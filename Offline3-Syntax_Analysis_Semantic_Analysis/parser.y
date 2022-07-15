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

#define HASH_TABLE_SIZE 30
#define _int_ "int"
#define _float_ "float"
#define _void_ "void"
#define _unknown_ "unknown"

extern int yylex(void);
extern FILE *yyin;


int yyparse(void);
int line_count;
int error_count;
FILE *fp,*fp2,*fp3,*fp1;
fstream logfile;
fstream errorfile;
symbol_table *symbolTable = new symbol_table(HASH_TABLE_SIZE);
bool zid_i_see_a_function_zaddy = 0;
symbol *currentFunction = nullptr, *dummySymbol = new symbol("dummy","dummy");
stack<symbol*> activeFunctions;
scope_table *declaredFunctions = new scope_table(HASH_TABLE_SIZE);


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
%token <symbolInfo> ID CONST_CHAR CONST_INT CONST_FLOAT PRINTF MAIN 
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
            $$ = new grammer_info("program: program unit",string($1->text+"\n"+$2->text) );
            writeLog($$->name,$$->text);

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
                    if( $1->type == _void_ )
                        writeError("variable type cannot be void");
                        
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
                    $$->type = _int_ ; 

                    writeLog("type_specifier: INT",$$->text);
                }
                |FLOAT {
                    $$ = new grammer_info(string("float"));
                    $$->text = "float";
                    $$->type = _float_; 

                    writeLog("type_specifier: FLOAT",$$->text);
                } 
                |VOID {
                    $$ = new grammer_info(string("void"));
                    $$->text = "void";
                    $$->type = _void_ ;

                    writeLog("type_specifier: VOID",$$->text);
                } 
                ;
declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
                    $$ = new grammer_info("declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD",string($1->text + "," + $3->getName() + "[" + $5->getName() + "]"));
                    $$->ids = $1->ids;
                    if( stoi($5->getName()) < 0 )
                        writeError("array size must be positive");    
                    $3->setArraySize(stoi($5->getName()));
                    $$->ids.push_back({$3->getName(),$3->getType(),$3->getArraySize()});
                    delete $1; delete $3; delete $5;

                    writeLog($$->name,$$->text);                
                }
                |declaration_list COMMA ID {
                    $$ = new grammer_info("declaration_list: declaration_list COMMA ID",string($1->text + "," + $3->getName()));
                    $$->ids = $1->ids;
                    $$->ids.push_back({$3->getName(),$3->getType(),$3->getArraySize()});
                    delete $1; delete $3; 

                    writeLog($$->name,$$->text);
                } 
                | ID LTHIRD CONST_INT RTHIRD {
                    $$ = new grammer_info("declaration_list: ID LTHIRD CONST_INT RTHIRD",string($1->getName() + "[" + $3->getName() + "]"));
                    if( stoi($3->getName()) < 0 )
                        writeError("array size must be positive");
                    $1->setArraySize(stoi($3->getName()));
                    $$->ids.push_back({$1->getName(),$1->getType(),$1->getArraySize()});
                    delete $1; delete $3;

                    writeLog($$->name,$$->text) ;
                }
                | ID {
                    $$ = new grammer_info("declaration_list: ID",string($1->getName()));
                    $$->ids.push_back({$1->getName(),$1->getType(),$1->getArraySize()}); // default array_size = -1;
                    delete $1;  

                    writeLog($$->name,$$->text);
                }
                ;
                
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
                    $$ = new grammer_info("func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",$1->text+" "+$2->getName()+"("+$4->text+");");
                    $2->setType($1->text);
                    for(int i=0;i<$4->ids.size();i++){
                        $2->getParams().push_back({$4->ids[i].name,$4->ids[i].type,$4->ids[i].array_size});
                    }
                    $2->markAsFunction();
                    declaredFunctions->insert($2);

                    delete $1; delete $4; delete $2;
                    
                    writeLog($$->name,$$->text);
                } 
                | type_specifier ID LPAREN RPAREN SEMICOLON {
                    $$ = new grammer_info("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",$1->text+" "+$2->getName()+"();");
                    $2->setType($1->text);
                    $2->markAsFunction();
                    declaredFunctions->insert($2);
                    
                    delete $1; delete $2;

                    writeLog($$->name,$$->text);  
                }
                ;
