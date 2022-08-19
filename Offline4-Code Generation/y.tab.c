/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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
stack<string> Lif,Lelse,Lend,Lbegin,Lloop,Lpostoperation;
queue<string> pendingCode;

vector<string> temp ; 
int temp_count = 0;
string newTemp() {
    string t = "tmp"+to_string(temp_count);
    if( temp_count == temp.size() ) {
        temp.push_back(t) ;
        temp_count++;
    }
    else temp_count++ ;
    return temp[temp_count-1];
}
void removeTemp() {
    temp_count--;
    temp_count = max(0,temp_count) ;
}
int removeTempCount = 0;

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



#line 156 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 87 "parser.y"

    symbol* symbolInfo;
    grammer_info* grammerInfo;

#line 302 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_DO = 6,                         /* DO  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_SWITCH = 10,                    /* SWITCH  */
  YYSYMBOL_DEFAULT = 11,                   /* DEFAULT  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 15,                    /* DOUBLE  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_CASE = 17,                      /* CASE  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_LCURL = 19,                     /* LCURL  */
  YYSYMBOL_RCURL = 20,                     /* RCURL  */
  YYSYMBOL_LPAREN = 21,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 22,                    /* RPAREN  */
  YYSYMBOL_LTHIRD = 23,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 24,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 26,                 /* SEMICOLON  */
  YYSYMBOL_ADDOP = 27,                     /* ADDOP  */
  YYSYMBOL_MULOP = 28,                     /* MULOP  */
  YYSYMBOL_INCOP = 29,                     /* INCOP  */
  YYSYMBOL_DECOP = 30,                     /* DECOP  */
  YYSYMBOL_RELOP = 31,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 32,                  /* ASSIGNOP  */
  YYSYMBOL_LOGICOP = 33,                   /* LOGICOP  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_CONST_CHAR = 36,                /* CONST_CHAR  */
  YYSYMBOL_CONST_INT = 37,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 38,               /* CONST_FLOAT  */
  YYSYMBOL_PRINTLN = 39,                   /* PRINTLN  */
  YYSYMBOL_MAIN = 40,                      /* MAIN  */
  YYSYMBOL_LOWER_THAN_ELSE = 41,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_INT_ARRAY = 42,                 /* INT_ARRAY  */
  YYSYMBOL_FLOAT_ARRAY = 43,               /* FLOAT_ARRAY  */
  YYSYMBOL_UNKNOWN = 44,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_start = 46,                     /* start  */
  YYSYMBOL_program = 47,                   /* program  */
  YYSYMBOL_unit = 48,                      /* unit  */
  YYSYMBOL_var_declaration = 49,           /* var_declaration  */
  YYSYMBOL_type_specifier = 50,            /* type_specifier  */
  YYSYMBOL_declaration_list = 51,          /* declaration_list  */
  YYSYMBOL_func_declaration = 52,          /* func_declaration  */
  YYSYMBOL_parameter_list = 53,            /* parameter_list  */
  YYSYMBOL_func_definition = 54,           /* func_definition  */
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_compound_statement = 57,        /* compound_statement  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_59_4 = 59,                      /* $@4  */
  YYSYMBOL_statements = 60,                /* statements  */
  YYSYMBOL_ifprefix = 61,                  /* ifprefix  */
  YYSYMBOL_62_5 = 62,                      /* $@5  */
  YYSYMBOL_statement = 63,                 /* statement  */
  YYSYMBOL_64_6 = 64,                      /* $@6  */
  YYSYMBOL_65_7 = 65,                      /* $@7  */
  YYSYMBOL_66_8 = 66,                      /* $@8  */
  YYSYMBOL_67_9 = 67,                      /* $@9  */
  YYSYMBOL_68_10 = 68,                     /* $@10  */
  YYSYMBOL_69_11 = 69,                     /* $@11  */
  YYSYMBOL_expression_statement = 70,      /* expression_statement  */
  YYSYMBOL_expression = 71,                /* expression  */
  YYSYMBOL_72_12 = 72,                     /* $@12  */
  YYSYMBOL_variable = 73,                  /* variable  */
  YYSYMBOL_logic_expression = 74,          /* logic_expression  */
  YYSYMBOL_rel_expression = 75,            /* rel_expression  */
  YYSYMBOL_simple_expression = 76,         /* simple_expression  */
  YYSYMBOL_term = 77,                      /* term  */
  YYSYMBOL_unary_expression = 78,          /* unary_expression  */
  YYSYMBOL_factor = 79,                    /* factor  */
  YYSYMBOL_argument_list = 80,             /* argument_list  */
  YYSYMBOL_arguments = 81                  /* arguments  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   122,   128,   136,   142,   147,   153,   201,
     214,   221,   228,   236,   247,   255,   265,   274,   287,   297,
     310,   319,   327,   335,   344,   344,   416,   416,   469,   479,
     479,   498,   498,   516,   522,   529,   529,   544,   550,   556,
     562,   569,   574,   562,   603,   603,   620,   632,   637,   632,
     662,   675,   691,   700,   705,   726,   736,   736,   766,   788,
     827,   837,   875,   885,   924,   934,   962,   972,  1013,  1027,
    1039,  1049,  1061,  1095,  1107,  1118,  1125,  1141,  1160,  1169,
    1177
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "DO", "INT", "FLOAT", "VOID", "SWITCH", "DEFAULT", "WHILE", "BREAK",
  "CHAR", "DOUBLE", "RETURN", "CASE", "CONTINUE", "LCURL", "RCURL",
  "LPAREN", "RPAREN", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "ADDOP",
  "MULOP", "INCOP", "DECOP", "RELOP", "ASSIGNOP", "LOGICOP", "NOT", "ID",
  "CONST_CHAR", "CONST_INT", "CONST_FLOAT", "PRINTLN", "MAIN",
  "LOWER_THAN_ELSE", "INT_ARRAY", "FLOAT_ARRAY", "UNKNOWN", "$accept",
  "start", "program", "unit", "var_declaration", "type_specifier",
  "declaration_list", "func_declaration", "parameter_list",
  "func_definition", "$@1", "$@2", "compound_statement", "$@3", "$@4",
  "statements", "ifprefix", "$@5", "statement", "$@6", "$@7", "$@8", "$@9",
  "$@10", "$@11", "expression_statement", "expression", "$@12", "variable",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
#endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   -84,   -84,   -84,    15,    29,   -84,   -84,     7,   -84,
     -84,   -84,   -84,    -3,    11,    19,   -84,    87,    -8,     5,
     -84,    39,    31,    27,     6,    40,    43,    -7,   -84,    44,
     -84,    53,    29,   -84,    33,    60,   -84,   -84,   -84,   -84,
      44,    48,    65,   105,    64,   -84,   -84,   -84,    71,    69,
      70,    77,   129,   129,   -84,   129,   129,    35,   -84,   -84,
      78,   -84,    12,   -84,    66,    98,   -84,   -84,    81,    -5,
     -84,    82,   -13,    83,   -84,   -84,   -84,   -84,   129,   120,
     -84,    90,    96,    30,   -84,   -84,   129,   129,    84,    97,
     -84,   -84,   -84,   -84,   -84,   -84,    91,   129,   129,   129,
     129,   100,   -84,   129,   -84,   -84,   -84,   103,   102,   104,
     106,   108,   105,   129,   -84,    83,   107,   -84,   -84,   120,
     -84,   -84,   129,   -84,   109,   -84,   -84,   105,   -84,   111,
     -84,   -84,   -84,   129,   105,   -84,   -84,   114,   105,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,    11,    12,     0,     2,     4,     5,     0,     6,
       7,     1,     3,     0,    16,     0,     9,     0,     0,     0,
       8,     0,    26,    23,     0,     0,    14,     0,    18,     0,
      22,    24,     0,    15,     0,    29,    19,    28,    27,    17,
       0,    21,     0,     0,     0,    25,    20,    13,     0,     0,
       0,     0,     0,     0,    53,     0,     0,    58,    74,    75,
       0,    37,     0,    39,     0,    46,    34,    38,     0,    71,
      55,    60,    62,    64,    66,    70,    32,    52,     0,     0,
      47,     0,     0,    71,    68,    69,     0,     0,     0,    16,
      30,    33,    44,    54,    76,    77,     0,     0,     0,     0,
       0,     0,    40,     0,    51,    73,    80,     0,    78,     0,
      58,     0,     0,     0,    61,    65,    63,    67,    35,     0,
      48,    72,     0,    59,     0,    45,    57,     0,    41,     0,
      79,    50,    36,     0,     0,    42,    49,     0,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   132,    17,    16,   -84,   -84,   -84,   -84,
     -84,   -84,   -20,   -84,   -84,   -84,   -84,   -84,   -62,   -84,
     -84,   -84,   -84,   -84,   -84,   -73,   -52,   -84,   -45,   -83,
      41,    46,    50,   -51,   -84,   -84,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,    61,    62,    15,     9,    24,    10,
      40,    29,    63,    43,    44,    64,    65,   127,    66,   119,
     133,   137,   112,   103,   129,    67,    68,    96,    69,    70,
      71,    72,    73,    74,    75,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    82,    91,   106,    84,    85,   102,    37,    13,    38,
      83,    83,    35,    13,    98,    11,     8,     7,    99,    36,
      45,     8,     7,    16,    94,    95,   101,   -56,    31,    25,
     126,    32,    17,    23,    18,   109,     1,     2,     3,   130,
      26,    83,    14,   111,    19,    20,   128,    89,    41,   117,
     125,   120,    83,    83,    83,    83,    86,    28,    87,    94,
      95,    27,    30,    35,    33,   132,    34,    48,    83,    49,
      42,    50,   136,     1,     2,     3,   139,    83,    51,    39,
     -31,   135,    52,    46,    76,    35,    90,    53,    21,    47,
      78,    79,    54,    55,     1,     2,     3,    77,    80,    88,
      56,    57,    92,    58,    59,    60,    48,    93,    49,    22,
      50,   100,     1,     2,     3,    97,   104,    51,   105,   110,
      18,    52,   118,   113,    35,   121,    53,   122,   123,    87,
     124,    54,    55,   134,    98,   131,   138,    12,   114,    56,
      57,    53,    58,    59,    60,   116,    54,    55,   115,     0,
      53,     0,     0,     0,    56,    57,    55,    58,    59,     0,
       0,     0,     0,    56,    57,     0,    58,    59
};

static const yytype_int16 yycheck[] =
{
      52,    53,    64,    86,    55,    56,    79,    27,     1,    29,
      55,    56,    19,     1,    27,     0,     0,     0,    31,    26,
      40,     5,     5,    26,    29,    30,    78,    32,    22,    37,
     113,    25,    21,    17,    23,    87,     7,     8,     9,   122,
      35,    86,    35,    88,    25,    26,   119,    35,    32,   100,
     112,   103,    97,    98,    99,   100,    21,    26,    23,    29,
      30,    22,    35,    19,    24,   127,    23,     1,   113,     3,
      37,     5,   134,     7,     8,     9,   138,   122,    12,    26,
      20,   133,    16,    35,    20,    19,    20,    21,     1,    24,
      21,    21,    26,    27,     7,     8,     9,    26,    21,    21,
      34,    35,     4,    37,    38,    39,     1,    26,     3,    22,
       5,    28,     7,     8,     9,    33,    26,    12,    22,    35,
      23,    16,    22,    32,    19,    22,    21,    25,    24,    23,
      22,    26,    27,    22,    27,    26,    22,     5,    97,    34,
      35,    21,    37,    38,    39,    99,    26,    27,    98,    -1,
      21,    -1,    -1,    -1,    34,    35,    27,    37,    38,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    46,    47,    48,    49,    50,    52,
      54,     0,    48,     1,    35,    51,    26,    21,    23,    25,
      26,     1,    22,    50,    53,    37,    35,    22,    26,    56,
      35,    22,    25,    24,    23,    19,    26,    57,    57,    26,
      55,    50,    37,    58,    59,    57,    35,    24,     1,     3,
       5,    12,    16,    21,    26,    27,    34,    35,    37,    38,
      39,    49,    50,    57,    60,    61,    63,    70,    71,    73,
      74,    75,    76,    77,    78,    79,    20,    26,    21,    21,
      21,    71,    71,    73,    78,    78,    21,    23,    21,    35,
      20,    63,     4,    26,    29,    30,    72,    33,    27,    31,
      28,    71,    70,    68,    26,    22,    74,    80,    81,    71,
      35,    73,    67,    32,    75,    77,    76,    78,    22,    64,
      71,    22,    25,    24,    22,    63,    74,    62,    70,    69,
      74,    26,    63,    65,    22,    71,    63,    66,    22,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    51,    51,    52,    52,    52,
      53,    53,    53,    53,    55,    54,    56,    54,    54,    58,
      57,    59,    57,    60,    60,    62,    61,    63,    63,    63,
      64,    65,    66,    63,    67,    63,    63,    68,    69,    63,
      63,    63,    63,    70,    70,    71,    72,    71,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    80,    81,
      81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     6,     3,     4,     1,     6,     5,     6,
       4,     3,     2,     1,     0,     7,     0,     6,     6,     0,
       4,     0,     3,     2,     1,     0,     6,     1,     1,     1,
       0,     0,     0,    10,     0,     4,     1,     0,     0,     7,
       5,     3,     2,     1,     2,     1,     0,     4,     1,     4,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     3,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: program  */
