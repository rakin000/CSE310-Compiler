%code requires{
    #include <bits/stdc++.h>
}

%{
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.cpp"
#include "grammer_info.cpp"
// #define PROMPT 1
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

void yyerror(char *s){
    printf("%s",s);
    return ;
}

#define writeLog(grammer,text) logfile<<"Line "<<line_count<<": "<<grammer<<"\n\n"<<text<<"\n"<<endl;

void writeError(string s ){
    errorfile<<"Line "<<line_count<<": "<<s<<endl;
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
%token LOWER_THAN_ELSE


%type<grammerInfo> declaration_list type_specifier start program unit var_declaration func_declaration func_definition
%type<grammerInfo> parameter_list compound_statement statements statement expression expression_statement 
%type<grammerInfo> variable logic_expression rel_expression term factor simple_expression argument_list arguments 
%type<grammerInfo> unary_expression


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE 


%%
start:  program {
            writeLog("start: program","");

            symbolTable->print_all_scope_table() ;
        }
	    ;
program: program unit {
            $$ = new grammer_info( string($1->text+"\n"+$2->text) );
            writeLog("program: program unit",$$->text);
        }
	    | unit {
            $$ = new grammer_info(string($1->text));
            writeLog("program: unit",$$->text);
        }
        ;
	
unit: var_declaration { 
            writeLog("unit: var_declaration",$$->text); 
        }
        | func_declaration {
            writeLog("unit: func_declaration",$$->text);
        }
        |func_definition {
            writeLog("unit: func_definition",$$->text);
        }
        ;
var_declaration: type_specifier declaration_list SEMICOLON {
                    $$ = new grammer_info(string($1->text + " " + $2->text + ";"));
                    writeLog("var_declaration: type_specifier declaration_list SEMICOLON",$$->text);
                }
                ;
                  
type_specifier: INT {
                    $$ = new grammer_info(string("int"));
                    writeLog("type_specifier: INT",$$->text);
                }
                |FLOAT {
                    $$ = new grammer_info(string("float"));
                    writeLog("type_specifier: FLOAT",$$->text);
                } 
                |VOID {
                    $$ = new grammer_info(string("void"));
                    writeLog("type_specifier: VOID",$$->text);
                } 
                ;
declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
                    $$ = new grammer_info(string($1->text + "," + $3->getName() + "[" + $5->getName() + "]"));
                    writeLog("declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD",$$->text);                
                }
                |declaration_list COMMA ID {
                    $$ = new grammer_info(string($1->text + "," + $3->getName()));
                    writeLog("declaration_list: declaration_list COMMA ID",$$->text);
                } 
                | ID LTHIRD CONST_INT RTHIRD {
                    $$ = new grammer_info(string($1->getName() + "[" + $3->getName() + "]"));
                    writeLog("declaration_list: ID LTHIRD CONST_INT RTHIRD",$$->text) ;
                }
                | ID {
                    $$ = new grammer_info(string($1->getName()));
                    writeLog("declaration_list: ID",$$->text);
                }
                ;
                
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
                    $$ = new grammer_info($1->text+" "+$2->getName()+"("+$4->text+");");
                    writeLog("func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",$$->text);
                } 
                | type_specifier ID LPAREN RPAREN SEMICOLON {
                    $$ = new grammer_info($1->text+" "+$2->getName()+"();");
                    writeLog("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",$$->text);  
                }
                ;
parameter_list: parameter_list COMMA type_specifier ID {
                    $$ = new grammer_info($1->text +"," + $3->text + " " + $4->getName());
                    writeLog("parameter_list: parameter_list COMMA type_specifier ID",$$->text);
                }
                | parameter_list COMMA type_specifier {
                    $$ = new grammer_info($1->text +"," + $3->text);
                    writeLog("parameter_list: parameter_list COMMA type_specifier",$$->text);
                }
                | type_specifier ID {
                    $$ = new grammer_info($1->text +" " + $2->getName());
                    writeLog("parameter_list: type_specifier ID",$$->text) ;
                }
                | type_specifier {
                    $$ = new grammer_info($1->text);
                    writeLog("parameter_list: type_specifier",$$->text) ;
                }
                ;

