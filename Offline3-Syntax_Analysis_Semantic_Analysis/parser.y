%code requires{
    #include <bits/stdc++.h>
}

%{
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
// #define PROMPT 1
#include "grammer_info.cpp"
using namespace std; 

extern int yylex(void);
extern FILE *yyin;


int yyparse(void);
int line_count;
int error_count;
FILE *fp,*fp2,*fp3,*fp1;
fstream logfile;
fstream errorfile;
symbol_table *symbolTable = new symbol_table(30);
bool zid_i_see_a_function_zaddy = 0;

void yyerror(char *s){
    printf("Error at Line %d: %s",line_count, s);
    return ;
}

#define writeLog(grammer,text) logfile<<"Line "<<line_count<<": "<<grammer<<"\n\n"<<text<<"\n"<<endl;

void writeError(string s){
    error_count++;
    errorfile<<"Error at Line "<<line_count<<": "<<s<<endl;
    logfile<<"Error at Line "<<line_count<<": "<<s<<endl;
}

%}


%union {
    symbol* symbolInfo;
    grammer_info* grammerInfo;
}

%token <symbolInfo> IF ELSE FOR DO INT FLOAT VOID SWITCH DEFAULT WHILE BREAK CHAR DOUBLE RETURN CASE CONTINUE 
%token <symbolInfo> LCURL RCURL LPAREN RPAREN LTHIRD RTHIRD COMMA SEMICOLON 
%token <symbolInfo> ADDOP MULOP INCOP DECOP RELOP ASSIGNOP LOGICOP NOT  
%token <symbolInfo> ID CONST_CHAR CONST_INT CONST_FLOAT PRINTLN MAIN 
%token LOWER_THAN_ELSE INT_ARRAY FLOAT_ARRAY UNKNOWN 

%type<grammerInfo> declaration_list type_specifier start program unit var_declaration func_declaration func_definition
%type<grammerInfo> parameter_list compound_statement statements statement expression expression_statement 
%type<grammerInfo> variable logic_expression rel_expression term factor simple_expression argument_list arguments 
%type<grammerInfo> unary_expression


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE 

// %destructor { delete $<symbolInfo>$; } <symbolInfo>
// %destructor { delete $<grammerInfo>$; } <grammerInfo>

%{
int getTypeValue(string &s){
    if( s == "int" )    return INT;
    else if( s == "float")  return FLOAT;
    else if( s == "void")   return VOID;
    else if( s == "int_array")  return INT_ARRAY;
    else if( s == "float_array")    return FLOAT_ARRAY;

    return UNKNOWN;
}
string getTypeString(int type){
    switch(type){
        case INT: return "int";
        case FLOAT: return "float";
        case VOID: return "void";
        case INT_ARRAY: return "int";
        case FLOAT_ARRAY: return "float";
        default : return "unknown";
    }
}
%}

%%
start:  program {
            writeLog("start: program","");
            symbolTable->print_all_scope_table() ;

            delete $1;
        }
	    ;
program: program unit {
            $$ = new grammer_info( string($1->text+"\n"+$2->text) );
            writeLog("program: program unit",$$->text);

            delete $1; delete $2;
        }
	    | unit {
            $$ = new grammer_info(string($1->text));
            writeLog("program: unit",$$->text);

            delete $1;
        }
        ;
	
unit:   var_declaration { 
            $$ = new grammer_info(string($1->text));
            delete $1;

            writeLog("unit: var_declaration",$$->text); 
        }
        |func_declaration {
            $$ = new grammer_info(string($1->text));
            delete $1;
            writeLog("unit: func_declaration",$$->text);
        }
        |func_definition {
            $$ = new grammer_info(string($1->text));
            delete $1;
            writeLog("unit: func_definition",$$->text);
        }
        ;
