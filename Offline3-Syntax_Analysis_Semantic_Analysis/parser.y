%code requires{
    #include <bits/stdc++.h>
}

%{
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.cpp"
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

void writeLog(string s){
    logfile<<"Line "<<line_count<<": "<<s<<endl;
}
void writeError(string s ){
    errorfile<<"Line "<<line_count<<": "<<s<<endl;
}
%}

%token  IF ELSE FOR DO INT FLOAT VOID SWITCH DEFAULT WHILE BREAK CHAR DOUBLE RETURN CASE CONTINUE 
        LCURL 
        RCURL 
        LPAREN 
        RPAREN 
        LTHIRD
        RTHIRD 
        COMMA 
        SEMICOLON 
        
        ADDOP 
        MULOP 
        INCOP 
        DECOP
        RELOP 
        ASSIGNOP 
        LOGICOP 
        NOT 

        ID 
        CONST_CHAR 
        CONST_INT 
        CONST_FLOAT 

        PRINTLN
        MAIN

        LOWER_THAN_ELSE

%union {
    symbol* symbolInfo;
}

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE 

%%
start:  program {
            writeLog("program");
        }
	    ;
program: program unit {
            writeLog("program unit");
        }
	    | unit {
            writeLog("unit");
        }
        ;
	
unit:   var_declaration { 
            writeLog("var_declaration"); 
        }
        | func_declaration {
            writeLog("func_declaration");
        }
        |func_definition {
            writeLog("func_definition");
        }
        ;
var_declaration: type_specifier declaration_list SEMICOLON {
                    writeLog("type_specifier declaration_list SEMICOLON");
                }
                ;
                  
type_specifier: INT {
                    writeLog("INT");
                }
                |FLOAT {
                    writeLog("FLOAT");
                } 
                |VOID {
                    writeLog("VOID");
                } 
                ;
declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
                    writeLog("declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
                }
                |declaration_list COMMA ID {
                    writeLog("declaration_list COMMA ID");
                } 
                | ID LTHIRD CONST_INT RTHIRD {
                    writeLog("ID LTHIRD CONST_INT RTHIRD") ;
                }
                | ID {
                    writeLog("ID");
                }
                ;
                
func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON {
                    writeLog("type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                } 
                | type_specifier ID LPAREN RPAREN SEMICOLON {
                   writeLog("type_specifier ID LPAREN RPAREN SEMICOLON");  
                }
                ;
parameter_list: parameter_list COMMA type_specifier ID {
                    writeLog("parameter_list COMMA type_specifier ID");
                }
                | parameter_list COMMA type_specifier {
                    writeLog("parameter_list COMMA type_specifier");
                }
                | type_specifier ID {
                    writeLog("type_specifier ID") ;
                }
                | type_specifier {
                    writeLog("type_specifier") ;
                }
                ;

func_definition:  type_specifier ID LPAREN parameter_list RPAREN compound_statement {
                    writeLog("type_specifier ID LPAREN parameter_list RPAREN compound_statement") ;
                }
                | type_specifier ID LPAREN RPAREN compound_statement {
                    writeLog("type_specifier ID LPAREN RPAREN compound_statement");
                }
                ;
compound_statement: LCURL statements RCURL {
                        writeLog("LCURL statements RCURL"); 
                    }
                    | LCURL RCURL {
                        writeLog("LCURL RCURL");
                    }
                    ;
statements: statements statement {
                writeLog("statements statement");
            }
            |statement {
                writeLog("statement");
            }
            ;
statement:  var_declaration {
                writeLog("var_declaration");
            }
            |expression_statement {
                writeLog("expression_statement");
            }
            |compound_statement {
                writeLog("compound_statement");
            }
            |FOR LPAREN expression_statement expression_statement expression_statement RPAREN statement {
               writeLog("FOR LPAREN expression_statement expression_statement expression_statement RPAREN statement");  
            }
            |IF LPAREN expression RPAREN statement ELSE statement {
                writeLog("IF LPAREN expression RPAREN statement ELSE statement");
            }
            |IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
                writeLog("IF LPAREN expression RPAREN statement");
            }
            |WHILE LPAREN expression RPAREN statement {
                writeLog("WHILE LPAREN expression RPAREN statement");
            }
            |PRINTLN LPAREN ID RPAREN SEMICOLON {
                writeLog("PRINTLN LPAREN ID RPAREN SEMICOLON");  
            }
            |RETURN expression SEMICOLON {
                writeLog("RETURN expression SEMICOLON");
            }
            ;

expression_statement: SEMICOLON {
                        writeLog("SEMICOLON");
                    } 
                    | expression SEMICOLON {
                        writeLog("expression SEMICOLON");
                    } 
                    ;
expression: logic_expression {
                writeLog("logic_expression");
            }
            | variable ASSIGNOP logic_expression {
                writeLog("variable ASSIGNOP logic_expression");
            }
            ;
variable:   ID {
                writeLog("ID");
            }
            | ID LTHIRD expression RTHIRD {
                writeLog("ID LTHIRd expression RTHIRD");
            }
            ;
logic_expression:   rel_expression {
                        writeLog("rel_expression");
                    } 	
		            | rel_expression LOGICOP rel_expression {
                        writeLog("rel_expression LOGICOP rel_expression");
                    }	
		            ;
rel_expression:     simple_expression {
                        writeLog("simple_expression");
                    }                
		            | simple_expression RELOP simple_expression {
                        writeLog("simple_expression RELOP simple_expression");
                    }	
		            ;
simple_expression:  term {
                        writeLog("term");
                    } 
		            | simple_expression ADDOP term {
                        writeLog("simple_expression ADDOP term");
                    } 
		            ;
term:   unary_expression {
            writeLog("unary_expression");
        }
        |term MULOP unary_expression {
           writeLog("term MULOP unary_expression"); 
        }
        ;
unary_expression:   ADDOP unary_expression {
                        writeLog("ADDOP unary_expression");
                    }  
		            |NOT unary_expression {
                        writeLog("NOT unary_expression");
                    }
		            | factor {
                        writeLog("factor");
                    } 
		            ;
	
factor: variable {
            writeLog("variable");
        } 
	    | ID LPAREN argument_list RPAREN {
            writeLog("ID LPAREN argument_list RPAREN");
        }
	    | LPAREN expression RPAREN {
            writeLog("LPAREN expression RPAREN");
        }
	    | CONST_INT {
            writeLog("CONST_INT");  
        } 
	    | CONST_FLOAT {
            writeLog("CONST_FLOAT");
        }
	    | variable INCOP {
            writeLog("variable INCOP");
        } 
	    | variable DECOP {
            writeLog("variable DECOP");
        }
	    ;
	
argument_list:  arguments {
                    writeLog("arguments");
                }
			    ;
	
arguments:  arguments COMMA logic_expression {
                writeLog("arguments COMMA logic_expression");
            }
	        | logic_expression {
                writeLog("logic_expression");
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
    
    yyin = fp;

    yyparse();

    fclose(fp);
    logfile.close();
    errorfile.close();
    return 0;
}