#line 114 "parser.y"
                {
            writeLog("start: program","");
            symbolTable->print_all_scope_table() ;

            free((yyvsp[0].grammerInfo));
            YYACCEPT;
        }
#line 1750 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 122 "parser.y"
                      {
            (yyval.grammerInfo) = new grammer_info("program: program unit",string((yyvsp[-1].grammerInfo)->text+"\n"+(yyvsp[0].grammerInfo)->text) );
            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);

            free((yyvsp[-1].grammerInfo)); free((yyvsp[0].grammerInfo));
        }
#line 1761 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 128 "parser.y"
                   {
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            writeLog("program: unit",(yyval.grammerInfo)->text);

            free((yyvsp[0].grammerInfo));
        }
#line 1772 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 136 "parser.y"
                        { 
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            free((yyvsp[0].grammerInfo));

            writeLog("unit: var_declaration",(yyval.grammerInfo)->text); 
        }
#line 1783 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 142 "parser.y"
                          {
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            free((yyvsp[0].grammerInfo));
            writeLog("unit: func_declaration",(yyval.grammerInfo)->text);
        }
#line 1793 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 147 "parser.y"
                         {
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            free((yyvsp[0].grammerInfo));
            writeLog("unit: func_definition",(yyval.grammerInfo)->text);
        }
#line 1803 "y.tab.c"
    break;

  case 8: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 153 "parser.y"
                                                           {
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[-2].grammerInfo)->text + " " + (yyvsp[-1].grammerInfo)->text + ";"));
                    if( (yyvsp[-2].grammerInfo)->type == _void_ )
                        writeError("variable type cannot be void");

                    int dec_cnt= 0;
                    for(int i=0;i<(yyvsp[-1].grammerInfo)->ids.size();i++){
                        (yyvsp[-1].grammerInfo)->ids[i].type = (yyvsp[-2].grammerInfo)->text;
                        symbol* foundSymbol = symbolTable->lookup_current((yyvsp[-1].grammerInfo)->ids[i].name ) ; 
                        if( foundSymbol == nullptr ){
                            offset_bp -= 2;
                            dec_cnt++;
                            foundSymbol = new symbol( (yyvsp[-1].grammerInfo)->ids[i].name,
                                                    (yyvsp[-1].grammerInfo)->ids[i].type, 
                                                    // (symbolTable->current_scope()->get_id() == "1") ? $2->ids[i].name: string("[BP +")+to_string(offset_bp)+string("]"),
                                                    (symbolTable->current_scope()->get_id() == "1") ? (yyvsp[-1].grammerInfo)->ids[i].name: to_string(offset_bp),
                                                    (yyvsp[-1].grammerInfo)->ids[i].array_size) ;
                            symbolTable->insert(foundSymbol);
                            if( (yyvsp[-1].grammerInfo)->ids[i].array_size != -1 ){
                                offset_bp -= 2*((yyvsp[-1].grammerInfo)->ids[i].array_size-1) ;
                                dec_cnt += (yyvsp[-1].grammerInfo)->ids[i].array_size-1;
                            }

                            // code 
                            if( symbolTable->current_scope()->get_id() == "1" ){
                                // codefile << $2->ids[i].name << " DW " << "?\n";
                                writeCode((yyvsp[-1].grammerInfo)->ids[i].name+" DW "+"?");
                            } 
                            else {
                                // writeCode("PUSH 0\n");
                            }
                            // end code ;

                            delete foundSymbol ;
                        }
                        else {
                            writeError("multiple declaration of "+(yyvsp[-1].grammerInfo)->ids[i].name);
                        }
                    }
                    //code 
                    if( symbolTable->current_scope()->get_id() != "1" ) 
                        writeCode("ADD SP, "+to_string(dec_cnt*-2));
                    //end 


                    free((yyvsp[-2].grammerInfo)); free((yyvsp[-1].grammerInfo)); 
                    writeLog("var_declaration: type_specifier declaration_list SEMICOLON",(yyval.grammerInfo)->text);
                }