var_declaration: type_specifier declaration_list SEMICOLON {
                    $$ = new grammer_info(string($1->text + " " + $2->text + ";"));
                    for(int i=0;i<$2->ids.size();i++){
                        $2->ids[i].type = $1->text;
                        symbol* foundSymbol = symbolTable->lookup_current($2->ids[i].name ) ; 
                        if( foundSymbol == nullptr ){
                            foundSymbol = new symbol( $2->ids[i].name,$2->ids[i].type,$2->ids[i].array_size) ;
                            symbolTable->insert(foundSymbol);
                            delete foundSymbol;
                        }
                        else {
                            writeError("multiple declaration of "+$2->ids[i].name);
                        }
                    }
                    delete $1; delete $2; 

                    writeLog("var_declaration: type_specifier declaration_list SEMICOLON",$$->text);
                }
                ;
                  
type_specifier: INT {
                    $$ = new grammer_info(string("int"));
                    $$->text = "int";
                    $$->type = INT ; 

                    writeLog("type_specifier: INT",$$->text);
                }
                |FLOAT {
                    $$ = new grammer_info(string("float"));
                    $$->text = "float";
                    $$->type = FLOAT ; 

                    writeLog("type_specifier: FLOAT",$$->text);
                } 
                |VOID {
                    $$ = new grammer_info(string("void"));
                    $$->text = "void";
                    $$->type = VOID;

                    writeLog("type_specifier: VOID",$$->text);
                } 
                ;
declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
                    $$ = new grammer_info(string($1->text + "," + $3->getName() + "[" + $5->getName() + "]"));
                    $$->ids = $1->ids;
                    if( stoi($5->getName()) < 0 )
                        writeError("array size must be positive");    
                    $3->setArraySize(stoi($5->getName()));
                    $$->ids.push_back({$3->getName(),$3->getType(),$3->getArraySize()});
                    delete $1; delete $3; delete $5;

                    writeLog("declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD",$$->text);                
                }
                |declaration_list COMMA ID {
                    $$ = new grammer_info(string($1->text + "," + $3->getName()));
                    $$->ids = $1->ids;
                    $$->ids.push_back({$3->getName(),$3->getType(),$3->getArraySize()});
                    delete $1; delete $3; 

                    writeLog("declaration_list: declaration_list COMMA ID",$$->text);
                } 
                | ID LTHIRD CONST_INT RTHIRD {
                    $$ = new grammer_info(string($1->getName() + "[" + $3->getName() + "]"));
                    if( stoi($3->getName()) < 0 )
                        writeError("array size must be positive");
                    $1->setArraySize(stoi($3->getName()));
                    $$->ids.push_back({$1->getName(),$1->getType(),$1->getArraySize()});
                    delete $1; delete $3;

                    writeLog("declaration_list: ID LTHIRD CONST_INT RTHIRD",$$->text) ;
                }
                | ID {
                    $$ = new grammer_info(string($1->getName()));
                    $$->ids.push_back({$1->getName(),$1->getType(),$1->getArraySize()});
                    delete $1;  

                    writeLog("declaration_list: ID",$$->text);
                }
                ;
                
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
                    $$ = new grammer_info($1->text+" "+$2->getName()+"("+$4->text+");");
                    $2->setType($1->text);
                    for(int i=0;i<$4->ids.size();i++){
                        $2->getParams().push_back({$4->ids[i].name,$4->ids[i].type,$4->ids[i].array_size});
                    }
                    $2->markAsFunction();
                    symbolTable->insert($2);

                    delete $1; delete $4; delete $2;
                    
                    writeLog("func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",$$->text);
                } 
                | type_specifier ID LPAREN RPAREN SEMICOLON {
                    $$ = new grammer_info($1->text+" "+$2->getName()+"();");
                    $2->setType($1->text);
                    $2->markAsFunction();
                    symbolTable->insert($2);
                    
                    delete $1; delete $2;

                    writeLog("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",$$->text);  
                }
                ;
