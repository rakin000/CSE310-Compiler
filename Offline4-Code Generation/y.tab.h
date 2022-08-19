/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    DO = 261,                      /* DO  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    VOID = 264,                    /* VOID  */
    SWITCH = 265,                  /* SWITCH  */
    DEFAULT = 266,                 /* DEFAULT  */
    WHILE = 267,                   /* WHILE  */
    BREAK = 268,                   /* BREAK  */
    CHAR = 269,                    /* CHAR  */
    DOUBLE = 270,                  /* DOUBLE  */
    RETURN = 271,                  /* RETURN  */
    CASE = 272,                    /* CASE  */
    CONTINUE = 273,                /* CONTINUE  */
    LCURL = 274,                   /* LCURL  */
    RCURL = 275,                   /* RCURL  */
    LPAREN = 276,                  /* LPAREN  */
    RPAREN = 277,                  /* RPAREN  */
    LTHIRD = 278,                  /* LTHIRD  */
    RTHIRD = 279,                  /* RTHIRD  */
    COMMA = 280,                   /* COMMA  */
    SEMICOLON = 281,               /* SEMICOLON  */
    ADDOP = 282,                   /* ADDOP  */
    MULOP = 283,                   /* MULOP  */
    INCOP = 284,                   /* INCOP  */
    DECOP = 285,                   /* DECOP  */
    RELOP = 286,                   /* RELOP  */
    ASSIGNOP = 287,                /* ASSIGNOP  */
    LOGICOP = 288,                 /* LOGICOP  */
    NOT = 289,                     /* NOT  */
    ID = 290,                      /* ID  */
    CONST_CHAR = 291,              /* CONST_CHAR  */
    CONST_INT = 292,               /* CONST_INT  */
    CONST_FLOAT = 293,             /* CONST_FLOAT  */
    PRINTLN = 294,                 /* PRINTLN  */
    MAIN = 295,                    /* MAIN  */
    LOWER_THAN_ELSE = 296,         /* LOWER_THAN_ELSE  */
    INT_ARRAY = 297,               /* INT_ARRAY  */
    FLOAT_ARRAY = 298,             /* FLOAT_ARRAY  */
    UNKNOWN = 299                  /* UNKNOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define DO 261
#define INT 262
#define FLOAT 263
#define VOID 264
#define SWITCH 265
#define DEFAULT 266
#define WHILE 267
#define BREAK 268
#define CHAR 269
#define DOUBLE 270
#define RETURN 271
#define CASE 272
#define CONTINUE 273
#define LCURL 274
#define RCURL 275
#define LPAREN 276
#define RPAREN 277
#define LTHIRD 278
#define RTHIRD 279
#define COMMA 280
#define SEMICOLON 281
#define ADDOP 282
#define MULOP 283
#define INCOP 284
#define DECOP 285
#define RELOP 286
#define ASSIGNOP 287
#define LOGICOP 288
#define NOT 289
#define ID 290
#define CONST_CHAR 291
#define CONST_INT 292
#define CONST_FLOAT 293
#define PRINTLN 294
#define MAIN 295
#define LOWER_THAN_ELSE 296
#define INT_ARRAY 297
#define FLOAT_ARRAY 298
#define UNKNOWN 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "parser.y"

    symbol* symbolInfo;
    grammer_info* grammerInfo;

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