#line 1856 "y.tab.c"
    break;

  case 9: /* var_declaration: type_specifier error SEMICOLON  */
#line 201 "parser.y"
                                                 {
                    // yyerror("syntax error");
                    yyerrok;
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[-2].grammerInfo)->text + " ;"));
                    if( (yyvsp[-2].grammerInfo)->type == _void_ )
                        writeError("variable type cannot be void");
    
                    

                    writeLog("var_declaration: type_specifier declaration_list SEMICOLON",(yyval.grammerInfo)->text);
                }
#line 1872 "y.tab.c"
    break;

  case 10: /* type_specifier: INT  */
#line 214 "parser.y"
                    {
                    (yyval.grammerInfo) = new grammer_info(string("int"));
                    (yyval.grammerInfo)->text = "int";
                    (yyval.grammerInfo)->type = _int_ ; 

                    writeLog("type_specifier: INT",(yyval.grammerInfo)->text);
                }
#line 1884 "y.tab.c"
    break;

  case 11: /* type_specifier: FLOAT  */
#line 221 "parser.y"
                       {
                    (yyval.grammerInfo) = new grammer_info(string("float"));
                    (yyval.grammerInfo)->text = "float";
                    (yyval.grammerInfo)->type = _float_; 

                    writeLog("type_specifier: FLOAT",(yyval.grammerInfo)->text);
                }
#line 1896 "y.tab.c"
    break;

  case 12: /* type_specifier: VOID  */
#line 228 "parser.y"
                      {
                    (yyval.grammerInfo) = new grammer_info(string("void"));
                    (yyval.grammerInfo)->text = "void";
                    (yyval.grammerInfo)->type = _void_ ;

                    writeLog("type_specifier: VOID",(yyval.grammerInfo)->text);
                }
#line 1908 "y.tab.c"
    break;

  case 13: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 236 "parser.y"
                                                                    {
                    (yyval.grammerInfo) = new grammer_info("declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD",string((yyvsp[-5].grammerInfo)->text + "," + (yyvsp[-3].symbolInfo)->getName() + "[" + (yyvsp[-1].symbolInfo)->getName() + "]"));
                    (yyval.grammerInfo)->ids = (yyvsp[-5].grammerInfo)->ids;
                    if( stoi((yyvsp[-1].symbolInfo)->getName()) < 0 )
                        writeError("array size must be positive");    
                    (yyvsp[-3].symbolInfo)->setArraySize(stoi((yyvsp[-1].symbolInfo)->getName()));
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[-3].symbolInfo)->getName(),(yyvsp[-3].symbolInfo)->getType(),(yyvsp[-3].symbolInfo)->getArraySize()});
                    free((yyvsp[-5].grammerInfo)); free((yyvsp[-3].symbolInfo)); free((yyvsp[-1].symbolInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);                
                }
#line 1924 "y.tab.c"
    break;

  case 14: /* declaration_list: declaration_list COMMA ID  */
#line 247 "parser.y"
                                           {
                    (yyval.grammerInfo) = new grammer_info("declaration_list: declaration_list COMMA ID",string((yyvsp[-2].grammerInfo)->text + "," + (yyvsp[0].symbolInfo)->getName()));
                    (yyval.grammerInfo)->ids = (yyvsp[-2].grammerInfo)->ids;
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[0].symbolInfo)->getName(),(yyvsp[0].symbolInfo)->getType(),(yyvsp[0].symbolInfo)->getArraySize()});
                    free((yyvsp[-2].grammerInfo)); free((yyvsp[0].symbolInfo)); 

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 1937 "y.tab.c"
    break;

  case 15: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 255 "parser.y"
                                             {
                    (yyval.grammerInfo) = new grammer_info("declaration_list: ID LTHIRD CONST_INT RTHIRD",string((yyvsp[-3].symbolInfo)->getName() + "[" + (yyvsp[-1].symbolInfo)->getName() + "]"));
                    if( stoi((yyvsp[-1].symbolInfo)->getName()) < 0 )
                        writeError("array size must be positive");
                    (yyvsp[-3].symbolInfo)->setArraySize(stoi((yyvsp[-1].symbolInfo)->getName()));
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[-3].symbolInfo)->getName(),(yyvsp[-3].symbolInfo)->getType(),(yyvsp[-3].symbolInfo)->getArraySize()});
                    free((yyvsp[-3].symbolInfo)); free((yyvsp[-1].symbolInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text) ;
                }
#line 1952 "y.tab.c"
    break;

  case 16: /* declaration_list: ID  */
#line 265 "parser.y"
                     {
                    (yyval.grammerInfo) = new grammer_info("declaration_list: ID",string((yyvsp[0].symbolInfo)->getName()));
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[0].symbolInfo)->getName(),(yyvsp[0].symbolInfo)->getType(),(yyvsp[0].symbolInfo)->getArraySize()}); // default array_size = -1;
                    free((yyvsp[0].symbolInfo));  

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 1964 "y.tab.c"
    break;

  case 17: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 274 "parser.y"
                                                                           {
                    (yyval.grammerInfo) = new grammer_info("func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",(yyvsp[-5].grammerInfo)->text+" "+(yyvsp[-4].symbolInfo)->getName()+"("+(yyvsp[-2].grammerInfo)->text+");");
                    (yyvsp[-4].symbolInfo)->setType((yyvsp[-5].grammerInfo)->text);
                    for(int i=0;i<(yyvsp[-2].grammerInfo)->ids.size();i++){
                        (yyvsp[-4].symbolInfo)->getParams().push_back({(yyvsp[-2].grammerInfo)->ids[i].name,(yyvsp[-2].grammerInfo)->ids[i].type,(yyvsp[-2].grammerInfo)->ids[i].array_size});
                    }
                    (yyvsp[-4].symbolInfo)->markAsFunction();
                    declaredFunctions->insert((yyvsp[-4].symbolInfo));

                    free((yyvsp[-5].grammerInfo)); free((yyvsp[-2].grammerInfo)); free((yyvsp[-4].symbolInfo));
                    
                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 1982 "y.tab.c"
    break;

  case 18: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 287 "parser.y"
                                                            {
                    (yyval.grammerInfo) = new grammer_info("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",(yyvsp[-4].grammerInfo)->text+" "+(yyvsp[-3].symbolInfo)->getName()+"();");
                    (yyvsp[-3].symbolInfo)->setType((yyvsp[-4].grammerInfo)->text);
                    (yyvsp[-3].symbolInfo)->markAsFunction();
                    declaredFunctions->insert((yyvsp[-3].symbolInfo));
                    
                    free((yyvsp[-4].grammerInfo)); free((yyvsp[-3].symbolInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
                }
#line 1997 "y.tab.c"
    break;

  case 19: /* func_declaration: type_specifier ID LPAREN error RPAREN SEMICOLON  */
#line 297 "parser.y"
                                                                  {
                    // yyerror("syntax error, function declaration");
                    yyerrok;
                    (yyval.grammerInfo) = new grammer_info("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",(yyvsp[-5].grammerInfo)->text+" "+(yyvsp[-4].symbolInfo)->getName()+"();");
                    (yyvsp[-4].symbolInfo)->setType((yyvsp[-5].grammerInfo)->text);
                    (yyvsp[-4].symbolInfo)->markAsFunction();
                    declaredFunctions->insert((yyvsp[-4].symbolInfo));
                    
                    // delete $1; delete $2;

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
                }
#line 2014 "y.tab.c"
    break;

  case 20: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 310 "parser.y"
                                                       {
                    (yyval.grammerInfo) = new grammer_info("parameter_list: parameter_list COMMA type_specifier ID",(yyvsp[-3].grammerInfo)->text +"," + (yyvsp[-1].grammerInfo)->text + " " + (yyvsp[0].symbolInfo)->getName());
                    (yyval.grammerInfo)->ids = (yyvsp[-3].grammerInfo)->ids;
                    (yyvsp[0].symbolInfo)->setType((yyvsp[-1].grammerInfo)->text);
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[0].symbolInfo)->getName(),(yyvsp[0].symbolInfo)->getType(),(yyvsp[0].symbolInfo)->getArraySize()});
                    free((yyvsp[-3].grammerInfo)); free((yyvsp[-1].grammerInfo)); free((yyvsp[0].symbolInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 2028 "y.tab.c"
    break;

  case 21: /* parameter_list: parameter_list COMMA type_specifier  */
#line 319 "parser.y"
                                                      {
                    (yyval.grammerInfo) = new grammer_info("parameter_list: parameter_list COMMA type_specifier",(yyvsp[-2].grammerInfo)->text +"," + (yyvsp[0].grammerInfo)->text);
                    (yyval.grammerInfo)->ids = (yyvsp[-2].grammerInfo)->ids;
                    (yyvsp[-2].grammerInfo)->ids.push_back({"_",(yyvsp[0].grammerInfo)->text,-1}); 
                    free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo)); 

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 2041 "y.tab.c"
    break;

  case 22: /* parameter_list: type_specifier ID  */
#line 327 "parser.y"
                                    {
                    (yyval.grammerInfo) = new grammer_info("parameter_list: type_specifier ID",(yyvsp[-1].grammerInfo)->text +" " + (yyvsp[0].symbolInfo)->getName());
                    (yyvsp[0].symbolInfo)->setType((yyvsp[-1].grammerInfo)->text);
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[0].symbolInfo)->getName(),(yyvsp[0].symbolInfo)->getType(),(yyvsp[0].symbolInfo)->getArraySize()});
                    free((yyvsp[-1].grammerInfo)); free((yyvsp[0].symbolInfo));
                    
                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text) ;
                }
