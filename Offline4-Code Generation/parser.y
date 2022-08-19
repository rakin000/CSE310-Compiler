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
int tab_count;
FILE *fp,*fp2,*fp3,*fp1;
fstream logfile;
fstream errorfile;
fstream codefile ;
symbol_table *symbolTable = new symbol_table(HASH_TABLE_SIZE);
bool inFunction = 0;
int offset_bp = 0;
symbol *currentFunction = nullptr, *dummySymbol = new symbol("dummy","dummy");
stack<symbol*> activeFunctions;
scope_table *declaredFunctions = new scope_table(HASH_TABLE_SIZE);


int label_count = 0 ;
string newLabel(){
    return "L"+to_string(label_count++);
}
string Lif,Lelse,Lendif;
string pendingCode = "" ;

vector<string> temp ; 
int temp_count = 0;
string newTemp() {
    string t = "tmp"+to_string(temp_count);
    if( temp_count == temp.size() ) {
        temp.push_back(t) ;
        temp_count++;
    }
    return temp[temp_count];
}
void removeTemp() {
    temp_count--;
    temp_count = max(0,temp_count) ;
}

void yyerror(const char *s){
    error_count++;
    cout<<"Error at Line "<<line_count<<": "<<s<<endl;
    errorfile<<"Error at Line "<<line_count<<": "<<s<<endl;
    // yyerrok;
    return ;
}

#define writeLog(grammer,text) logfile<<"Line "<<line_count<<": "<<grammer<<"\n\n"<<text<<"\n"<<endl;
#define comment(text) codefile<<"; Line "<<line_count<<": "<<text; 

void writeCode(string s,string c=""){
    for(int i=0;i<tab_count;i++)
        codefile <<"\t" ;
    codefile<<s;
    if( c!="" ) comment(c) ;
    codefile<<"\n" ;
}
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
%type<grammerInfo> ifprefix

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE 


%define parse.error verbose

/* %destructor { free($<symbolInfo>$); } <symbolInfo>  */
/* %destructor { free($<grammerInfo>$); } <grammerInfo> */

%%
start:  program {
            writeLog("start: program","");
            symbolTable->print_all_scope_table() ;

            free($1);
            YYACCEPT;
        }
	    ;
program: program unit {
            $$ = new grammer_info("program: program unit",string($1->text+"\n"+$2->text) );
            writeLog($$->name,$$->text);

            free($1); free($2);
        }
	    | unit {
            $$ = new grammer_info(string($1->text));
            writeLog("program: unit",$$->text);

            free($1);
        }
        ;
	
unit:   var_declaration { 
            $$ = new grammer_info(string($1->text));
            free($1);

            writeLog("unit: var_declaration",$$->text); 
        }
        |func_declaration {
            $$ = new grammer_info(string($1->text));
            free($1);
            writeLog("unit: func_declaration",$$->text);
        }
        |func_definition {
            $$ = new grammer_info(string($1->text));
            free($1);
            writeLog("unit: func_definition",$$->text);
        }
        ;
