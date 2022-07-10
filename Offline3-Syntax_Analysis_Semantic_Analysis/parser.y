%code requires{
    #include <bits/stdc++.h>
}

%{
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.cpp"

using namespace std; 

int yyparse(void);
extern int yylex(void);
extern FILE *yyin;
FILE *fp,*fp2,*fp3,*fp1;
symbol_table *symbolTable = new symbol_table(30);

void yyerror(char *s){
    printf("%s",s);
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

%union {
    symbol* symbolInfo;
}

%% 
start : program
	;
program : program unit 
	| unit
	;
	
unit : var_declaration { printf("Var declaration detected !! \n"); }
     ;
var_declaration : type_specifier ID ASSIGNOP CONST_INT SEMICOLON
                | type_specifier ID ASSIGNOP CONST_FLOAT SEMICOLON 
                | type_specifier ID SEMICOLON 
                ; 
                  
    ;
type_specifier: INT 
                |FLOAT 
                | CHAR 
                ;
%%

int main(int argc, char **argv){
    // cout<<argv[1]<<endl;
    if( (fp=fopen(argv[1],"r")) == NULL){
        printf("Cannot Open Input File.\n");
        exit(1);
    }

    // fp2 = fopen(argv[2],"w");
    // fclose(fp2);
    // fp3 = fopen(argv[3],"w");
    // fclose(fp3);

    // fp2 = fopen(argv[2],"a");
    // fp3 = fopen(argv[3],"a");

    // cout<<"Still ok\n";
    yyin = fp;
    yyparse();

    // fclose(fp2);
    // fclose(fp3);
    fclose(fp);
    return 0;
}