parameter_list: parameter_list COMMA type_specifier ID {
                    $$ = new grammer_info($1->text +"," + $3->text + " " + $4->getName());
                    $$->ids = $1->ids;
                    $4->setType($3->text);
                    $$->ids.push_back({$4->getName(),$4->getType(),$4->getArraySize()});
                    delete $1; delete $3; delete $4;

                    writeLog("parameter_list: parameter_list COMMA type_specifier ID",$$->text);
                }
                | parameter_list COMMA type_specifier {
                    $$ = new grammer_info($1->text +"," + $3->text);
                    $$->ids = $1->ids;
                    $1->ids.push_back({"_",$3->text,-1}); 
                    delete $1; delete $3; 

                    writeLog("parameter_list: parameter_list COMMA type_specifier",$$->text);
                }
                | type_specifier ID {
                    $$ = new grammer_info($1->text +" " + $2->getName());
                    $2->setType($1->text);
                    $$->ids.push_back({$2->getName(),$2->getType(),$2->getArraySize()});
                    delete $1; delete $2;
                    
                    writeLog("parameter_list: type_specifier ID",$$->text) ;
                }
                | type_specifier {
                    $$ = new grammer_info($1->text);
                    $$->ids.push_back({"_",$1->text,-1});
                    delete $1;

                    writeLog("parameter_list: type_specifier",$$->text) ;
                }
                ;

func_definition:  type_specifier ID LPAREN parameter_list RPAREN {
                        $2->setType($1->text);
                        for(int i=0;i<$4->ids.size();i++){
                            $2->getParams().push_back({$4->ids[i].name,$4->ids[i].type,$4->ids[i].array_size});
                        }
                        $2->markAsFunction();
                        symbol* foundSymbol = symbolTable->lookup($2->getName());
                        // if( foundSymbol != nullptr ){
                        //     writeError("multiple definition of function "+$2->to_string());
                        // }
                        
                        symbolTable->insert($2);
                        symbolTable->enter_scope();
                        zid_i_see_a_function_zaddy = 1;
                        for(int i=0;i<$4->ids.size();i++){
                            foundSymbol = symbolTable->lookup_current($4->ids[i].name);
                            if( foundSymbol == nullptr){
                                foundSymbol = new symbol($4->ids[i].name,$4->ids[i].type,$4->ids[i].array_size);
                                symbolTable->insert(foundSymbol);
                                delete foundSymbol;
                            }
                            else 
                                writeError("multiple parameters of same name");
                        }
                    } compound_statement {
                    $$ = new grammer_info($1->text+" "+$2->getName()+"("+$4->text+")"+$7->text); 
                    delete $1; delete $4; 
                    writeLog("func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement",$$->text) ;
                }
                | type_specifier ID LPAREN RPAREN {
                        $2->setType($1->text);
                        $2->markAsFunction();
                        symbol* foundSymbol = symbolTable->lookup($2->getName());
                        // if( foundSymbol != nullptr ){
                        //     writeError("multiple definition of function "+$2->to_string());
                        // }
                        symbolTable->insert($2);
                        symbolTable->enter_scope();
                        zid_i_see_a_function_zaddy = 1;
                    } compound_statement {
                    $$ = new grammer_info($1->text+" "+$2->getName()+"()"+$6->text); 
                    delete $1; delete $2;

                    writeLog("func_definition: type_specifier ID LPAREN RPAREN compound_statement",$$->text);
                }
                ;
compound_statement: LCURL {
                            if( !zid_i_see_a_function_zaddy )
                                symbolTable->enter_scope();
                            zid_i_see_a_function_zaddy = 0;
                        } statements RCURL {
                        $$ = new grammer_info("{\n"+$3->text+"\n}");

                        delete $3;

                        writeLog("compound_statement: LCURL statements RCURL",$$->text); 
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                    }
                    | LCURL {
                            if( !zid_i_see_a_function_zaddy )
                                symbolTable->enter_scope();
                            zid_i_see_a_function_zaddy = 0;
                        }
                        RCURL {
                        $$ = new grammer_info("{\n}");

                        writeLog("compound_statement: LCURL RCURL",$$->text);
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                    }
                    ;