func_definition:  type_specifier ID LPAREN parameter_list RPAREN compound_statement {
                    $$ = new grammer_info($1->text+" "+$2->getName()+"("+$4->text+")"+$6->text); 
                    writeLog("func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement",$$->text) ;
                }
                | type_specifier ID LPAREN RPAREN compound_statement {
                    $$ = new grammer_info($1->text+" "+$2->getName()+"()"+$5->text); 
                    writeLog("func_definition: type_specifier ID LPAREN RPAREN compound_statement",$$->text);
                }
                ;
compound_statement: LCURL statements RCURL {
                        $$ = new grammer_info("{\n"+$2->text+"\n}");
                        writeLog("compound_statement: LCURL statements RCURL",$$->text); 
                    }
                    | LCURL RCURL {
                        $$ = new grammer_info("{\n}");
                        writeLog("compound_statement: LCURL RCURL",$$->text);
                    }
                    ;
statements: statements statement {
                $$ = new grammer_info($1->text+"\n"+$2->text);
                writeLog("statements: statements statement",$$->text);
            }
            |statement {
                $$ = new grammer_info($1->text);
                writeLog("statements: statement",$$->text);
            }
            ;
statement:  var_declaration {
                $$ = new grammer_info($1->text);
                writeLog("statement: var_declaration",$$->text);
            }
            |expression_statement {
                $$ = new grammer_info($1->text);
                writeLog("statement: expression_statement",$$->text);
            }
            |compound_statement {
                $$ = new grammer_info($1->text);
                writeLog("statement: compound_statement",$$->text);
            }
            |FOR LPAREN expression_statement expression_statement expression_statement RPAREN statement {
                $$ = new grammer_info("for("+$3->text+$4->text+$5->text+")\n"+$7->text);
                writeLog("statement: FOR LPAREN expression_statement expression_statement expression_statement RPAREN statement",$$->text);  
            }
            |IF LPAREN expression RPAREN statement ELSE statement {
                $$ = new grammer_info("if("+$3->text+")\n"+$5->text+"\nelse\n"+$7->text);
                writeLog("statement: IF LPAREN expression RPAREN statement ELSE statement",$$->text);
            }
            |IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
                $$ = new grammer_info("if("+$3->text+")\n"+$5->text);
                writeLog("statement: IF LPAREN expression RPAREN statement",$$->text);
            }
            |WHILE LPAREN expression RPAREN statement {
                $$ = new grammer_info("while("+$3->text+")\n"+$5->text);
                writeLog("statement: WHILE LPAREN expression RPAREN statement",$$->text);
            }
            |PRINTLN LPAREN ID RPAREN SEMICOLON {
                $$ = new grammer_info("println("+$3->getName()+");");
                writeLog("statement: PRINTLN LPAREN ID RPAREN SEMICOLON",$$->text);  
            }
            |RETURN expression SEMICOLON {
                $$ = new grammer_info("return "+$2->text+";");
                writeLog("statement: RETURN expression SEMICOLON",$$->text);
            }
            ;

expression_statement: SEMICOLON {
                        $$ = new grammer_info(";");
                        writeLog("expression_statement: SEMICOLON",$$->text);
                    } 
                    | expression SEMICOLON {
                        $$ = new grammer_info($1->text+";");
                        writeLog("expression_statement: expression SEMICOLON",$$->text);
                    } 
                    ;
expression: logic_expression {
                $$ = new grammer_info($1->text);
                writeLog("expression: logic_expression",$$->text);
            }
            | variable ASSIGNOP logic_expression {
                $$ = new grammer_info($1->text+"="+$3->text);
                writeLog("expression: variable ASSIGNOP logic_expression",$$->text);
            }
            ;