var_declaration: type_specifier declaration_list SEMICOLON {
                    $$ = new grammer_info(string($1->text + " " + $2->text + ";"));
                    if( $1->type == _void_ )
                        writeError("variable type cannot be void");

                    int dec_cnt= 0;
                    for(int i=0;i<$2->ids.size();i++){
                        $2->ids[i].type = $1->text;
                        symbol* foundSymbol = symbolTable->lookup_current($2->ids[i].name ) ; 
                        if( foundSymbol == nullptr ){
                            offset_bp -= 2;
                            dec_cnt++;
                            foundSymbol = new symbol( $2->ids[i].name,
                                                    $2->ids[i].type, 
                                                    // (symbolTable->current_scope()->get_id() == "1") ? $2->ids[i].name: string("[BP +")+to_string(offset_bp)+string("]"),
                                                    (symbolTable->current_scope()->get_id() == "1") ? $2->ids[i].name: to_string(offset_bp),
                                                    $2->ids[i].array_size) ;
                            symbolTable->insert(foundSymbol);
                            if( $2->ids[i].array_size != -1 ){
                                offset_bp -= 2*($2->ids[i].array_size-1) ;
                                dec_cnt += $2->ids[i].array_size-1;
                            }

                            // code 
                            if( symbolTable->current_scope()->get_id() == "1" ){
                                // codefile << $2->ids[i].name << " DW " << "?\n";
                                writeCode($2->ids[i].name+" DW "+"?");
                            } 
                            else {
                                // writeCode("PUSH 0\n");
                            }
                            // end code ;

                            delete foundSymbol ;
                        }
                        else {
                            writeError("multiple declaration of "+$2->ids[i].name);
                        }
                    }
                    //code 
                    if( symbolTable->current_scope()->get_id() != "1" ) 
                        writeCode("ADD SP, "+to_string(dec_cnt*-2));
                    //end 


                    free($1); free($2); 
                    writeLog("var_declaration: type_specifier declaration_list SEMICOLON",$$->text);
                }
                | type_specifier error SEMICOLON {
                    // yyerror("syntax error");
                    yyerrok;
                    $$ = new grammer_info(string($1->text + " ;"));
                    if( $1->type == _void_ )
                        writeError("variable type cannot be void");
    
                    

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
                    free($1); free($3); free($5);

                    writeLog($$->name,$$->text);                
                }
                |declaration_list COMMA ID {
                    $$ = new grammer_info("declaration_list: declaration_list COMMA ID",string($1->text + "," + $3->getName()));
                    $$->ids = $1->ids;
                    $$->ids.push_back({$3->getName(),$3->getType(),$3->getArraySize()});
                    free($1); free($3); 

                    writeLog($$->name,$$->text);
                } 
                | ID LTHIRD CONST_INT RTHIRD {
                    $$ = new grammer_info("declaration_list: ID LTHIRD CONST_INT RTHIRD",string($1->getName() + "[" + $3->getName() + "]"));
                    if( stoi($3->getName()) < 0 )
                        writeError("array size must be positive");
                    $1->setArraySize(stoi($3->getName()));
                    $$->ids.push_back({$1->getName(),$1->getType(),$1->getArraySize()});
                    free($1); free($3);

                    writeLog($$->name,$$->text) ;
                }
                | ID {
                    $$ = new grammer_info("declaration_list: ID",string($1->getName()));
                    $$->ids.push_back({$1->getName(),$1->getType(),$1->getArraySize()}); // default array_size = -1;
                    free($1);  

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

                    free($1); free($4); free($2);
                    
                    writeLog($$->name,$$->text);
                } 
                | type_specifier ID LPAREN RPAREN SEMICOLON {
                    $$ = new grammer_info("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",$1->text+" "+$2->getName()+"();");
                    $2->setType($1->text);
                    $2->markAsFunction();
                    declaredFunctions->insert($2);
                    
                    free($1); free($2);

                    writeLog($$->name,$$->text);  
                }
                | type_specifier ID LPAREN error RPAREN SEMICOLON {
                    // yyerror("syntax error, function declaration");
                    yyerrok;
                    $$ = new grammer_info("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",$1->text+" "+$2->getName()+"();");
                    $2->setType($1->text);
                    $2->markAsFunction();
                    declaredFunctions->insert($2);
                    
                    // delete $1; delete $2;

                    writeLog($$->name,$$->text);  
                }
                ;
