%{
#include <bits/stdc++.h>

#include "symbol_table.cpp"
#define YYSTYPE symbol*;

using namespace std; 

int yyparse(void);
int yylex(void);
extern FILE *yyin;

SymbolTable *table;

void yyerror(char *s){
    printerr("%s",s);
    return ;
}
%}

%token  IF 
        ELSE 
        FOR
        DO 
        INT 
        FLOAT 
        VOID 
        SWITCH 
        DEFAULT 
        WHILE 
        BREAK 
        CHAR 
        DOUBLE 
        RETURN 
        CASE 
        CONTINUE 

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
        RELOP 
        ASSIGNOP 
        LOGICOP 
        NOT 

        ID 
        CONST_CHAR 
        CONST_INT 
        CONST_FLOAT 

%% 
start : program 
    ;
program : unit 
    | unit program  
    ;
unit :  var_declaration 
    |   func_declaration
    |   func_definition 
    ;

var_declaration : INT int_declaration_list SEMICOLON  
                | FLOAT float_declaration_list SEMICOLON
                | DOUBLE float_declaration_list SEMICOLON
                | CHAR char_declaration_list SEMICOLON
                ;
int_declaration_list :  int_declaration 
                        | int_declaration COMMA int_declaration_list 
                        ;
int_declaration :   ID
                    | ID ASSIGNOP CONST_INT 
                    | ID LTHIRD CONST_INT RTHIRD 
                    | ID LTHIRD RTHIRD 
                    ;
float_declaration_list : float_declaration 
                        | float_declaration COMMA float_declaration_list 
                        ;
float_declaration : ID 
                    | ID ASSIGNOP CONST_FLOAT
                    | ID LTHIRD CONST_INT RTHIRD 
                    | ID LTHIRD RTHIRD 
                    ;
char_declaration_list : char_declaration 
                        | char_declaration COMMA char_declaration_list
                        ;
char_declaration :  ID 
                    | ID ASSIGNOP CONST_CHAR 
                    | ID LTHIRD CONST_INT RTHIRD 
                    | ID LTHIRD RTHIRD 
                    ;
                    
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON 
    | type_specifier ID LPAREN RPAREN SEMICOLON
    ;
func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement 
    | type_specifier ID LPAREN RPAREN compound_statement
    ;
type_specifier : INT 
                | FLOAT 
                | VOID 
                | CHAR
                | DOUBLE 
                ;
parameter_list : parameter_list1 
                | parameter_list2
                ;
parameter_list1 : type_specifier ID 
                | type_specifier ID COMMA parameter_list
                ;    
parameter_list2 : type_specifier 
                | type_specifier COMMA parameter_list2 
                ;
statements: statement
            | statement statements
            
statement:  var_declaration
            | expression_statement      // expr
            | compound_statement    // compound statement 
            | FOR LPAREN expression_statement expression_statement expression RPAREN statement // for/while/do statement 
            | WHILE LPAREN expression RPAREN statement 
            | DO statement WHILE LPAREN expression RPAREN SEMICOLON 
            | IF LPAREN expression RPAREN statement   //if statement 
            | IF LPAREN expression RPAREN statement ELSE statement  
            | PRINTLN LPAREN ID RPAREN SEMICOLON 
            | RETURN expression SEMICOLON 
            ; // assignment
            // function call
expression_statement:   SEMICOLON 
                        |expression SEMICOLON
                        ;
expresssion :   


%%

int main(int argc, char *argv){
    if( fp=fopen(argv[1],"r")) == NULL){
        printf("Cannot Open Input File.\n");
        exit(1);
    }

    fp2 = fopen(argv[2],"w");
    fclose(fp2);
    fp3 = fopen(argv[3],"w");
    fclose(fp3);

    fp2 = fopen(argv[2],"a");
    fp3 = fopen(argv[3],"a");

    yyin = fp;
    yyparse();

    fclose(fp2);
    fclose(fp3);

    return 0;
}