statements: statements statement {
                $$ = new grammer_info($1->text+"\n"+$2->text);
                delete $1; delete $2;

                writeLog("statements: statements statement",$$->text);
            }
            |statement {
                $$ = new grammer_info($1->text);
                delete $1;

                writeLog("statements: statement",$$->text);
            }
            ;
statement:  var_declaration {
                $$ = new grammer_info($1->text);
                delete $1;

                writeLog("statement: var_declaration",$$->text);
            }
            |expression_statement {
                $$ = new grammer_info($1->text);
                delete $1;

                writeLog("statement: expression_statement",$$->text);
            }
            |compound_statement {
                $$ = new grammer_info($1->text);
                delete $1;

                writeLog("statement: compound_statement",$$->text);
            }
            |FOR LPAREN expression_statement expression_statement expression RPAREN statement {
                $$ = new grammer_info("for("+$3->text+$4->text+$5->text+")\n"+$7->text);
                delete $3; delete $4; delete $5; delete $7;
                
                writeLog("statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement",$$->text);  
            }
            |IF LPAREN expression RPAREN statement ELSE statement {
                $$ = new grammer_info("if("+$3->text+")\n"+$5->text+"\nelse\n"+$7->text);
                delete $3; delete $5; delete $7;   
                
                writeLog("statement: IF LPAREN expression RPAREN statement ELSE statement",$$->text);
            }
            |IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
                $$ = new grammer_info("if("+$3->text+")\n"+$5->text);
                delete $3; delete $5;

                writeLog("statement: IF LPAREN expression RPAREN statement",$$->text);
            }
            |WHILE LPAREN expression RPAREN statement {
                $$ = new grammer_info("while("+$3->text+")\n"+$5->text);
                delete $3; delete $5;

                writeLog("statement: WHILE LPAREN expression RPAREN statement",$$->text);
            }
            |PRINTLN LPAREN variable RPAREN SEMICOLON {
                $$ = new grammer_info("println("+$3->text+");");
                delete $3;

                writeLog("statement: PRINTLN LPAREN ID RPAREN SEMICOLON",$$->text);  
            }
            |RETURN expression SEMICOLON {
                $$ = new grammer_info("return "+$2->text+";");
                delete $2;

                writeLog("statement: RETURN expression SEMICOLON",$$->text);
            }
            ;

expression_statement: SEMICOLON {
                        $$ = new grammer_info(";");
                        writeLog("expression_statement: SEMICOLON",$$->text);
                    } 
                    | expression SEMICOLON {
                        $$ = new grammer_info($1->text+";");
                        delete $1;

                        writeLog("expression_statement: expression SEMICOLON",$$->text);
                    } 
                    ;
expression: logic_expression {
                $$ = new grammer_info($1->text);
                $$->type = $1->type;
                delete $1;

                writeLog("expression: logic_expression",$$->text);
            }
            | variable ASSIGNOP logic_expression {
                $$ = new grammer_info($1->text+"="+$3->text);
                if( $1->type != $3->type){
                    writeError("assignment operator, operand types do not match");
                    cout<<$1->type<<" "<<$3->type<<endl;
                }
                $$->type = $1->type;    // type conversion 
                delete $1; delete $2; delete $3;

                writeLog("expression: variable ASSIGNOP logic_expression",$$->text);
            }
            ;