parameter_list: parameter_list COMMA type_specifier ID {
                    $$ = new grammer_info("parameter_list: parameter_list COMMA type_specifier ID",$1->text +"," + $3->text + " " + $4->getName());
                    $$->ids = $1->ids;
                    $4->setType($3->text);
                    $$->ids.push_back({$4->getName(),$4->getType(),$4->getArraySize()});
                    free($1); free($3); free($4);

                    writeLog($$->name,$$->text);
                }
                | parameter_list COMMA type_specifier {
                    $$ = new grammer_info("parameter_list: parameter_list COMMA type_specifier",$1->text +"," + $3->text);
                    $$->ids = $1->ids;
                    $1->ids.push_back({"_",$3->text,-1}); 
                    free($1); free($3); 

                    writeLog($$->name,$$->text);
                }
                | type_specifier ID {
                    $$ = new grammer_info("parameter_list: type_specifier ID",$1->text +" " + $2->getName());
                    $2->setType($1->text);
                    $$->ids.push_back({$2->getName(),$2->getType(),$2->getArraySize()});
                    free($1); free($2);
                    
                    writeLog($$->name,$$->text) ;
                }
                | type_specifier {
                    $$ = new grammer_info($1->text);
                    $$->ids.push_back({"_",$1->text,-1});
                    free($1);

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
                        inFunction = 1;

                        //code 
                        // codefile << $2->getName() << " PROC: \n" ;
                        writeCode($2->getName() +" PROC");
                        tab_count++;
                        if( $2->getName() == "main" ){
                            writeCode("MOV AX, @DATA");
                            writeCode("MOV DS, AX","load data to DS");
                        }
                        writeCode("MOV BP, SP","save SP") ;
                        // end code 
                        offset_bp = 0;
                        
                        for(int i=0;i<$4->ids.size();i++){
                            foundSymbol = symbolTable->lookup_current($4->ids[i].name);
                            if( foundSymbol == nullptr){
                                // foundSymbol = new symbol($4->ids[i].name,$4->ids[i].type,string("[BP +")+to_string(offset_bp)+string("]"),$4->ids[i].array_size);
                                foundSymbol = new symbol($4->ids[i].name,$4->ids[i].type,to_string(offset_bp),$4->ids[i].array_size);
                                symbolTable->insert(foundSymbol);
                                offset_bp += 2;

                                free(foundSymbol);
                            }
                            else 
                                writeError("multiple parameters of same name");
                        }
                        offset_bp = 0 ;

                    } compound_statement {
                    $$ = new grammer_info("func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement",$1->text+" "+$2->getName()+"("+$4->text+")"+$7->text); 

                    // code 
                    if( $2->getName() == "main"){
                        writeCode("MOV AH, 4CH") ;
                        writeCode("INT 21H") ;
                    }
                    --tab_count;
                    writeCode($2->getName()+" ENDP") ;               
                    //end code 

                    offset_bp = 0;
                    free($1); free($4); 
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
                        inFunction = 1;

                        //code 
                        writeCode($2->getName()+" PROC");
                        tab_count++;
                        if( $2->getName() == "main" ){
                            writeCode("MOV AX, @DATA");
                            writeCode("MOV DS, AX","load data to DS");
                        }
                        writeCode("MOV BP, SP","save SP") ;
                        // end code 

                        offset_bp = 0;
                    } compound_statement {
                    $$ = new grammer_info("func_definition: type_specifier ID LPAREN RPAREN compound_statement",$1->text+" "+$2->getName()+"()"+$6->text); 
                    
                    // code 
                    if( $2->getName() == "main"){
                        writeCode("MOV AH, 4CH") ;
                        writeCode("INT 21H") ;
                    }
                    --tab_count;
                    writeCode($2->getName()+" ENDP") ;               
                    //end code 
                    
                    offset_bp = 0; 
                    free($1); free($2);
                    writeLog($$->name,$$->text);
                }
                | type_specifier ID LPAREN error RPAREN compound_statement {
                    // yyerror("syntax error, function definition");
                    yyerrok;
                    $$ = new grammer_info("func_definition: type_specifier ID LPAREN RPAREN compound_statement",$1->text+" "+$2->getName()+"()"+$6->text); 
                    // delete $1; delete $2;

                    writeLog($$->name,$$->text);

                }
                ;
compound_statement: LCURL {
                            if( !inFunction ){
                                symbolTable->enter_scope();
                                currentFunction = dummySymbol ;
                                activeFunctions.push(currentFunction);
                            }
                            inFunction = 0;
                            offset_bp = 0 ;
                        } statements RCURL {
                        $$ = new grammer_info("compound_statement: LCURL statements RCURL","{\n"+$3->text+"\n}");

                        free($3);

                        writeLog($$->name,$$->text); 
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                        activeFunctions.pop();
                        currentFunction = activeFunctions.top();
                    }
                    | LCURL {
                            if( !inFunction ){
                                symbolTable->enter_scope();
                                currentFunction = dummySymbol ;
                                activeFunctions.push(currentFunction);
                            }
                            inFunction = 0;
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
                free($1); free($2);

                writeLog($$->name,$$->text);
            }
            |statement {
                $$ = new grammer_info("statements: statement",$1->text);
                free($1);

                writeLog($$->name,$$->text);
            }
            ;
