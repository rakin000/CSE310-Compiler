%{
    // no def
%}


%%
if {printf("IF\n");}
int {printf("INT\n");}
double {printf("DOUBLE\n");}
char {printf("CHAR\n");}
[a-zA-Z_]+[a-zA-Z0-9_]* {printf("IDENTIFIER\n");}
\n {printf("Newline Encountered\n"); return 0;}

%%

yywrap(){}

int main(){
    yylex();
}