parameter_list: parameter_list COMMA type_specifier ID {
                    $$ = new grammer_info("parameter_list: parameter_list COMMA type_specifier ID",$1->text +"," + $3->text + " " + $4->getName());
                    $$->ids = $1->ids;
                    $4->setType($3->text);
                    $$->ids.push_back({$4->getName(),$4->getType(),$4->getArraySize()});
                    delete $1; delete $3; delete $4;

                    writeLog($$->name,$$->text);
                }
                | parameter_list COMMA type_specifier {
                    $$ = new grammer_info("parameter_list: parameter_list COMMA type_specifier",$1->text +"," + $3->text);
                    $$->ids = $1->ids;
                    $1->ids.push_back({"_",$3->text,-1}); 
                    delete $1; delete $3; 

                    writeLog($$->name,$$->text);
                }
                | type_specifier ID {
                    $$ = new grammer_info("parameter_list: type_specifier ID",$1->text +" " + $2->getName());
                    $2->setType($1->text);
                    $$->ids.push_back({$2->getName(),$2->getType(),$2->getArraySize()});
                    delete $1; delete $2;
                    
                    writeLog($$->name,$$->text) ;
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
                        if( foundSymbol != nullptr ){
                            writeError("multiple definition of function "+$2->to_string());
                        }
                        foundSymbol = declaredFunctions->lookup($2->getName());
                        if( foundSymbol != nullptr ){
                            if( foundSymbol->getType() != $2->getType())
                                writeError($2->to_string()+", return type doesn't match with function declaration "+foundSymbol->to_string() ) ;
                            if( foundSymbol->getParams().size() != $2->getParams().size() )
                                writeError($2->to_string()+", number of parameters don't match with function declaration "+foundSymbol->to_string() );
                            else {
                                for(int i=0;i<foundSymbol->getParams().size();i++){
                                    if( foundSymbol->getParams()[i].type != $2->getParams()[i].type )
                                        writeError($2->to_string()+" parameters don't match with function declaration "+foundSymbol->to_string());
                                }
                            }
                        } 
                        symbolTable->insert($2);
                        symbolTable->enter_scope();
                        currentFunction = symbolTable->lookup($2->getName());
                        activeFunctions.push(currentFunction);
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
                    $$ = new grammer_info("func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement",$1->text+" "+$2->getName()+"("+$4->text+")"+$7->text); 
                    delete $1; delete $4; 
                    writeLog($$->name,$$->text) ;
                }
                | type_specifier ID LPAREN RPAREN {
                        $2->setType($1->text);
                        $2->markAsFunction();
                        symbol* foundSymbol = symbolTable->lookup($2->getName());
                        if( foundSymbol != nullptr ){
                            writeError("multiple definition of function "+$2->to_string());
                        }
                        foundSymbol = declaredFunctions->lookup($2->getName());
                        if( foundSymbol != nullptr ){
                            if( foundSymbol->getType() != $2->getType())
                                writeError($2->to_string()+", return type doesn't match with function declaration "+foundSymbol->to_string() ) ;
                            if( foundSymbol->getParams().size() != $2->getParams().size() )
                                writeError($2->to_string()+", number of parameters don't match with function declaration "+foundSymbol->to_string() );
                            else {
                                for(int i=0;i<foundSymbol->getParams().size();i++){
                                    if( foundSymbol->getParams()[i].type != $2->getParams()[i].type )
                                        writeError($2->to_string()+" parameters don't match with function declaration "+foundSymbol->to_string());
                                }
                            }
                        } 
                        symbolTable->insert($2);
                        symbolTable->enter_scope();
                        currentFunction = symbolTable->lookup($2->getName());
                        activeFunctions.push(currentFunction);
                        zid_i_see_a_function_zaddy = 1;

                    } compound_statement {
                    $$ = new grammer_info("func_definition: type_specifier ID LPAREN RPAREN compound_statement",$1->text+" "+$2->getName()+"()"+$6->text); 
                    delete $1; delete $2;

                    writeLog($$->name,$$->text);
                }
                ;