ifprefix : IF LPAREN expression RPAREN { 
                    // Lif = newLabel();
                    Lelse = newLabel();
                    Lendif = newLabel();
                    //code
                    writeCode("POP AX");
                    writeCode("CMP AX,0");
                    writeCode("JE "+Lelse) ;
                    // write
                    //end
                } statement {
                    $$ = new grammer_info("statement: IF LPAREN expression RPAREN statement ELSE statement","if("+$3->text+")\n"+$6->text+"\n");
                
                    delete $3;
                }
            ;
statement:  var_declaration {
                $$ = new grammer_info("statement: var_declaration",$1->text);
                free($1);

                writeLog($$->name,$$->text);
            }
            |expression_statement {
                $$ = new grammer_info("statement: expression_statement",$1->text);
                free($1);

                writeLog($$->name,$$->text);
            }
            |compound_statement {
                $$ = new grammer_info("statement: compound_statement",$1->text);
                free($1);

                writeLog($$->name,$$->text);
            }
            |FOR LPAREN expression_statement expression_statement expression RPAREN statement {
                $$ = new grammer_info("statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement","for("+$3->text+$4->text+$5->text+")\n"+$7->text);
                free($3); free($4); free($5); free($7);
                
                writeLog($$->name,$$->text);  
            }
            |ifprefix ELSE {
                    //code 
                    writeCode("JMP "+Lendif) ;
                    writeCode(Lelse+":");
                    //end 
                } statement {
                $$ = new grammer_info("statement: IF LPAREN expression RPAREN statement ELSE statement",$1->text+"else\n"+$4->text);
                
                //code 
                writeCode(Lendif+":");
                //

                free($1); free($4); // free($9);   
                writeLog($$->name,$$->text);
            }
            |ifprefix %prec LOWER_THAN_ELSE {
                $$ = new grammer_info("statement: IF LPAREN expression RPAREN statement",$1->text);
                
                //code
                writeCode(Lelse+":"); 
                //end 

                free($1); //free($6);
                writeLog($$->name,$$->text);
            }
            |WHILE LPAREN expression RPAREN statement {
                $$ = new grammer_info("statement: WHILE LPAREN expression RPAREN statement","while("+$3->text+")\n"+$5->text);
                free($3); free($5);

                writeLog($$->name,$$->text);
            }
            |PRINTLN LPAREN variable RPAREN SEMICOLON {
                $$ = new grammer_info("statement: PRINTLN LPAREN ID RPAREN SEMICOLON","printf("+$3->text+");");


                //code
                writeCode("MOV AX, ["+$3->value+"]");
                writeCode("CALL PRINT") ; 
                //end 

                free($3);

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
                free($2);

                writeLog($$->name,$$->text);
            }
            | error SEMICOLON {
                // yyerror("syntax error, invalid statement");

                yyerrok;
                $$ = new grammer_info("statement: error");
                writeLog($$->name,$$->text);
            }
            ;

expression_statement: SEMICOLON {
                        $$ = new grammer_info("expression_statement: SEMICOLON",";");
                        writeLog($$->name,$$->text);

                    } 
                    | expression SEMICOLON {
                        $$ = new grammer_info("expression_statement: expression SEMICOLON",$1->text+";");
                        
                        //code 
                        writeCode("POP AX");
                        //end 
                        free($1);

                        writeLog($$->name,$$->text);
                    } 
                    ;