#line 2054 "y.tab.c"
    break;

  case 23: /* parameter_list: type_specifier  */
#line 335 "parser.y"
                                 {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                    (yyval.grammerInfo)->ids.push_back({"_",(yyvsp[0].grammerInfo)->text,-1});
                    free((yyvsp[0].grammerInfo));

                    writeLog("parameter_list: type_specifier",(yyval.grammerInfo)->text) ;
                }
#line 2066 "y.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 344 "parser.y"
                                                                 {
                        (yyvsp[-3].symbolInfo)->setType((yyvsp[-4].grammerInfo)->text);
                        for(int i=0;i<(yyvsp[-1].grammerInfo)->ids.size();i++){
                            (yyvsp[-3].symbolInfo)->getParams().push_back({(yyvsp[-1].grammerInfo)->ids[i].name,(yyvsp[-1].grammerInfo)->ids[i].type,(yyvsp[-1].grammerInfo)->ids[i].array_size});
                        }
                        (yyvsp[-3].symbolInfo)->markAsFunction();
                        symbol* foundSymbol = symbolTable->lookup((yyvsp[-3].symbolInfo)->getName());
                        if( foundSymbol != nullptr ){
                            writeError("multiple definition of function "+(yyvsp[-3].symbolInfo)->to_string());
                        }
                        foundSymbol = declaredFunctions->lookup((yyvsp[-3].symbolInfo)->getName());
                        if( foundSymbol != nullptr ){
                            if( foundSymbol->getType() != (yyvsp[-3].symbolInfo)->getType())
                                writeError((yyvsp[-3].symbolInfo)->to_string()+", return type doesn't match with function declaration "+foundSymbol->to_string() ) ;
                            if( foundSymbol->getParams().size() != (yyvsp[-3].symbolInfo)->getParams().size() )
                                writeError((yyvsp[-3].symbolInfo)->to_string()+", number of parameters don't match with function declaration "+foundSymbol->to_string() );
                            else {
                                for(int i=0;i<foundSymbol->getParams().size();i++){
                                    if( foundSymbol->getParams()[i].type != (yyvsp[-3].symbolInfo)->getParams()[i].type )
                                        writeError((yyvsp[-3].symbolInfo)->to_string()+" parameters don't match with function declaration "+foundSymbol->to_string());
                                }
                            }
                        } 
                        symbolTable->insert((yyvsp[-3].symbolInfo));
                        symbolTable->enter_scope();
                        currentFunction = symbolTable->lookup((yyvsp[-3].symbolInfo)->getName());
                        activeFunctions.push(currentFunction);
                        inFunction = 1;

                        //code 
                        // codefile << $2->getName() << " PROC: \n" ;
                        writeCode((yyvsp[-3].symbolInfo)->getName() +" PROC");
                        tab_count++;
                        if( (yyvsp[-3].symbolInfo)->getName() == "main" ){
                            writeCode("MOV AX, @DATA");
                            writeCode("MOV DS, AX","load data to DS");
                        }
                        writeCode("MOV BP, SP","save SP") ;
                        // end code 
                        offset_bp = 0;
                        
                        for(int i=0;i<(yyvsp[-1].grammerInfo)->ids.size();i++){
                            foundSymbol = symbolTable->lookup_current((yyvsp[-1].grammerInfo)->ids[i].name);
                            if( foundSymbol == nullptr){
                                // foundSymbol = new symbol($4->ids[i].name,$4->ids[i].type,string("[BP +")+to_string(offset_bp)+string("]"),$4->ids[i].array_size);
                                foundSymbol = new symbol((yyvsp[-1].grammerInfo)->ids[i].name,(yyvsp[-1].grammerInfo)->ids[i].type,to_string(offset_bp),(yyvsp[-1].grammerInfo)->ids[i].array_size);
                                symbolTable->insert(foundSymbol);
                                offset_bp += 2;

                                free(foundSymbol);
                            }
                            else 
                                writeError("multiple parameters of same name");
                        }
                        offset_bp = 0 ;

                    }
#line 2128 "y.tab.c"
    break;

  case 25: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 400 "parser.y"
                                         {
                    (yyval.grammerInfo) = new grammer_info("func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement",(yyvsp[-6].grammerInfo)->text+" "+(yyvsp[-5].symbolInfo)->getName()+"("+(yyvsp[-3].grammerInfo)->text+")"+(yyvsp[0].grammerInfo)->text); 

                    // code 
                    if( (yyvsp[-5].symbolInfo)->getName() == "main"){
                        writeCode("MOV AH, 4CH") ;
                        writeCode("INT 21H") ;
                    }
                    --tab_count;
                    writeCode((yyvsp[-5].symbolInfo)->getName()+" ENDP") ;               
                    //end code 

                    offset_bp = 0;
                    free((yyvsp[-6].grammerInfo)); free((yyvsp[-3].grammerInfo)); 
                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text) ;
                }
#line 2149 "y.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 416 "parser.y"
                                                  {
                        (yyvsp[-2].symbolInfo)->setType((yyvsp[-3].grammerInfo)->text);
                        (yyvsp[-2].symbolInfo)->markAsFunction();
                        symbol* foundSymbol = symbolTable->lookup((yyvsp[-2].symbolInfo)->getName());
                        if( foundSymbol != nullptr ){
                            writeError("multiple definition of function "+(yyvsp[-2].symbolInfo)->to_string());
                        }
                        foundSymbol = declaredFunctions->lookup((yyvsp[-2].symbolInfo)->getName());
                        if( foundSymbol != nullptr ){
                            if( foundSymbol->getType() != (yyvsp[-2].symbolInfo)->getType())
                                writeError((yyvsp[-2].symbolInfo)->to_string()+", return type doesn't match with function declaration "+foundSymbol->to_string() ) ;
                            if( foundSymbol->getParams().size() != (yyvsp[-2].symbolInfo)->getParams().size() )
                                writeError((yyvsp[-2].symbolInfo)->to_string()+", number of parameters don't match with function declaration "+foundSymbol->to_string() );
                            else {
                                for(int i=0;i<foundSymbol->getParams().size();i++){
                                    if( foundSymbol->getParams()[i].type != (yyvsp[-2].symbolInfo)->getParams()[i].type )
                                        writeError((yyvsp[-2].symbolInfo)->to_string()+" parameters don't match with function declaration "+foundSymbol->to_string());
                                }
                            }
                        } 
                        symbolTable->insert((yyvsp[-2].symbolInfo));
                        symbolTable->enter_scope();
                        currentFunction = symbolTable->lookup((yyvsp[-2].symbolInfo)->getName());
                        activeFunctions.push(currentFunction);
                        inFunction = 1;

                        //code 
                        writeCode((yyvsp[-2].symbolInfo)->getName()+" PROC");
                        tab_count++;
                        if( (yyvsp[-2].symbolInfo)->getName() == "main" ){
                            writeCode("MOV AX, @DATA");
                            writeCode("MOV DS, AX","load data to DS");
                        }
                        writeCode("MOV BP, SP","save SP") ;
                        // end code 

                        offset_bp = 0;
                    }