compound_statement: LCURL {
                            if( !zid_i_see_a_function_zaddy ){
                                symbolTable->enter_scope();
                                currentFunction = dummySymbol ;
                                activeFunctions.push(currentFunction);
                            }
                            zid_i_see_a_function_zaddy = 0;
                        } statements RCURL {
                        $$ = new grammer_info("compound_statement: LCURL statements RCURL","{\n"+$3->text+"\n}");

                        delete $3;

                        writeLog($$->name,$$->text); 
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                        activeFunctions.pop();
                        currentFunction = activeFunctions.top();
                    }
                    | LCURL {
                            if( !zid_i_see_a_function_zaddy ){
                                symbolTable->enter_scope();
                                currentFunction = dummySymbol ;
                                activeFunctions.push(currentFunction);
                            }
                            zid_i_see_a_function_zaddy = 0;
                        }
                        RCURL {
                        $$ = new grammer_info("compound_statement: LCURL RCURL","{\n}");

                        writeLog($$->name,$$->text);
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                        activeFunctions.pop();
                        currentFunction = activeFunctions.top();
                    }
                    ;
statements: statements statement {
                $$ = new grammer_info("statements: statements statement",$1->text+"\n"+$2->text);
                delete $1; delete $2;

                writeLog($$->name,$$->text);
            }
            |statement {
                $$ = new grammer_info("statements: statement",$1->text);
                delete $1;

                writeLog($$->name,$$->text);
            }
            ;
statement:  var_declaration {
                $$ = new grammer_info("statement: var_declaration",$1->text);
                delete $1;

                writeLog($$->name,$$->text);
            }
            |expression_statement {
                $$ = new grammer_info("statement: expression_statement",$1->text);
                delete $1;

                writeLog($$->name,$$->text);
            }
            |compound_statement {
                $$ = new grammer_info("statement: compound_statement",$1->text);
                delete $1;

                writeLog($$->name,$$->text);
            }
            |FOR LPAREN expression_statement expression_statement expression RPAREN statement {
                $$ = new grammer_info("statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement","for("+$3->text+$4->text+$5->text+")\n"+$7->text);
                delete $3; delete $4; delete $5; delete $7;
                
                writeLog($$->name,$$->text);  
            }
            |IF LPAREN expression RPAREN statement ELSE statement {
                $$ = new grammer_info("statement: IF LPAREN expression RPAREN statement ELSE statement","if("+$3->text+")\n"+$5->text+"\nelse\n"+$7->text);
                delete $3; delete $5; delete $7;   
                
                writeLog($$->name,$$->text);
            }
            |IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
                $$ = new grammer_info("statement: IF LPAREN expression RPAREN statement","if("+$3->text+")\n"+$5->text);
                delete $3; delete $5;

                writeLog($$->name,$$->text);
            }
            |WHILE LPAREN expression RPAREN statement {
                $$ = new grammer_info("statement: WHILE LPAREN expression RPAREN statement","while("+$3->text+")\n"+$5->text);
                delete $3; delete $5;

                writeLog($$->name,$$->text);
            }
            |PRINTF LPAREN variable RPAREN SEMICOLON {
                $$ = new grammer_info("statement: PRINTLN LPAREN ID RPAREN SEMICOLON","printf("+$3->text+");");
                delete $3;

                writeLog($$->name,$$->text);  
            }
            |RETURN expression SEMICOLON {
                $$ = new grammer_info("statement: RETURN expression SEMICOLON","return "+$2->text+";");
                if( currentFunction == nullptr )
                    writeError("return statement without any function");
                else if( currentFunction->getType() != $2->type ){
                    if( (currentFunction->getType() == _int_ && $2->type == _float_) || (currentFunction->getType() ==_float_&& $2->type==_int_) ){
                    }
                    else {
                        writeError("return expression type donot match with function definition , defined "+currentFunction->getType()+" ,returned "+$2->type);
                    }
                    
                }
                delete $2;

                writeLog($$->name,$$->text);
            }
            ;

expression_statement: SEMICOLON {
                        $$ = new grammer_info("expression_statement: SEMICOLON",";");
                        writeLog($$->name,$$->text);
                    } 
                    | expression SEMICOLON {
                        $$ = new grammer_info("expression_statement: expression SEMICOLON",$1->text+";");
                        delete $1;

                        writeLog($$->name,$$->text);
                    } 
                    ;