expression: logic_expression {
                $$ = new grammer_info("expression: logic_expression",$1->text);
                $$->type = $1->type;
                free($1);

                //code
                // writeCode("POP AX\n");
                //end 
                writeLog($$->name,$$->text);
            }
            | variable {
                //code 
                if( $1->array == true ){
                    writeCode("PUSH SI","saving the address SI") ;
                }
                //
            } ASSIGNOP logic_expression {
                $$ = new grammer_info("expression: variable ASSIGNOP logic_expression",$1->text+"="+$4->text);
                if( $1->type != $4->type ){
                    if( ($1->type == _int_ && $4->type == _float_) || ($1->type==_float_&& $4->type==_int_) ){
                        $$->type = $1->type; // type conversion 
                    }
                    else {
                        writeError($3->getName()+" operator ,"+"type mismatch "+$1->type+$3->getName()+$4->type);
                        $$->type = _unknown_;
                    }
                }
                //code
                // writeCode("MOV AX, [SP]\n");
                writeCode("POP AX");
                if($1->array == true )
                    writeCode("POP SI","retrieving the address SI"); 
                writeCode("MOV ["+$1->value+"], AX"); 
                writeCode("PUSH AX");
                //end 

                free($1); free($4); free($3);
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

                if( foundSymbol != nullptr ){
                    // writeCode("MOV DX, "+foundSymbol->getValue()+"\n");
                    // comment("load variable: "+foundSymbol->getName()) ;
                    $$->value = "BP+"+foundSymbol->getValue();
                    $$->array = false ;
                }

                free($1);

                writeLog("variable: ID",$$->text);
            }
            | ID LTHIRD expression RTHIRD {
                $$ = new grammer_info("variable: ID LTHIRD expression RTHIRD",$1->getName()+"["+$3->text+"]");
                symbol* foundSymbol = symbolTable->lookup($1->getName());

                bool ok = 0;
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
                    ok = 1; 
                }

                if( $3->type != _int_ ){
                    writeError("expression inside third brackets not an integer");
                    ok = 0;
                }
                
                //code 
                if( ok ){
                    writeCode("POP SI");
                    writeCode("SHL SI, 1");
                    writeCode("NEG SI");
                    writeCode("ADD SI, "+foundSymbol->getValue());
                    // writeCode("ADD BX, BP");
                    // writeCode()
                    $$->value = "BP+SI";
                }
                //end 
                free($1); free($3);
                writeLog($$->name,$$->text);
            }
            ;
logic_expression:   rel_expression {
                        $$ = new grammer_info(*$1);
                        $$->name = "logic_expression: rel_expression";
                        
                        //code 
                        //end 

                        free($1);
                        writeLog($$->name,$$->text);
                    } 	
		            | rel_expression LOGICOP rel_expression {
                        $$ = new grammer_info("logic_expression: rel_expression LOGICOP rel_expression",$1->text+" "+$2->getName()+" "+$3->text);
                        if( $1->type != _int_ || $3->type != _int_ )
                            writeError("operands of LOGICOP must be integers");    
                        $$->type = _int_;

                        //code
                        writeCode("POP BX");
                        writeCode("POP AX"); 
                        if( $2->getName() == "&&" ){
                            string L1 = newLabel(), L2 = newLabel() ;
                            writeCode("CMP AX, 0");
                            writeCode("JE "+L1);
                            writeCode("CMP BX, 0");
                            writeCode("JE "+L1);
                            writeCode("PUSH 1");
                            writeCode("JMP "+L2);
                            writeCode(L1+":");
                            writeCode("PUSH 0");
                            writeCode(L2+":");
                        } 
                        else if( $2->getName() == "||") {
                             string L1 = newLabel(), L2 = newLabel() ;
                            writeCode("CMP AX, 0");
                            writeCode("JNE "+L1);
                            writeCode("CMP BX, 0");
                            writeCode("JNE "+L1);
                            writeCode("PUSH 0");
                            writeCode("JMP "+L2);
                            writeCode(L1+":");
                            writeCode("PUSH 1sn");
                            writeCode(L2+":");
                        }
                        //end  

                        free($1); free($3);
                        writeLog($$->name,$$->text); }	
		            ;
