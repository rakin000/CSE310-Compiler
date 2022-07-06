%{
    /* definitions */
%}

%%
[a-z] {printf("MoFo encountered a lowercase letter.\n");}
. {printf("MoFo didnot encounter a lowercase letter.\n");}
\n {printf("MoFo encountered a newline\n"); return 0;}
%%

yywrap(){}

int main(){
    printf("Enter string: ");
    yylex();
    return 0;
}