variable:   ID {
                $$ = new grammer_info($1->getName());
                symbol* foundSymbol = symbolTable->lookup($1->getName());
                if( foundSymbol == nullptr ){
                    writeError("variable "+$1->to_string()+" not declared");
                }
                $$->type = (foundSymbol!=nullptr)?getTypeValue(foundSymbol->getType()):UNKNOWN;
                $$->array = (foundSymbol!=nullptr)?foundSymbol->isArray():0;
                delete $1;

                writeLog("variable: ID",$$->text);
            }
            | ID LTHIRD expression RTHIRD {
                $$ = new grammer_info($1->getName()+"["+$3->text+"]");
                symbol* foundSymbol = symbolTable->lookup($1->getName());
                if( foundSymbol == nullptr ){
                    writeError("variable "+$1->to_string()+" not declared");
                    $$->type = UNKNOWN;
                }
                else if( !foundSymbol->isArray() ) {
                    writeError("variable "+$1->to_string()+" not an array");
                    $$->type = UNKNOWN;
                }
                else  {
                    $$->type = getTypeValue(foundSymbol->getType());
                    $$->array = true; 
                }

                if( $3->type != INT ){
                    writeError("expression inside third brackets not an integer");
                }
                
                delete $1; delete $3;

                writeLog("variable: ID LTHIRD expression RTHIRD",$$->text);
            }
            ;
logic_expression:   rel_expression {
                        $$ = new grammer_info(*$1);
                        delete $1;

                        writeLog("logic_expression: rel_expression",$$->text);
                    } 	
		            | rel_expression LOGICOP rel_expression {
                        $$ = new grammer_info($1->text+" "+$2->getName()+" "+$3->text);
                        if( $1->type != INT || $3->type != INT )
                            writeError("operands of LOGICOP must be integers");    
                        $$->type = INT;
                        delete $1; delete $3;

                        writeLog("logic_expression: rel_expression LOGICOP rel_expression",$$->text);
                    }	
		            ;
rel_expression:     simple_expression {
                        $$ = new grammer_info(*$1);
                        delete $1;

                        writeLog("rel_expression: simple_expression",$$->text);
                    }                
		            | simple_expression RELOP simple_expression {
                        $$ = new grammer_info($1->text+$2->getName()+$3->text);
                        $$->type = INT;
                        delete $1; delete $3;

                        writeLog("rel_expression: simple_expression RELOP simple_expression",$$->text);
                    }	
		            ;
simple_expression:  term {
                        $$ = new grammer_info(*$1);
                        delete $1;

                        writeLog("simple_expression: term",$$->text);
                    } 
		            | simple_expression ADDOP term {
                        $$ = new grammer_info($1->text+$2->getName()+$3->text);
                        if( $1->type == FLOAT || $3->type == FLOAT )
                            $$->type = FLOAT ;
                        else $$->type = $1->type ;
                        delete $1; delete $3;

                        writeLog("simple_expression: simple_expression ADDOP term",$$->text);
                    } 
		            ;
term:   unary_expression {
            $$ = new grammer_info(*$1);
            delete $1;
            
            writeLog("term: unary_expression",$$->text);
        }
        |term MULOP unary_expression {
            $$ = new grammer_info($1->text+$2->getName()+$3->text);
            if( $2->getName() == "%" && ($1->type != INT || $3->type != INT) ){
                writeError("operands of modulo not integer");
            }
            if( $1->type == FLOAT || $3->type == FLOAT )
                $$->type = FLOAT ;
            else $$->type = $1->type ;
            delete $1; delete $3;

            writeLog("term: term MULOP unary_expression",$$->text); 
        }
        ;
unary_expression:   ADDOP unary_expression {
                        $$ = new grammer_info(*$2);
                        $$->text = string($1->getName()+$2->text);
                        delete $1;

                        writeLog("unary_expression: ADDOP unary_expression",$$->text);
                    }  
		            |NOT unary_expression {
                        $$ = new grammer_info($1->getName()+$2->text);
                        $$->type = INT;
                        delete $1; delete $2;

                        writeLog("unary_expression: NOT unary_expression",$$->text);
                    }
		            | factor {
                        $$ = new grammer_info(*$1);
                        delete $1;

                        writeLog("unary_expression: factor",$$->text);
                    } 
		            ;
	