#line 2192 "y.tab.c"
    break;

  case 27: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 453 "parser.y"
                                         {
                    (yyval.grammerInfo) = new grammer_info("func_definition: type_specifier ID LPAREN RPAREN compound_statement",(yyvsp[-5].grammerInfo)->text+" "+(yyvsp[-4].symbolInfo)->getName()+"()"+(yyvsp[0].grammerInfo)->text); 
                    
                    // code 
                    if( (yyvsp[-4].symbolInfo)->getName() == "main"){
                        writeCode("MOV AH, 4CH") ;
                        writeCode("INT 21H") ;
                    }
                    --tab_count;
                    writeCode((yyvsp[-4].symbolInfo)->getName()+" ENDP") ;               
                    //end code 
                    
                    offset_bp = 0; 
                    free((yyvsp[-5].grammerInfo)); free((yyvsp[-4].symbolInfo));
                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 2213 "y.tab.c"
    break;

  case 28: /* func_definition: type_specifier ID LPAREN error RPAREN compound_statement  */
#line 469 "parser.y"
                                                                           {
                    // yyerror("syntax error, function definition");
                    yyerrok;
                    (yyval.grammerInfo) = new grammer_info("func_definition: type_specifier ID LPAREN RPAREN compound_statement",(yyvsp[-5].grammerInfo)->text+" "+(yyvsp[-4].symbolInfo)->getName()+"()"+(yyvsp[0].grammerInfo)->text); 
                    // delete $1; delete $2;

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);

                }
#line 2227 "y.tab.c"
    break;

  case 29: /* $@3: %empty  */
#line 479 "parser.y"
                          {
                            if( !inFunction ){
                                symbolTable->enter_scope();
                                currentFunction = dummySymbol ;
                                activeFunctions.push(currentFunction);
                            }
                            inFunction = 0;
                            offset_bp = 0 ;
                        }
#line 2241 "y.tab.c"
    break;

  case 30: /* compound_statement: LCURL $@3 statements RCURL  */
#line 487 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info("compound_statement: LCURL statements RCURL","{\n"+(yyvsp[-1].grammerInfo)->text+"\n}");

                        free((yyvsp[-1].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text); 
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                        activeFunctions.pop();
                        currentFunction = activeFunctions.top();
                    }
#line 2257 "y.tab.c"
    break;

  case 31: /* $@4: %empty  */
#line 498 "parser.y"
                            {
                            if( !inFunction ){
                                symbolTable->enter_scope();
                                currentFunction = dummySymbol ;
                                activeFunctions.push(currentFunction);
                            }
                            inFunction = 0;
                        }
#line 2270 "y.tab.c"
    break;

  case 32: /* compound_statement: LCURL $@4 RCURL  */
#line 506 "parser.y"
                              {
                        (yyval.grammerInfo) = new grammer_info("compound_statement: LCURL RCURL","{\n}");

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                        activeFunctions.pop();
                        currentFunction = activeFunctions.top();
                    }
#line 2284 "y.tab.c"
    break;

  case 33: /* statements: statements statement  */