rel_expression:     simple_expression {
                        $$ = new grammer_info(*$1);
                        $$->name = "rel_expression: simple_expression";

                        //code 
                        //end 

                        free($1);
                        writeLog($$->name,$$->text);
                    }                
		            | simple_expression RELOP simple_expression {
                        $$ = new grammer_info("rel_expression: simple_expression RELOP simple_expression",$1->text+$2->getName()+$3->text);
                        $$->type = _int_;
                        $$->value = $2->getName();
                        // code
                        writeCode("POP BX");
                        writeCode("POP AX") ;
                        writeCode("CMP AX,BX");
                        string L1 = newLabel(), L2= newLabel() ;
                        
                        if( $2->getName() == ">" ){
                            writeCode("JG "+L1);
                        }
                        else if($2->getName() == ">=" ){
                            writeCode("JGE "+L1);
                        }
                        else if( $2->getName() == "<") {
                            writeCode("JL "+L1);
                        }
                        else if( $2->getName() == "<=") {
                            writeCode("JLE "+L1);
                        }
                        else if( $2->getName() == "==") {
                            writeCode("JE "+L1);
                        }
                        else if( $2->getName() == "!=") {
                            writeCode("JNE "+L1);
                        }
                        writeCode("PUSH 0");
                        writeCode("JMP "+L2);
                        writeCode(L1+":");
                        writeCode("PUSH 1") ;
                        writeCode(L2+":");
                        // end 

                        free($1); free($3);
                        writeLog($$->name,$$->text);
                    }	
		            ;
simple_expression:  term {
                        $$ = new grammer_info(*$1);
                        $$->name = "simple_expression: term"; 
                       
                        //code  
                        //end 

                        free($1);
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

                        //code
                        writeCode("POP AX");
                        writeCode("POP BX"); 
                        if( $2->getName() == "+") {
                            writeCode("ADD BX, AX");
                        }
                        else writeCode("SUB BX, AX");
                        writeCode("PUSH BX") ;
                        //end 

                        free($1); free($3);

                        writeLog($$->name,$$->text);
                    } 
		            ;
term:   unary_expression {
            $$ = new grammer_info(*$1);
            $$->name = "term: unary_expression";
            free($1);
            // code 
            writeCode("PUSH CX");
            //end
            
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

            //code 
            writeCode("POP AX") ;
            if( $2->getName() == "*"){
                writeCode("MUL CX");
                writeCode("PUSH AX");
            }
            else if( $2->getName() == "/"){
                writeCode("DIV CX");
                writeCode("PUSH AX");
            }
            else if( $2->getName()=="%") {
                writeCode("DIV CX") ;
                writeCode("PUSH DX") ;
            }
            //end 

            free($1); free($3);

            writeLog($$->name,$$->text); 
        }
        ;
unary_expression:   ADDOP unary_expression {
                        $$ = new grammer_info(*$2);
                        $$->text = string($1->getName()+$2->text);
                        $$->name = "unary_expression: ADDOP unary_expression";
                        
                        //code 
                        if($1->getName() == "-") 
                            writeCode("NEG CX");
                        //end code ;
                        
                        free($1);

                        writeLog($$->name,$$->text);
                    }  
		            |NOT unary_expression {
                        $$ = new grammer_info("unary_expression: NOT unary_expression",$1->getName()+$2->text);
                        $$->type = _int_;
                        //code 
                        writeCode("NOT CX");
                        writeCode("AND CX, 1");
                        //end code ;
                        
                        
                        free($1); free($2);
                        writeLog($$->name,$$->text);
                    }
		            | factor {
                        $$ = new grammer_info(*$1);
                        $$->name = "unary_expression: factor"; 
                        
                        
                        free($1);
                        writeLog($$->name,$$->text);
                    } 
		            ;
	