factor: variable {
            $$ = new grammer_info(*$1);
            delete $1;

            writeLog("factor: variable",$$->text);
        } 
	    | ID LPAREN argument_list RPAREN {
            $$ = new grammer_info($1->getName()+"("+$3->text+")");
            symbol* foundSymbol = symbolTable->lookup($1->getName());
           
            bool ok = 0;
            if( foundSymbol == nullptr ){
                writeError("identifier "+$1->to_string()+" not declared.");
            }
            else if( !foundSymbol->isFunction() )
                writeError("identifier "+$1->to_string()+" is not a function.");
            else if( foundSymbol->getParams().size() != $3->ids.size() ){
                writeError("identifier "+$1->to_string()+" doesn't match with the definition, number of args.");
            }  

            else {
                int i ;
                for(i=0;i<foundSymbol->getParams().size();i++)
                    if( foundSymbol->getParams()[i].type != $3->ids[i].type || (foundSymbol->getParams()[i].array_size>0) != ($3->ids[i].array_size>0) ){
                        writeError("argument type doesn't match with definition");
                    }    
                if( i == foundSymbol->getParams().size() )
                    ok = 1;    
            }
            $$->type = (ok?getTypeValue(foundSymbol->getType()):UNKNOWN);
            delete $1; delete $3; 

            writeLog("factor: ID LPAREN argument_list RPAREN",$$->text);
        }
	    | LPAREN expression RPAREN {
            $$ = new grammer_info("("+$2->text+")");
            $$->type = $2->type;
            delete $2;

            writeLog("factor: LPAREN expression RPAREN",$$->text);
        }
	    | CONST_INT {
            $$ = new grammer_info($1->getName());
            $$->type = INT;
            delete $1;

            writeLog("factor: CONST_INT",$$->text);  
        } 
	    | CONST_FLOAT {
            $$ = new grammer_info($1->getName());
            $$->type = FLOAT ;
            delete $1;

            writeLog("factor: CONST_FLOAT",$$->text);
        }
	    | variable INCOP {
            $$ = new grammer_info($1->text+"++");
            $$->type = $1->type ;
            delete $1;

            writeLog("factor: variable INCOP",$$->text);
        } 
	    | variable DECOP {
            $$ = new grammer_info($1->text+"--");
            $$->type = $1->type ;
            delete $1;

            writeLog("factor: variable DECOP",$$->text);
        }
	    ;
	
argument_list:  arguments {
                    $$ = new grammer_info($1->text);
                    $$->ids = $1->ids;
                    delete $1;

                    writeLog("argument_list: arguments",$$->text);
                }
			    ;
	
arguments:  arguments COMMA logic_expression {
                $$ = new grammer_info($1->text+","+$3->text);
                $$->ids = $1->ids;
                $$->ids.push_back({"arg",getTypeString($3->type),$3->array?1:-1});
                delete $1; delete $3;

                writeLog("arguments: arguments COMMA logic_expression",$$->text);
            }
	        |logic_expression {
                $$ = new grammer_info($1->text);
                $$->ids.push_back({"argument",getTypeString($1->type),$1->array?1:-1});
                delete $1;
                
                writeLog("arguments: logic_expression",$$->text);
            }
	        ;
 
%%

int main(int argc, char **argv){
    // cout<<argv[1]<<endl;
    if( (fp=fopen(argv[1],"r")) == NULL){
        printf("Cannot Open Input File.\n");
        exit(1);
    }

    line_count = 1;
    error_count = 0;
    logfile = fstream("log.txt",ios_base::out);
    errorfile = fstream("error.txt",ios_base::out);
    cout.rdbuf(logfile.rdbuf());

    
    yyin = fp;

    yyparse();

    fclose(fp);
    // delete symbolTable;
    logfile.close();
    errorfile.close();
    return 0;
}