#line 516 "parser.y"
                                 {
                (yyval.grammerInfo) = new grammer_info("statements: statements statement",(yyvsp[-1].grammerInfo)->text+"\n"+(yyvsp[0].grammerInfo)->text);
                free((yyvsp[-1].grammerInfo)); free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2295 "y.tab.c"
    break;

  case 34: /* statements: statement  */
#line 522 "parser.y"
                       {
                (yyval.grammerInfo) = new grammer_info("statements: statement",(yyvsp[0].grammerInfo)->text);
                free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2306 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 529 "parser.y"
                                       { 
                    Lelse.push(newLabel());
                    Lend.push(newLabel());
                    //code
                    writeCode("POP AX");
                    writeCode("CMP AX,0");
                    writeCode("JE "+Lelse.top()) ;
                    // write
                    //end
                }
#line 2321 "y.tab.c"
    break;

  case 36: /* ifprefix: IF LPAREN expression RPAREN $@5 statement  */
#line 538 "parser.y"
                            {
                    (yyval.grammerInfo) = new grammer_info("statement: IF LPAREN expression RPAREN statement ELSE statement","if("+(yyvsp[-3].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text+"\n");
                
                    delete (yyvsp[-3].grammerInfo);
                }
#line 2331 "y.tab.c"
    break;

  case 37: /* statement: var_declaration  */
#line 544 "parser.y"
                            {
                (yyval.grammerInfo) = new grammer_info("statement: var_declaration",(yyvsp[0].grammerInfo)->text);
                free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2342 "y.tab.c"
    break;

  case 38: /* statement: expression_statement  */
#line 550 "parser.y"
                                  {
                (yyval.grammerInfo) = new grammer_info("statement: expression_statement",(yyvsp[0].grammerInfo)->text);
                
                free((yyvsp[0].grammerInfo));
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2353 "y.tab.c"
    break;

  case 39: /* statement: compound_statement  */
#line 556 "parser.y"
                                {
                (yyval.grammerInfo) = new grammer_info("statement: compound_statement",(yyvsp[0].grammerInfo)->text);
                free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2364 "y.tab.c"
    break;

  case 40: /* $@6: %empty  */
#line 562 "parser.y"
                                             {
                    Lbegin.push(newLabel()) ;
                    Lpostoperation.push(newLabel()) ;
                    Lloop.push(newLabel()) ;
                    Lend.push(newLabel()) ;

                    writeCode(Lbegin.top()+":", "begin FOR loop");
                }
#line 2377 "y.tab.c"
    break;

  case 41: /* $@7: %empty  */
#line 569 "parser.y"
                                       {
                    writeCode("CMP AX, 0");
                    writeCode("JE "+Lend.top());
                    writeCode("JMP "+Lloop.top()) ;
                    writeCode(Lpostoperation.top()+":", "FOR loop post operation") ;
                }
#line 2388 "y.tab.c"
    break;

  case 42: /* $@8: %empty  */
#line 574 "parser.y"
                             {
                    writeCode("POP AX");
                    writeCode("PUSHF");
                    while( !pendingCode.empty() ){
                        writeCode(pendingCode.front()) ;
                        pendingCode.pop();
                    }
                    while( removeTempCount ){
                        removeTemp();
                        removeTempCount-- ;
                    }
                    writeCode("POPF");
                    writeCode("JMP "+Lbegin.top());
                    writeCode(Lloop.top()+":");
                }
#line 2408 "y.tab.c"
    break;

  case 43: /* statement: FOR LPAREN expression_statement $@6 expression_statement $@7 expression $@8 RPAREN statement  */
#line 588 "parser.y"
                                   {
                (yyval.grammerInfo) = new grammer_info ("statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement","for("+(yyvsp[-7].grammerInfo)->text+(yyvsp[-5].grammerInfo)->text+(yyvsp[-3].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text);
                

                writeCode("JMP "+Lpostoperation.top()) ;
                writeCode(Lend.top()+":", "FOR loop end") ;
                Lbegin.pop();
                Lend.pop();
                Lloop.pop();
                Lpostoperation.pop();


                free((yyvsp[-7].grammerInfo)); free((yyvsp[-5].grammerInfo)); free((yyvsp[-3].grammerInfo)); free((yyvsp[0].grammerInfo));
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
            }
#line 2428 "y.tab.c"
    break;

  case 44: /* $@9: %empty  */
#line 603 "parser.y"
                           {
                    //code 
                    writeCode("JMP "+Lend.top()) ;
                    writeCode(Lelse.top()+":");
                    //end 
                }
#line 2439 "y.tab.c"
    break;

  case 45: /* statement: ifprefix ELSE $@9 statement  */
#line 608 "parser.y"
                            {
                (yyval.grammerInfo) = new grammer_info("statement: IF LPAREN expression RPAREN statement ELSE statement",(yyvsp[-3].grammerInfo)->text+"else\n"+(yyvsp[0].grammerInfo)->text);
                
                //code 
                writeCode(Lend.top()+":");
                Lend.pop();
                Lelse.pop();
                //

                free((yyvsp[-3].grammerInfo)); free((yyvsp[0].grammerInfo)); // free($9);   
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2456 "y.tab.c"
    break;

  case 46: /* statement: ifprefix  */
#line 620 "parser.y"
                                            {
                (yyval.grammerInfo) = new grammer_info("statement: IF LPAREN expression RPAREN statement",(yyvsp[0].grammerInfo)->text);
                
                //code
                writeCode(Lelse.top()+":"); 
                Lend.pop();
                Lelse.pop();
                //end 

                free((yyvsp[0].grammerInfo)); //free($6);
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2473 "y.tab.c"
    break;

  case 47: /* $@10: %empty  */
#line 632 "parser.y"
                          {
                    Lbegin.push(newLabel()) ;
                    Lend.push(newLabel()) ;

                    writeCode(Lbegin.top()+":", "begin while loop");
                }
#line 2484 "y.tab.c"
    break;

  case 48: /* $@11: %empty  */
#line 637 "parser.y"
                             {
                    writeCode("POP AX");
                    writeCode("CMP AX, 0");
                    writeCode("PUSHF");
                    while( !pendingCode.empty() ){
                        writeCode(pendingCode.front()) ;
                        pendingCode.pop();
                    }
                    while( removeTempCount ){
                        removeTemp();
                        removeTempCount-- ;
                    }
                    writeCode("POPF");
                    writeCode("JE "+Lend.top()) ;
                }
#line 2504 "y.tab.c"
    break;

  case 49: /* statement: WHILE LPAREN $@10 expression $@11 RPAREN statement  */
#line 651 "parser.y"
                                   {
                (yyval.grammerInfo) = new grammer_info("statement: WHILE LPAREN expression RPAREN statement","while("+(yyvsp[-3].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text);
                
                writeCode("JMP "+Lbegin.top());
                writeCode(Lend.top()+":","end while loop");
                Lbegin.pop();
                Lend.pop();

                free((yyvsp[-3].grammerInfo)); free((yyvsp[0].grammerInfo));
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2520 "y.tab.c"
    break;

  case 50: /* statement: PRINTLN LPAREN variable RPAREN SEMICOLON  */
#line 662 "parser.y"
                                                      {
                (yyval.grammerInfo) = new grammer_info("statement: PRINTLN LPAREN ID RPAREN SEMICOLON","printf("+(yyvsp[-2].grammerInfo)->text+");");


                //code
                writeCode("MOV AX, [BP+"+(yyvsp[-2].grammerInfo)->value+"]");
                writeCode("CALL PRINT") ; 
                //end 

                free((yyvsp[-2].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
            }
#line 2538 "y.tab.c"
    break;

  case 51: /* statement: RETURN expression SEMICOLON  */
#line 675 "parser.y"
                                         {
                (yyval.grammerInfo) = new grammer_info("statement: RETURN expression SEMICOLON","return "+(yyvsp[-1].grammerInfo)->text+";");
                if( currentFunction == nullptr )
                    writeError("return statement without any function");
                else if( currentFunction->getType() != (yyvsp[-1].grammerInfo)->type ){
                    if( (currentFunction->getType() == _int_ && (yyvsp[-1].grammerInfo)->type == _float_) || (currentFunction->getType() ==_float_&& (yyvsp[-1].grammerInfo)->type==_int_) ){
                    }
                    else {
                        writeError("return expression type donot match with function definition , defined "+currentFunction->getType()+" ,returned "+(yyvsp[-1].grammerInfo)->type);
                    }
                    
                }
                free((yyvsp[-1].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2559 "y.tab.c"
    break;

  case 52: /* statement: error SEMICOLON  */
#line 691 "parser.y"
                              {
                // yyerror("syntax error, invalid statement");

                yyerrok;
                (yyval.grammerInfo) = new grammer_info("statement: error");
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2571 "y.tab.c"
    break;

  case 53: /* expression_statement: SEMICOLON  */
#line 700 "parser.y"
                                {
                        (yyval.grammerInfo) = new grammer_info("expression_statement: SEMICOLON",";");
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);

                    }
#line 2581 "y.tab.c"
    break;

  case 54: /* expression_statement: expression SEMICOLON  */
#line 705 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info("expression_statement: expression SEMICOLON",(yyvsp[-1].grammerInfo)->text+";");
                        
                        //code 
                        writeCode("POP AX");
                        writeCode("PUSHF");
                        while( !pendingCode.empty() ){
                            writeCode(pendingCode.front()) ;
                            pendingCode.pop();
                        }
                        while( removeTempCount ){
                            removeTemp();
                            removeTempCount-- ;
                        }
                        writeCode("POPF");
                        //end 
                        free((yyvsp[-1].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2606 "y.tab.c"
    break;

  case 55: /* expression: logic_expression  */
#line 726 "parser.y"
                             {
                (yyval.grammerInfo) = new grammer_info("expression: logic_expression",(yyvsp[0].grammerInfo)->text);
                (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type;
                free((yyvsp[0].grammerInfo));

                //code
                // writeCode("POP AX\n");
                //end 
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2621 "y.tab.c"
    break;

  case 56: /* $@12: %empty  */
#line 736 "parser.y"
                       {
                //code 
                if( (yyvsp[0].grammerInfo)->array == true ){
                    writeCode("PUSH SI","saving the address SI") ;
                }
                //
            }
#line 2633 "y.tab.c"
    break;

  case 57: /* expression: variable $@12 ASSIGNOP logic_expression  */
#line 742 "parser.y"
                                        {
                (yyval.grammerInfo) = new grammer_info("expression: variable ASSIGNOP logic_expression",(yyvsp[-3].grammerInfo)->text+"="+(yyvsp[0].grammerInfo)->text);
                if( (yyvsp[-3].grammerInfo)->type != (yyvsp[0].grammerInfo)->type ){
                    if( ((yyvsp[-3].grammerInfo)->type == _int_ && (yyvsp[0].grammerInfo)->type == _float_) || ((yyvsp[-3].grammerInfo)->type==_float_&& (yyvsp[0].grammerInfo)->type==_int_) ){
                        (yyval.grammerInfo)->type = (yyvsp[-3].grammerInfo)->type; // type conversion 
                    }
                    else {
                        writeError((yyvsp[-1].symbolInfo)->getName()+" operator ,"+"type mismatch "+(yyvsp[-3].grammerInfo)->type+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->type);
                        (yyval.grammerInfo)->type = _unknown_;
                    }
                }
                //code
                // writeCode("MOV AX, [SP]\n");
                writeCode("POP AX");
                if((yyvsp[-3].grammerInfo)->array == true )
                    writeCode("POP SI","retrieving the address SI"); 
                writeCode("MOV [BP+"+(yyvsp[-3].grammerInfo)->value+"], AX"); 
                writeCode("PUSH AX");
                //end 

                free((yyvsp[-3].grammerInfo)); free((yyvsp[0].grammerInfo)); free((yyvsp[-1].symbolInfo));
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2661 "y.tab.c"
    break;

  case 58: /* variable: ID  */
#line 766 "parser.y"
               {
                (yyval.grammerInfo) = new grammer_info((yyvsp[0].symbolInfo)->getName());
                symbol* foundSymbol = symbolTable->lookup((yyvsp[0].symbolInfo)->getName());
                if( foundSymbol == nullptr ){
                    writeError("variable "+(yyvsp[0].symbolInfo)->to_string()+" not declared");
                    (yyval.grammerInfo)->type = _unknown_;
                }
                else {
                    (yyval.grammerInfo)->type = foundSymbol->isArray()?_unknown_:foundSymbol->getType();
                }

                if( foundSymbol != nullptr ){
                    // writeCode("MOV DX, "+foundSymbol->getValue()+"\n");
                    // comment("load variable: "+foundSymbol->getName()) ;
                    (yyval.grammerInfo)->value = ""+foundSymbol->getValue();
                    (yyval.grammerInfo)->array = false ;
                }

                free((yyvsp[0].symbolInfo));

                writeLog("variable: ID",(yyval.grammerInfo)->text);
            }
#line 2688 "y.tab.c"
    break;

  case 59: /* variable: ID LTHIRD expression RTHIRD  */
#line 788 "parser.y"
                                          {
                (yyval.grammerInfo) = new grammer_info("variable: ID LTHIRD expression RTHIRD",(yyvsp[-3].symbolInfo)->getName()+"["+(yyvsp[-1].grammerInfo)->text+"]");
                symbol* foundSymbol = symbolTable->lookup((yyvsp[-3].symbolInfo)->getName());

                bool ok = 0;
                if( foundSymbol == nullptr ){
                    writeError("variable "+(yyvsp[-3].symbolInfo)->to_string()+" not declared");
                    (yyval.grammerInfo)->type = _unknown_;
                }
                else if( !foundSymbol->isArray() ) {
                    writeError("variable "+(yyvsp[-3].symbolInfo)->to_string()+" not an array");
                    (yyval.grammerInfo)->type = _unknown_;
                }
                else  {
                    (yyval.grammerInfo)->type = foundSymbol->getType();
                    (yyval.grammerInfo)->array = true; 
                    ok = 1; 
                }

                if( (yyvsp[-1].grammerInfo)->type != _int_ ){
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
                    (yyval.grammerInfo)->value = "SI";
                }
                //end 
                free((yyvsp[-3].symbolInfo)); free((yyvsp[-1].grammerInfo));
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2731 "y.tab.c"
    break;

  case 60: /* logic_expression: rel_expression  */
#line 827 "parser.y"
                                   {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->name = "logic_expression: rel_expression";
                        
                        //code 
                        //end 

                        free((yyvsp[0].grammerInfo));
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2746 "y.tab.c"
    break;

  case 61: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 837 "parser.y"
                                                                    {
                        (yyval.grammerInfo) = new grammer_info("logic_expression: rel_expression LOGICOP rel_expression",(yyvsp[-2].grammerInfo)->text+" "+(yyvsp[-1].symbolInfo)->getName()+" "+(yyvsp[0].grammerInfo)->text);
                        if( (yyvsp[-2].grammerInfo)->type != _int_ || (yyvsp[0].grammerInfo)->type != _int_ )
                            writeError("operands of LOGICOP must be integers");    
                        (yyval.grammerInfo)->type = _int_;

                        //code
                        writeCode("POP BX");
                        writeCode("POP AX"); 
                        if( (yyvsp[-1].symbolInfo)->getName() == "&&" ){
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
                        else if( (yyvsp[-1].symbolInfo)->getName() == "||") {
                             string L1 = newLabel(), L2 = newLabel() ;
                            writeCode("CMP AX, 0");
                            writeCode("JNE "+L1);
                            writeCode("CMP BX, 0");
                            writeCode("JNE "+L1);
                            writeCode("PUSH 0");
                            writeCode("JMP "+L2);
                            writeCode(L1+":");
                            writeCode("PUSH 1");
                            writeCode(L2+":");
                        }
                        //end  

                        free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text); }
#line 2788 "y.tab.c"
    break;

  case 62: /* rel_expression: simple_expression  */
#line 875 "parser.y"
                                      {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->name = "rel_expression: simple_expression";

                        //code 
                        //end 

                        free((yyvsp[0].grammerInfo));
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2803 "y.tab.c"
    break;

  case 63: /* rel_expression: simple_expression RELOP simple_expression  */
#line 885 "parser.y"
                                                                        {
                        (yyval.grammerInfo) = new grammer_info("rel_expression: simple_expression RELOP simple_expression",(yyvsp[-2].grammerInfo)->text+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = _int_;
                        (yyval.grammerInfo)->value = (yyvsp[-1].symbolInfo)->getName();
                        // code
                        writeCode("POP BX");
                        writeCode("POP AX") ;
                        writeCode("CMP AX,BX");
                        string L1 = newLabel(), L2= newLabel() ;
                        
                        if( (yyvsp[-1].symbolInfo)->getName() == ">" ){
                            writeCode("JG "+L1);
                        }
                        else if((yyvsp[-1].symbolInfo)->getName() == ">=" ){
                            writeCode("JGE "+L1);
                        }
                        else if( (yyvsp[-1].symbolInfo)->getName() == "<") {
                            writeCode("JL "+L1);
                        }
                        else if( (yyvsp[-1].symbolInfo)->getName() == "<=") {
                            writeCode("JLE "+L1);
                        }
                        else if( (yyvsp[-1].symbolInfo)->getName() == "==") {
                            writeCode("JE "+L1);
                        }
                        else if( (yyvsp[-1].symbolInfo)->getName() == "!=") {
                            writeCode("JNE "+L1);
                        }
                        writeCode("PUSH 0");
                        writeCode("JMP "+L2);
                        writeCode(L1+":");
                        writeCode("PUSH 1") ;
                        writeCode(L2+":");
                        // end 

                        free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2846 "y.tab.c"
    break;

  case 64: /* simple_expression: term  */
#line 924 "parser.y"
                         {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->name = "simple_expression: term"; 
                       
                        //code  
                        //end 

                        free((yyvsp[0].grammerInfo));
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2861 "y.tab.c"
    break;

  case 65: /* simple_expression: simple_expression ADDOP term  */
#line 934 "parser.y"
                                                           {
                        (yyval.grammerInfo) = new grammer_info("simple_expression: simple_expression ADDOP term",(yyvsp[-2].grammerInfo)->text+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        if( (yyvsp[-2].grammerInfo)->type != (yyvsp[0].grammerInfo)->type ){
                            if( ((yyvsp[-2].grammerInfo)->type == _int_ && (yyvsp[0].grammerInfo)->type == _float_) || ((yyvsp[-2].grammerInfo)->type==_float_&&(yyvsp[0].grammerInfo)->type==_int_) ){
                                (yyval.grammerInfo)->type = _float_;
                            }
                            else {
                                writeError((yyvsp[-1].symbolInfo)->getName()+" operator ,"+"type mismatch "+(yyvsp[-2].grammerInfo)->type+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->type);
                                (yyval.grammerInfo)->type = _unknown_;
                            }
                        }
                        else (yyval.grammerInfo)->type=(yyvsp[-2].grammerInfo)->type ;

                        //code
                        writeCode("POP AX");
                        writeCode("POP BX"); 
                        if( (yyvsp[-1].symbolInfo)->getName() == "+") {
                            writeCode("ADD BX, AX");
                        }
                        else writeCode("SUB BX, AX");
                        writeCode("PUSH BX") ;
                        //end 

                        free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2893 "y.tab.c"
    break;

  case 66: /* term: unary_expression  */
#line 962 "parser.y"
                         {
            (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
            (yyval.grammerInfo)->name = "term: unary_expression";
            free((yyvsp[0].grammerInfo));
            // code 
            writeCode("PUSH CX");
            //end
            
            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 2908 "y.tab.c"
    break;

  case 67: /* term: term MULOP unary_expression  */
#line 972 "parser.y"
                                     {
            (yyval.grammerInfo) = new grammer_info("term: term MULOP unary_expression",(yyvsp[-2].grammerInfo)->text+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
            if( (yyvsp[-1].symbolInfo)->getName() == "%" ){
                if((yyvsp[-2].grammerInfo)->type != _int_ || (yyvsp[0].grammerInfo)->type != _int_ )  
                    writeError("operands of modulo not integer");
                // modulo 0 error ?? 
            }
            if( (yyvsp[-2].grammerInfo)->type != (yyvsp[0].grammerInfo)->type ){
                if( ((yyvsp[-2].grammerInfo)->type == _int_ && (yyvsp[0].grammerInfo)->type == _float_) || ((yyvsp[-2].grammerInfo)->type==_float_&&(yyvsp[0].grammerInfo)->type==_int_) ){
                    (yyval.grammerInfo)->type = _float_;
                }
                else {
                    writeError((yyvsp[-1].symbolInfo)->getName()+" operator ,"+"type mismatch "+(yyvsp[-2].grammerInfo)->type+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->type);
                    (yyval.grammerInfo)->type = _unknown_;
                }
            }
            else (yyval.grammerInfo)->type = (yyvsp[-2].grammerInfo)->type ;

            //code 
            writeCode("POP AX") ;
            if( (yyvsp[-1].symbolInfo)->getName() == "*"){
                writeCode("MUL CX");
                writeCode("PUSH AX");
            }
            else if( (yyvsp[-1].symbolInfo)->getName() == "/"){
                writeCode("MOV DX, 0", "to avoid overflow error");
                writeCode("DIV CX");
                writeCode("PUSH AX");
            }
            else if( (yyvsp[-1].symbolInfo)->getName()=="%") {
                writeCode("MOV DX, 0", "to avoid overflow error");
                writeCode("DIV CX") ;
                writeCode("PUSH DX") ;
            }
            //end 

            free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text); 
        }
#line 2953 "y.tab.c"
    break;

  case 68: /* unary_expression: ADDOP unary_expression  */
#line 1013 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->text = string((yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->name = "unary_expression: ADDOP unary_expression";
                        
                        //code 
                        if((yyvsp[-1].symbolInfo)->getName() == "-") 
                            writeCode("NEG CX");
                        //end code ;
                        
                        free((yyvsp[-1].symbolInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2972 "y.tab.c"
    break;

  case 69: /* unary_expression: NOT unary_expression  */
#line 1027 "parser.y"
                                                  {
                        (yyval.grammerInfo) = new grammer_info("unary_expression: NOT unary_expression",(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = _int_;
                        //code 
                        writeCode("NOT CX");
                        writeCode("AND CX, 1");
                        //end code ;
                        
                        
                        free((yyvsp[-1].symbolInfo)); free((yyvsp[0].grammerInfo));
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2989 "y.tab.c"
    break;

  case 70: /* unary_expression: factor  */
#line 1039 "parser.y"
                                     {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->name = "unary_expression: factor"; 
                        
                        
                        free((yyvsp[0].grammerInfo));
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 3002 "y.tab.c"
    break;

  case 71: /* factor: variable  */
#line 1049 "parser.y"
                 {
            (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
            (yyval.grammerInfo)->name = "factor: variable"; 
            
            // code 
            writeCode("MOV CX,[BP+"+(yyvsp[0].grammerInfo)->value+"]");
            // end code 
            
            free((yyvsp[0].grammerInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3019 "y.tab.c"
    break;

  case 72: /* factor: ID LPAREN argument_list RPAREN  */
#line 1061 "parser.y"
                                             {
            (yyval.grammerInfo) = new grammer_info("factor: ID LPAREN argument_list RPAREN",(yyvsp[-3].symbolInfo)->getName()+"("+(yyvsp[-1].grammerInfo)->text+")");
            symbol* foundSymbol = symbolTable->lookup((yyvsp[-3].symbolInfo)->getName());
           
            bool ok = 0;
            if( foundSymbol == nullptr ){
                writeError("identifier "+(yyvsp[-3].symbolInfo)->to_string()+" not declared.");
            }
            else if( !foundSymbol->isFunction() )
                writeError("identifier "+(yyvsp[-3].symbolInfo)->to_string()+" is not a function.");
            else if( foundSymbol->getParams().size() != (yyvsp[-1].grammerInfo)->ids.size() ){
                writeError("identifier "+(yyvsp[-3].symbolInfo)->to_string()+" doesn't match with the definition, number of args.");
            }  
            else {
                int i ;
                for(i=0;i<foundSymbol->getParams().size();i++)
                    if( foundSymbol->getParams()[i].type != (yyvsp[-1].grammerInfo)->ids[i].type){ //(foundSymbol->getParams()[i].array_size>0) != ($3->ids[i].array_size>0) 
                        writeError( to_string(i+1)+"th argument type doesn't match with definition, defined "+foundSymbol->getParams()[i].type+", called by "+(yyvsp[-1].grammerInfo)->ids[i].type);
                    }    
                if( i == foundSymbol->getParams().size() )
                    ok = 1;    
            }
            (yyval.grammerInfo)->type = ok?foundSymbol->getType():_unknown_;
            
            //code 
            if( ok ) {
                // writeCode("CALL "+found)
            }
            //endcode 
            
            free((yyvsp[-3].symbolInfo)); free((yyvsp[-1].grammerInfo)); 

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3058 "y.tab.c"
    break;

  case 73: /* factor: LPAREN expression RPAREN  */
#line 1095 "parser.y"
                                       {
            (yyval.grammerInfo) = new grammer_info("factor: LPAREN expression RPAREN","("+(yyvsp[-1].grammerInfo)->text+")");
            (yyval.grammerInfo)->type = (yyvsp[-1].grammerInfo)->type;
            
            //code 
            writeCode("POP CX");
            //
            
            free((yyvsp[-1].grammerInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3075 "y.tab.c"
    break;

  case 74: /* factor: CONST_INT  */
#line 1107 "parser.y"
                        {
            (yyval.grammerInfo) = new grammer_info("factor: CONST_INT",(yyvsp[0].symbolInfo)->getName());
            (yyval.grammerInfo)->type = _int_;

            //code 
            writeCode("MOV CX, "+(yyvsp[0].symbolInfo)->getName()) ;
            // end code ;
            free((yyvsp[0].symbolInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
        }
#line 3091 "y.tab.c"
    break;

  case 75: /* factor: CONST_FLOAT  */
#line 1118 "parser.y"
                          {
            (yyval.grammerInfo) = new grammer_info("factor: CONST_FLOAT",(yyvsp[0].symbolInfo)->getName());
            (yyval.grammerInfo)->type = _float_;
            free((yyvsp[0].symbolInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3103 "y.tab.c"
    break;

  case 76: /* factor: variable INCOP  */
#line 1125 "parser.y"
                             {
            (yyval.grammerInfo) = new grammer_info("factor: variable INCOP",(yyvsp[-1].grammerInfo)->text+"++");
            (yyval.grammerInfo)->type = (yyvsp[-1].grammerInfo)->type ;
            
            //code 
            writeCode("MOV CX,[BP+"+(yyvsp[-1].grammerInfo)->value+"]");
            string t1 = newTemp() ;
            writeCode("MOV "+t1+", "+(yyvsp[-1].grammerInfo)->value);
            pendingCode.push(string("MOV SI, "+t1));
            pendingCode.push(string("INC WORD [BP+SI]"));
            removeTempCount++;
            //end 
            
            free((yyvsp[-1].grammerInfo));
            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3124 "y.tab.c"
    break;

  case 77: /* factor: variable DECOP  */
#line 1141 "parser.y"
                             {
            (yyval.grammerInfo) = new grammer_info("factor: variable DECOP",(yyvsp[-1].grammerInfo)->text+"--");
            (yyval.grammerInfo)->type = (yyvsp[-1].grammerInfo)->type ;
            
            //code 
            writeCode("MOV CX,[BP+"+(yyvsp[-1].grammerInfo)->value+"]");
            string t1 = newTemp() ;
            writeCode("MOV "+t1+", "+(yyvsp[-1].grammerInfo)->value);
            pendingCode.push(string("MOV SI, "+t1));
            pendingCode.push(string("DEC WORD [BP+SI]"));
            removeTempCount++;
            //end 
            
            
            free((yyvsp[-1].grammerInfo));
            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3146 "y.tab.c"
    break;

  case 78: /* argument_list: arguments  */
#line 1160 "parser.y"
                          {
                    (yyval.grammerInfo) = new grammer_info("argument_list: arguments",(yyvsp[0].grammerInfo)->text);
                    (yyval.grammerInfo)->ids = (yyvsp[0].grammerInfo)->ids;
                    free((yyvsp[0].grammerInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 3158 "y.tab.c"
    break;

  case 79: /* arguments: arguments COMMA logic_expression  */
#line 1169 "parser.y"
                                             {
                (yyval.grammerInfo) = new grammer_info("arguments: arguments COMMA logic_expression",(yyvsp[-2].grammerInfo)->text+","+(yyvsp[0].grammerInfo)->text);
                (yyval.grammerInfo)->ids = (yyvsp[-2].grammerInfo)->ids;
                (yyval.grammerInfo)->ids.push_back({"arg",(yyvsp[0].grammerInfo)->type,(yyvsp[0].grammerInfo)->array?1:-1});
                free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 3171 "y.tab.c"
    break;

  case 80: /* arguments: logic_expression  */
#line 1177 "parser.y"
                                  {
                (yyval.grammerInfo) = new grammer_info("arguments: logic_expression",(yyvsp[0].grammerInfo)->text);
                (yyval.grammerInfo)->ids.push_back({"argument",(yyvsp[0].grammerInfo)->type,(yyvsp[0].grammerInfo)->array?1:-1});
                free((yyvsp[0].grammerInfo));
                
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 3183 "y.tab.c"
    break;


#line 3187 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1186 "parser.y"


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