expression: logic_expression {
                $$ = new grammer_info("expression: logic_expression",$1->text);
                $$->type = $1->type;
                delete $1;

                writeLog($$->name,$$->text);
            }
            | variable ASSIGNOP logic_expression {
                $$ = new grammer_info("expression: variable ASSIGNOP logic_expression",$1->text+"="+$3->text);
                if( $1->type != $3->type ){
                    if( ($1->type == _int_ && $3->type == _float_) || ($1->type==_float_&&$3->type==_int_) ){
                        $$->type = $1->type; // type conversion 
                    }
                    else {
                        writeError($2->getName()+" operator ,"+"type mismatch "+$1->type+$2->getName()+$3->type);
                        $$->type = _unknown_;
                    }
                }
                delete $1; delete $2; delete $3;

                writeLog($$->name,$$->text);
            }
            ;
variable:   ID {
                $$ = new grammer_info($1->getName());
                symbol* foundSymbol = symbolTable->lookup($1->getName());
                if( foundSymbol == nullptr ){
                    writeError("variable "+$1->to_string()+" not declared");
                    $$->type = _unknown_;
                }
                else {
                    $$->type = foundSymbol->isArray()?_unknown_:foundSymbol->getType();
                }
                delete $1;

                writeLog("variable: ID",$$->text);
            }
            | ID LTHIRD expression RTHIRD {
                $$ = new grammer_info("variable: ID LTHIRD expression RTHIRD",$1->getName()+"["+$3->text+"]");
                symbol* foundSymbol = symbolTable->lookup($1->getName());
                if( foundSymbol == nullptr ){
                    writeError("variable "+$1->to_string()+" not declared");
                    $$->type = _unknown_;
                }
                else if( !foundSymbol->isArray() ) {
                    writeError("variable "+$1->to_string()+" not an array");
                    $$->type = _unknown_;
                }
                else  {
                    $$->type = foundSymbol->getType();
                    $$->array = true; 
                }

                if( $3->type != _int_ ){
                    writeError("expression inside third brackets not an integer");
                }
                
                delete $1; delete $3;

                writeLog($$->name,$$->text);
            }
            ;
logic_expression:   rel_expression {
                        $$ = new grammer_info(*$1);
                        $$->name = "logic_expression: rel_expression";
                        delete $1;

                        writeLog($$->name,$$->text);
                    } 	
		            | rel_expression LOGICOP rel_expression {
                        $$ = new grammer_info("logic_expression: rel_expression LOGICOP rel_expression",$1->text+" "+$2->getName()+" "+$3->text);
                        if( $1->type != _int_ || $3->type != _int_ )
                            writeError("operands of LOGICOP must be integers");    
                        $$->type = _int_;
                        delete $1; delete $3;

                        writeLog($$->name,$$->text);
                    }	
		            ;
rel_expression:     simple_expression {
                        $$ = new grammer_info(*$1);
                        $$->name = "rel_expression: simple_expression";
                        delete $1;

                        writeLog($$->name,$$->text);
                    }                
		            | simple_expression RELOP simple_expression {
                        $$ = new grammer_info("rel_expression: simple_expression RELOP simple_expression",$1->text+$2->getName()+$3->text);
                        $$->type = _int_;
                        delete $1; delete $3;

                        writeLog($$->name,$$->text);
                    }	
		            ;
simple_expression:  term {
                        $$ = new grammer_info(*$1);
                        $$->name = "simple_expression: term"; 
                        delete $1;

                        writeLog($$->name,$$->text);
                    } 
		            | simple_expression ADDOP term {
                        $$ = new grammer_info("simple_expression: simple_expression ADDOP term",$1->text+$2->getName()+$3->text);
                        if( $1->type != $3->type ){
                            if( ($1->type == _int_ && $3->type == _float_) || ($1->type==_float_&&$3->type==_int_) ){
                                $$->type = _float_;
                            }
                            else {
                                writeError($2->getName()+" operator ,"+"type mismatch "+$1->type+$2->getName()+$3->type);
                                $$->type = _unknown_;
                            }
                        }
                        else $$->type=$1->type ;

                        delete $1; delete $3;

                        writeLog($$->name,$$->text);
                    } 
		            ;
