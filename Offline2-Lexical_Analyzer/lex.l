%option noyywrap
%option c++

%x CONST_NUMBER_STATE 
%x STRING_STATE 
%x MULTI_COMMENT_STATE 
%x SINGLE_COMMENT_STATE 
%x CONST_CHAR_STATE 

%{
    #include <stdio.h>
    #include <fstream>
    // #define PROMPT 1 
    #define SYMBOL_TABLE_BUCKET_SIZE 7
    #include "symbol_table.cpp"

    #define writeLog(s) cout<<"Line No. "<<line_count<<": Token "<<s<<" Lexeme "<<yytext<<" found\n"
    #define writeToken(s) tokenfile<<"<"<<s<<","<<yytext<<"> ";

    int line_count = 1;
    int error_count = 0;
    int id_count = 0;
    fstream tokenfile("1805012_token.txt",ios_base::out);
    symbol_table symbolTable(7);
    string str; 

    char * toUpper(char *s){
      while( *s ){
        *s = toupper(*s);
        ++s;
      }
      return s;
    }
%}

WS              [ \t\v\f\r]
ALPHA           [A-Za-z]
DIGIT           [0-9]
CONST_INT       {DIGIT}+
EXP             [Ee][+-]?{CONST_INT}
CONST_FLOAT     ({DIGIT}*"."{DIGIT}+{EXP}?)|({DIGIT}+{EXP}) 
CONST_CHAR      ("\'"[^\n\t\\\'\a\f\r\b\v\0]"\'")
CONST_CHAR_ES   ("\'\\"[ntafrbv0\\\']"\'")
IDENTIFIER      [a-zA-Z_][a-zA-Z0-9_]*


ADDOP           [+]|[-] 
MULOP           [*]|[/]|[%]
INCOP           "++"|"--"
RELOP           "<"|"<="|">"|">="|"=="|"!="
ASSIGNOP        [=]
LOGICOP         "&&"|"||"
NOT             "!"

LCURL           [\{]
RCURL           [\}]  
LPAREN          [\(]
RPAREN          [\)]
LTHIRD          [\[]
RTHIRD          [\]]
COMMA           [,]
SEMICOLON       [;]

IF              "if"
FOR             "for"
ELSE            "else"
DO              "do"
INT             "int"
FLOAT           "float"
VOID            "void"
SWITCH          "switch"
DEFAULT         "default"
WHILE           "while"
BREAK           "break"
CHAR            "char"         
DOUBLE          "double"
RETURN          "return"
CASE            "case"
CONTINUE        "continue"

ILL_FORMED_NUMBER           {CONST_FLOAT}("."{DIGIT}*)+
INV_SUF_ON_NUM              ({CONST_INT}{IDENTIFIER})|({CONST_FLOAT}{IDENTIFIER}) 
MULTI_CHAR_CONST            "\'"[^\n\t\\\'\a\f\r\b\v\0]{2,}"\'"
EMPT_CHAR_CONST             "\'\'"




%%
{LCURL} {
  writeLog("LCURL");
  writeToken("LCURL");
  symbolTable.enter_scope();
}
{RCURL} {
  writeLog("RCURL");
  writeToken("RCURL");
  symbolTable.exit_scope();
}
{LTHIRD} {
  writeLog("LTHIRD");
  writeToken("LTHIRD");
}

{RTHIRD} {
  writeLog("RTHIRD");
  writeToken("RTHIRD");
}

{LPAREN} {
  writeLog("LPAREN");
  writeToken("LPAREN");
}

{RPAREN} {
  writeLog("RPAREN");
  writeToken("RPAREN");
}
{COMMA} {
  writeLog("COMMA");
  writeToken("COMMA");
}
{SEMICOLON} {
  writeLog("SEMICOLON");
  writeToken("SEMICOLON");
} 

{ADDOP} {
  writeLog("ADDOP");
  writeToken("ADDOP");
} 
{MULOP} {
  writeLog("MULOP");
  writeToken("MULOP");
}
{INCOP} {
  writeLog("INCOP");
  writeToken("INCOP");
}
{RELOP} {
  writeLog("RELOP");
  writeToken("RELOP");
}
{ASSIGNOP} {
  writeLog("ASSIGNOP");
  writeToken("ASSIGNOP");
}
{LOGICOP} {
  writeLog("LOGICOP");
  writeToken("LOGICOP");
}
{NOT}  {
  writeLog("NOT");
  writeToken("NOT");
}  

{IF}|{ELSE}|{FOR}|{DO}|{INT}|{FLOAT}|{VOID}|{SWITCH}|{DEFAULT}|{WHILE}|{BREAK}|{CHAR}|{DOUBLE}|{RETURN}|{CASE}|{CONTINUE} {
  toUpper(yytext);
  writeLog(yytext);
  tokenfile<<"<"<<yytext<<"> ";
}

{IDENTIFIER} {
  writeLog("ID");
  writeToken("ID");
  symbolTable.insert(yytext,"ID");
  symbolTable.print_all_scope_table();
  id_count++;
}
{CONST_INT} {
  writeLog("CONST_INT"); 
  writeToken("CONST_INT");
}
{CONST_FLOAT} {
  writeLog("CONST_FLOAT");
  writeToken("CONST_FLOAT");
}

\' {
  str = "";
  yymore();
  BEGIN CONST_CHAR_STATE;
}
\" {
  str = "";
  yymore();
  BEGIN STRING_STATE;
}
"\/\/" {
  str = "";
  BEGIN SINGLE_COMMENT_STATE ;
}
"\/*" {
  str = "" ;
  BEGIN MULTI_COMMENT_STATE ;
}

<CONST_CHAR_STATE>"\'" {
  str = yytext ;
  str = str.substr(1,str.length()-2);
  if( str.length() > 2 ) {
    ++error_count;
    cout<<"Line No. "<<line_count<<": multiple character constant, "<<yytext<<endl; 
  }
  else if( str.length() == 2 && str[0] != '\\'){
      ++error_count;
      cout<<"Line No. "<<line_count<<": multiple character constant, "<<yytext<<endl;
  }
  else if( str.length() == 1 && str[0] == '\\'){
      ++error_count;
      cout<<"Line No. "<<line_count<<": invalid character constant "<<yytext<<endl;
  }
  else if( str.length() == 0 ){
      ++error_count;
      cout<<"Line No. "<<line_count<<": empty character constant "<<yytext<<endl;
  }
  else {
    cout<<"Line No. "<<line_count<<": Token "<<"CONST_CHAR"<<" Lexeme "<<str<<" found\n";
    tokenfile<<"<"<<"CONST_CHAR"<<","<<str<<"> ";
  }
  BEGIN(INITIAL);
}
<CONST_CHAR_STATE>"\\[ntafrbv0\\\']" {
  yymore();
}
<CONST_CHAR_STATE>. {
  yymore();
}
<CONST_CHAR_STATE>"\n"|"\r\n" {
  ++error_count;
  ++line_count;
  cout<<"Line No. "<<line_count<<": unfinished character constant, "<<yytext<<endl; 
  BEGIN(INITIAL);
}
<CONST_CHAR_STATE><<EOF>> {
  ++error_count;
  cout<<"Line No. "<<line_count<<": unfinished character constant, "<<yytext<<endl; 
  BEGIN(INITIAL);
}


<STRING_STATE>"\"" {
  cout<<"Line No. "<<line_count<<": Token <STRING> Lexeme "<<yytext<<" found"<<" --> <STRING, "<<"\""<<str<<"\">"<<endl; 
  tokenfile<<"<CONST_STRING,"<<str<<"> ";
  BEGIN(INITIAL);
}
<STRING_STATE>"\\" {
  yymore();
}
<STRING_STATE>"\\\n"|"\\\r\n" {
  yymore();
  line_count++;
}
<STRING_STATE>"\\n" {
  yymore();
  str = str+char('\n') ;
}
<STRING_STATE>"\\t" {
  yymore();
  str = str+char('\t') ;
}
<STRING_STATE>"\n" {
  cout<<"Line No. "<<line_count<<": unfinished string, missing \""<<endl;
  line_count++;
  ++error_count;
  BEGIN(INITIAL) ;
}
<STRING_STATE>. {
  yymore();
  str = str+char(yytext[yyleng-1]);
}
<STRING_STATE><<EOF>> {
  cout<<"Line No. "<<line_count<<": unfinished string."<<endl;
  BEGIN(INITIAL);
}


<SINGLE_COMMENT_STATE>"\n" {
  cout<<"Line No. "<<line_count<<": single line comment "<<str<<endl;
  line_count++;
  BEGIN INITIAL;
}
<SINGLE_COMMENT_STATE>"\\\n"|"\\\r\n" {
  line_count++;
}
<SINGLE_COMMENT_STATE>. {
  str += string(yytext);
}
<SINGLE_COMMENT_STATE><<EOF>> {
  BEGIN(INITIAL);
}

<MULTI_COMMENT_STATE>"*\/" {
  // ++error_count;
  cout<<"Line No. "<<line_count<<": multiline comment "<<str<<endl;
  BEGIN(INITIAL);
}
<MULTI_COMMENT_STATE>. {
  str += string(yytext) ;
}
<MULTI_COMMENT_STATE>"\n" {
  line_count++;
}
<MULTI_COMMENT_STATE><<EOF>> {
  ++error_count;
  cout<<"Line No. "<<line_count<<": error, unfinished comment";
  BEGIN(INITIAL);
}


{ILL_FORMED_NUMBER} {
  ++error_count;
  cout<<"Line No. "<<line_count<<": ill formed number, "<<yytext<<endl;
}

{INV_SUF_ON_NUM} {
  ++error_count;
  cout<<"Line No. "<<line_count<<": invalid suffix on a numeric constand of invalid prefix on an identifier, "<<yytext<<endl;
}

{WS}* {  
  
}

. {
  printf("unrecognized character\n");
  ++error_count;
}

\n  {
  line_count++;
}
<<EOF>> {

  cout<<"\nTotal lines = "<<line_count<<endl;
  cout<<"Total errors = "<<error_count<<endl;
  cout<<"End of File encountered\n";
  return 0;
}
%%



int main(int argc,char** argv){
  if( argc != 2 ){
    cout<<"Invalid format."<<endl;
    return -1;
  }
  // infile = fstream(argv[1],ios_base::in) ;
  freopen(argv[1],"r",stdin);
  freopen("1805012_log.txt","w",stdout);
  // symbolTable = symbol_table(SYMBOL_TABLE_BUCKET_SIZE);
  yyFlexLexer lexer;
  lexer.yylex();
}