variable:   ID {
                $$ = new grammer_info($1->getName());
                writeLog("variable: ID",$$->text);
            }
            | ID LTHIRD expression RTHIRD {
                $$ = new grammer_info($1->getName()+"["+$3->text+"]");
                writeLog("variable: ID LTHIRD expression RTHIRD",$$->text);
            }
            ;
logic_expression:   rel_expression {
                        $$ = new grammer_info($1->text);
                        writeLog("logic_expression: rel_expression",$$->text);
                    } 	
		            | rel_expression LOGICOP rel_expression {
                        $$ = new grammer_info($1->text+" "+$2->getName()+" "+$3->text);
                        writeLog("logic_expression: rel_expression LOGICOP rel_expression",$$->text);
                    }	
		            ;
rel_expression:     simple_expression {
                        $$ = new grammer_info($1->text);
                        writeLog("rel_expression: simple_expression",$$->text);
                    }                
		            | simple_expression RELOP simple_expression {
                        $$ = new grammer_info($1->text+$2->getName()+$3->text);
                        writeLog("rel_expression: simple_expression RELOP simple_expression",$$->text);
                    }	
		            ;
simple_expression:  term {
                        $$ = new grammer_info($1->text);
                        writeLog("simple_expression: term",$$->text);
                    } 
		            | simple_expression ADDOP term {
                        $$ = new grammer_info($1->text+$2->getName()+$3->text);
                        writeLog("simple_expression: simple_expression ADDOP term",$$->text);
                    } 
		            ;
term:   unary_expression {
            $$ = new grammer_info($1->text);
            writeLog("term: unary_expression",$$->text);
        }
        |term MULOP unary_expression {
            $$ = new grammer_info($1->text+$2->getName()+$3->text);
           writeLog("term: term MULOP unary_expression",$$->text); 
        }
        ;
unary_expression:   ADDOP unary_expression {
                        $$ = new grammer_info($1->getName()+$2->text);
                        writeLog("unary_expression: ADDOP unary_expression",$$->text);
                    }  
		            |NOT unary_expression {
                        $$ = new grammer_info($1->getName()+$2->text);
                        writeLog("unary_expression: NOT unary_expression",$$->text);
                    }
		            | factor {
                        $$ = new grammer_info($1->text);
                        writeLog("unary_expression: factor",$$->text);
                    } 
		            ;
	
factor: variable {
            $$ = new grammer_info($1->text);
            writeLog("factor: variable",$$->text);
        } 
	    | ID LPAREN argument_list RPAREN {
            $$ = new grammer_info($1->getName()+"("+$3->text+")");
            writeLog("factor: ID LPAREN argument_list RPAREN",$$->text);
        }
	    | LPAREN expression RPAREN {
            $$ = new grammer_info("("+$2->text+")");
            writeLog("factor: LPAREN expression RPAREN",$$->text);
        }
	    | CONST_INT {
            $$ = new grammer_info($1->getName());
            writeLog("factor: CONST_INT",$$->text);  
        } 
	    | CONST_FLOAT {
            $$ = new grammer_info($1->getName());
            writeLog("factor: CONST_FLOAT",$$->text);
        }
	    | variable INCOP {
            $$ = new grammer_info($1->text+"++");
            writeLog("factor: variable INCOP",$$->text);
        } 
	    | variable DECOP {
            $$ = new grammer_info($1->text+"--");
            writeLog("factor: variable DECOP",$$->text);
        }
	    ;
	
argument_list:  arguments {
                    $$ = new grammer_info($1->text);
                    writeLog("argument_list: arguments",$$->text);
                }
			    ;
	
arguments:  arguments COMMA logic_expression {
                $$ = new grammer_info($1->text+","+$3->text);
                writeLog("arguments: arguments COMMA logic_expression",$$->text);
            }
	        | logic_expression {
                $$ = new grammer_info($1->text);
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
    logfile.close();
    errorfile.close();
    return 0;
}
