%option noyywrap

%x CONST_NUMBER_STATE 
%x STRING_STATE 
%x MULTI_COMMENT_STATE 
%x SINGLE_COMMENT_STATE 
%x CONST_CHAR_STATE 

%{
#include <bits/stdc++.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
// #define PROMPT 1 
#define SYMBOL_TABLE_BUCKET_SIZE 7
#include "grammer_info.cpp"
#include "y.tab.h"

#define writeLog(s) cout<<"Line No. "<<line_count<<": Token "<<s<<" Lexeme "<<yytext<<" found\n"

using namespace std ;

extern symbol_table* symbolTable;
extern YYSTYPE yylval;
extern int line_count;
extern int error_count;

int id_count = 0;
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
#ifdef PROMPT
  writeLog("LCURL");
#endif
  symbol *s = new symbol(yytext,"LCURL");
  yylval.symbolInfo = s;
  // symbolTable->enter_scope();
  return LCURL;
}
{RCURL} {
#ifdef PROMPT
  writeLog("RCURL");
#endif
  symbol *s = new symbol(yytext,"RCURL");
  yylval.symbolInfo = s;
  // symbolTable->exit_scope();
  return RCURL;
}

{LTHIRD} {
#ifdef PROMPT 
  writeLog("LTHIRD");
#endif 
  symbol *s = new symbol(yytext,"LTHIRD");
  yylval.symbolInfo = s;
  return LTHIRD;
}

{RTHIRD} {
#ifdef PROMPT 
  writeLog("RTHIRD");
#endif 
  symbol *s = new symbol(yytext,"RTHIRD");
  yylval.symbolInfo = s;
  return RTHIRD;
}
{LPAREN} {
#ifdef PROMPT 
  writeLog("LPAREN");
#endif 
  symbol *s = new symbol(yytext,"LPAREN");
  yylval.symbolInfo = s;
  return LPAREN;
}

{RPAREN} {
#ifdef PROMPT 
	writeLog("RPAREN");
#endif
	symbol *s = new symbol(yytext,"RPAREN");
	yylval.symbolInfo = s;
	return RPAREN ;
}
{COMMA} {
#ifdef PROMPT 
	writeLog("COMMA");
#endif
	symbol *s = new symbol(yytext,"COMMA");
	yylval.symbolInfo = s;
	return COMMA;
}
{SEMICOLON} {
#ifdef PROMPT 
	writeLog("SEMICOLON");
#endif
	symbol *s = new symbol(yytext,"SEMICOLON");
	yylval.symbolInfo = s;
  	return SEMICOLON;
} 

{ADDOP} {
#ifdef PROMPT 
	writeLog("ADDOP");
#endif
	symbol *s = new symbol(yytext,"ADDOP");
	yylval.symbolInfo = s;
	return ADDOP;
} 
{MULOP} {
#ifdef PROMPT 
	writeLog("MULOP");
#endif
	symbol *s = new symbol(yytext,"MULOP");
	yylval.symbolInfo = s;
	return MULOP;
} 

{INCOP} {
#ifdef PROMPT 
  writeLog("INCOP");
#endif
	symbol *s = new symbol(yytext,"INCOP");
	yylval.symbolInfo = s;
	return INCOP;
}
{RELOP} {
#ifdef PROMPT 
	writeLog("RELOP");
#endif
	symbol *s = new symbol(yytext,"RELOP");
	yylval.symbolInfo = s;
	return RELOP;
}
{ASSIGNOP} {
#ifdef PROMPT 
  	writeLog("ASSIGNOP");
#endif
	symbol *s = new symbol(yytext,"ASSIGNOP");
	yylval.symbolInfo = s;
	return ASSIGNOP ;
}
{LOGICOP} {
#ifdef PROMPT 
  writeLog("LOGICOP");
#endif
  symbol *s = new symbol(yytext,"LOGICOP");
  yylval.symbolInfo = s;
  return LOGICOP;
}

{NOT}  {
#ifdef PROMPT 
  writeLog("NOT");
#endif
  symbol *s = new symbol(yytext,"NOT");
  yylval.symbolInfo = s;
  return NOT; 
}  

{IF} {
#ifdef PROMPT
  writeLog("IF");
#endif
  symbol *s = new symbol(yytext,"IF");
  yylval.symbolInfo = s;
  return IF;
}
{ELSE} { return ELSE;}
{FOR} {return FOR;}
{WHILE} {return WHILE;}
{INT} {return INT;}
{FLOAT} {return FLOAT;}
{DOUBLE} {return DOUBLE;}
{CHAR} {return CHAR;}
{RETURN} {return RETURN;}
{VOID} {return VOID;}

{IDENTIFIER} {
  // symbolTable->insert(yytext,"ID");
#ifdef PROMPT 
  writeLog("ID");
  symbolTable->print_all_scope_table();
#endif
  symbol *s = new symbol(yytext,"ID");
  yylval.symbolInfo = s;
  return ID; 
}
{CONST_INT} {
#ifdef PROMPT 
  writeLog("CONST_INT"); 
#endif 
  symbol *s = new symbol(yytext,"CONST_INT");
  yylval.symbolInfo = s;
  return CONST_INT ;
}
{CONST_FLOAT} {
#ifdef PROMPT 
  writeLog("CONST_FLOAT"); 
#endif 
  symbol *s = new symbol(yytext,"CONST_FLOAT");
  yylval.symbolInfo = s;
  return CONST_FLOAT ;
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
<STRING_STATE>"\\a" {
  yymore();
  str = str+char('\a');
}
<STRING_STATE>"\\f" {
  yymore();
  str = str+char('\f');
}
<STRING_STATE>"\\r" {
  yymore();
  str = str+char('\r');
}
<STRING_STATE>"\\b" {
  yymore();
  str = str+char('\b');
}
<STRING_STATE>"\\v" {
  yymore();
  str = str + char('\v');
}
<STRING_STATE>"\\\\" {
  yymore(); 
  str = str+char('\\');
}
<STRING_STATE>"\\\'" {
  yymore();
  str = str +char('\'');
}
<STRING_STATE>"\\\"" {
  yymore();
  str = str + char('\"');
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
<MULTI_COMMENT_STATE>"\n"|"\r\n" {
  line_count++;
  str += string(yytext);
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