term:   unary_expression {
            $$ = new grammer_info(*$1);
            $$->name = "term: unary_expression";
            delete $1;
            
            writeLog($$->name,$$->text);
        }
        |term MULOP unary_expression {
            $$ = new grammer_info("term: term MULOP unary_expression",$1->text+$2->getName()+$3->text);
            if( $2->getName() == "%" ){
                if($1->type != _int_ || $3->type != _int_ )  
                    writeError("operands of modulo not integer");
                // modulo 0 error ?? 
            }
            if( $1->type != $3->type ){
                if( ($1->type == _int_ && $3->type == _float_) || ($1->type==_float_&&$3->type==_int_) ){
                    $$->type = _float_;
                }
                else {
                    writeError($2->getName()+" operator ,"+"type mismatch "+$1->type+$2->getName()+$3->type);
                    $$->type = _unknown_;
                }
            }
            else $$->type = $1->type ;

            delete $1; delete $3;

            writeLog($$->name,$$->text); 
        }
        ;
unary_expression:   ADDOP unary_expression {
                        $$ = new grammer_info(*$2);
                        $$->text = string($1->getName()+$2->text);
                        $$->name = "unary_expression: ADDOP unary_expression";
                        delete $1;

                        writeLog($$->name,$$->text);
                    }  
		            |NOT unary_expression {
                        $$ = new grammer_info("unary_expression: NOT unary_expression",$1->getName()+$2->text);
                        $$->type = _int_;
                        delete $1; delete $2;

                        writeLog($$->name,$$->text);
                    }
		            | factor {
                        $$ = new grammer_info(*$1);
                        $$->name = "unary_expression: factor"; 
                        delete $1;

                        writeLog($$->name,$$->text);
                    } 
		            ;
	
factor: variable {
            $$ = new grammer_info(*$1);
            $$->name = "factor: variable"; 
            delete $1;

            writeLog($$->name,$$->text);
        } 
	    | ID LPAREN argument_list RPAREN {
            $$ = new grammer_info("factor: ID LPAREN argument_list RPAREN",$1->getName()+"("+$3->text+")");
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
                    if( foundSymbol->getParams()[i].type != $3->ids[i].type){ //(foundSymbol->getParams()[i].array_size>0) != ($3->ids[i].array_size>0) 
                        writeError( to_string(i+1)+"th argument type doesn't match with definition, defined "+foundSymbol->getParams()[i].type+", called by "+$3->ids[i].type);
                    }    
                if( i == foundSymbol->getParams().size() )
                    ok = 1;    
            }
            $$->type = ok?foundSymbol->getType():_unknown_;
            delete $1; delete $3; 

            writeLog($$->name,$$->text);
        }
	    | LPAREN expression RPAREN {
            $$ = new grammer_info("factor: LPAREN expression RPAREN","("+$2->text+")");
            $$->type = $2->type;
            delete $2;

            writeLog($$->name,$$->text);
        }
	    | CONST_INT {
            $$ = new grammer_info("factor: CONST_INT",$1->getName());
            $$->type = _int_;
            delete $1;

            writeLog($$->name,$$->text);  
        } 
	    | CONST_FLOAT {
            $$ = new grammer_info("factor: CONST_FLOAT",$1->getName());
            $$->type = _float_;
            delete $1;

            writeLog($$->name,$$->text);
        }
	    | variable INCOP {
            $$ = new grammer_info("factor: variable INCOP",$1->text+"++");
            $$->type = $1->type ;
            delete $1;

            writeLog($$->name,$$->text);
        } 
	    | variable DECOP {
            $$ = new grammer_info("factor: variable DECOP",$1->text+"--");
            $$->type = $1->type ;
            delete $1;

            writeLog($$->name,$$->text);
        }
	    ;
	
argument_list:  arguments {
                    $$ = new grammer_info("argument_list: arguments",$1->text);
                    $$->ids = $1->ids;
                    delete $1;

                    writeLog($$->name,$$->text);
                }
			    ;
	
arguments:  arguments COMMA logic_expression {
                $$ = new grammer_info("arguments: arguments COMMA logic_expression",$1->text+","+$3->text);
                $$->ids = $1->ids;
                $$->ids.push_back({"arg",$3->type,$3->array?1:-1});
                delete $1; delete $3;

                writeLog($$->name,$$->text);
            }
	        |logic_expression {
                $$ = new grammer_info("arguments: logic_expression",$1->text);
                $$->ids.push_back({"argument",$1->type,$1->array?1:-1});
                delete $1;
                
                writeLog($$->name,$$->text);
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

    activeFunctions.push(dummySymbol);
    
    yyin = fp;

    yyparse();

    fclose(fp);
    // delete symbolTable;
    logfile.close();
    errorfile.close();
    return 0;
}