factor: variable {
            $$ = new grammer_info(*$1);
            $$->name = "factor: variable"; 
            
            // code 
            writeCode("MOV CX,["+$1->value+"]");
            // end code 
            
            free($1);

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
            
            //code 
            if( ok ) {
                // writeCode("CALL "+found)
            }
            //endcode 
            
            free($1); free($3); 

            writeLog($$->name,$$->text);
        }
	    | LPAREN expression RPAREN {
            $$ = new grammer_info("factor: LPAREN expression RPAREN","("+$2->text+")");
            $$->type = $2->type;
            
            //code 
            writeCode("POP CX");
            //
            
            free($2);

            writeLog($$->name,$$->text);
        }
	    | CONST_INT {
            $$ = new grammer_info("factor: CONST_INT",$1->getName());
            $$->type = _int_;

            //code 
            writeCode("MOV CX, "+$1->getName()) ;
            // end code ;
            free($1);

            writeLog($$->name,$$->text);  
        } 
	    | CONST_FLOAT {
            $$ = new grammer_info("factor: CONST_FLOAT",$1->getName());
            $$->type = _float_;
            free($1);

            writeLog($$->name,$$->text);
        }
	    | variable INCOP {
            $$ = new grammer_info("factor: variable INCOP",$1->text+"++");
            $$->type = $1->type ;
            
            //code 
            writeCode("MOV CX,["+$1->value+"]");
            //end 
            
            free($1);
            writeLog($$->name,$$->text);
        } 
	    | variable DECOP {
            $$ = new grammer_info("factor: variable DECOP",$1->text+"--");
            $$->type = $1->type ;
            
            //code 
            writeCode("MOV CX,["+$1->value+"]");
            //end 
            
            
            free($1);
            writeLog($$->name,$$->text);
        }
	    ;
	
argument_list:  arguments {
                    $$ = new grammer_info("argument_list: arguments",$1->text);
                    $$->ids = $1->ids;
                    free($1);

                    writeLog($$->name,$$->text);
                }
			    ;
	
arguments:  arguments COMMA logic_expression {
                $$ = new grammer_info("arguments: arguments COMMA logic_expression",$1->text+","+$3->text);
                $$->ids = $1->ids;
                $$->ids.push_back({"arg",$3->type,$3->array?1:-1});
                free($1); free($3);

                writeLog($$->name,$$->text);
            }
	        |logic_expression {
                $$ = new grammer_info("arguments: logic_expression",$1->text);
                $$->ids.push_back({"argument",$1->type,$1->array?1:-1});
                free($1);
                
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
    codefile = fstream("code.asm", ios_base::out);

    codefile << "\.MODEL SMALL\n\.STACK 400H\n\.DATA\n" ;
    codefile<<"NUM_STR DB \'000000$\'\n";
    codefile <<"\.CODE\nCALL main\n" ;
    

    cout.rdbuf(logfile.rdbuf());

    activeFunctions.push(dummySymbol);
    
    yyin = fp;

    yyparse();
    
    codefile <<"PRINT PROC\n"
    "\tMOV BX, 8000H\n"
    "\tAND BX, AX\n"
    "\tCMP BX, 0\n"
    "\tJZ NOT_NEG\n"
    "\n"
    "\tMOV BX, AX\n"
    "\tMOV DL, 2DH\n"
    "\tMOV AH, 2\n"
    "\tINT 21H\n"
    "\tMOV AX, BX\n"
    "\tNEG AX\n"
    "\n"
    "\tNOT_NEG:\n"
    "\tLEA SI, NUM_STR\n"
    "\tADD SI, 6\n"
    "\t\n"
    "\tPRINT_LOOP:\n"
    "\tDEC SI\n"
    "\tMOV DX, 0\n"
    "\tMOV CX, 10\n"
    "\tDIV CX\n"
    "\tADD DL, \'0\'\n"
    "\tMOV [SI], DL\n"
    "\n"
    "\tCMP AX, 0\n"
    "\tJNE PRINT_LOOP\n"
    "\tMOV DX, SI \n"
    "\tMOV AH, 9\n"
    "\tINT 21H\n"
    "\n"
    "\tMOV DL, 0AH\n"
    "\tMOV AH, 2\n"
    "\tINT 21H\n"
    "\tMOV DL, 0DH\n"
    "\tINT 21H\n"
    "\tRET\n"
    "PRINT ENDP\n";
    fclose(fp);
    // delete symbolTable;
    free(symbolTable);
    free(dummySymbol) ;
    free(declaredFunctions);
    logfile.close();
    errorfile.close();
    codefile.close();
    return 0;
}
