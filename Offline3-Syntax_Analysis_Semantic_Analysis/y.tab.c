/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "parser.y"

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
    printf("Error at Line %d: %s",line_count, s);
    return ;
}

#define writeLog(grammer,text) logfile<<"Line "<<line_count<<": "<<grammer<<"\n\n"<<text<<"\n"<<endl;

void writeError(string s){
    errorfile<<"Error at Line "<<line_count<<": "<<s<<endl;
    logfile<<"Error at Line "<<line_count<<": "<<s<<endl;
}


#line 106 "y.tab.c"

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
/* "%code requires" blocks.  */
#line 1 "parser.y"

    #include <bits/stdc++.h>

#line 145 "y.tab.c"

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
#line 41 "parser.y"

    symbol* symbolInfo;
    grammer_info* grammerInfo;

#line 258 "y.tab.c"

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
  YYSYMBOL_compound_statement = 55,        /* compound_statement  */
  YYSYMBOL_statements = 56,                /* statements  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_expression_statement = 58,      /* expression_statement  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_variable = 60,                  /* variable  */
  YYSYMBOL_logic_expression = 61,          /* logic_expression  */
  YYSYMBOL_rel_expression = 62,            /* rel_expression  */
  YYSYMBOL_simple_expression = 63,         /* simple_expression  */
  YYSYMBOL_term = 64,                      /* term  */
  YYSYMBOL_unary_expression = 65,          /* unary_expression  */
  YYSYMBOL_factor = 66,                    /* factor  */
  YYSYMBOL_argument_list = 67,             /* argument_list  */
  YYSYMBOL_arguments = 68                  /* arguments  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 63 "parser.y"

int getTypeValue(string &s){
    if( s == "int" )    return INT;
    else if( s == "float")  return FLOAT;
    else if( s == "void")   return VOID;
    else if( s == "int_array")  return INT_ARRAY;
    else if( s == "float_array")    return FLOAT_ARRAY;

    return UNKNOWN;
}

#line 364 "y.tab.c"


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
typedef yytype_int8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

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
       0,    76,    76,    82,    86,    92,    95,    98,   102,   108,
     114,   118,   123,   127,   131,   135,   141,   145,   150,   154,
     158,   162,   168,   172,   177,   181,   186,   190,   195,   199,
     203,   207,   211,   215,   219,   223,   227,   233,   237,   242,
     249,   260,   274,   289,   296,   306,   313,   321,   328,   338,
     345,   355,   362,   369,   378,   385,   389,   393,   397,   401,
     405,   411,   417,   421
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
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
  "func_definition", "compound_statement", "statements", "statement",
  "expression_statement", "expression", "variable", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-57)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,   -57,   -57,   -57,     1,    74,   -57,   -57,    -6,   -57,
     -57,   -57,   -57,    -4,    80,     4,    20,    53,   -57,   -10,
      55,    18,    51,    71,    58,   -57,   -57,   -57,    -5,    74,
     -57,    98,    89,    91,    92,   119,   -57,   119,   -57,   119,
     119,    35,   -57,   -57,    96,   -57,    66,   -57,    95,   -57,
     -57,    93,    57,   -57,    85,    49,    97,   -57,   -57,   -57,
     -57,    88,    83,   119,   110,   119,   100,   102,    79,   -57,
     -57,   119,   119,   103,   104,   -57,   -57,   -57,   -57,   -57,
     119,   119,   119,   119,   119,   -57,   111,   106,   110,   117,
     -57,   -57,   -57,   120,   116,   125,   121,   -57,   -57,    97,
     123,   -57,   -57,    15,   119,    15,   -57,   119,   -57,   126,
     147,   133,   -57,   -57,   -57,    15,    15,   -57,   -57
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,    11,     0,     2,     4,     5,     0,     6,
       7,     1,     3,    15,     0,     0,     0,     0,     8,     0,
      21,     0,     0,    13,     0,    17,    23,    20,     0,     0,
      14,     0,     0,     0,     0,     0,    25,     0,    37,     0,
       0,    41,    57,    58,     0,    28,     0,    30,     0,    27,
      29,     0,    54,    39,    43,    45,    47,    49,    53,    16,
      22,    19,     0,     0,     0,     0,     0,     0,    54,    51,
      52,     0,     0,     0,    15,    24,    26,    38,    59,    60,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
      36,    56,    63,     0,    61,     0,     0,    40,    44,    48,
      46,    50,    12,     0,     0,     0,    55,     0,    42,     0,
      33,     0,    34,    62,    35,     0,     0,    32,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   153,    33,    10,   -57,   -57,   -57,   -57,
      40,   -57,   -43,   -56,   -35,   -36,   -16,    78,    77,    81,
     -33,   -57,   -57,   -57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    45,    46,    14,     9,    21,    10,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    93,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      66,    11,    67,    68,    68,    76,    69,    70,    88,    24,
       8,     1,     2,     3,    24,     8,    25,    15,    32,    16,
      33,    59,     1,     2,     3,    20,    19,    34,    87,    13,
      89,    35,   104,     7,    24,    68,    37,    95,     7,    61,
      28,    38,    39,    29,    68,    68,    68,    68,    68,    40,
      41,   101,    42,    43,    44,    92,    71,    22,    72,    26,
     110,    32,   112,    33,    97,     1,     2,     3,    60,   111,
      34,    68,   117,   118,    35,    30,    82,    24,    36,    37,
      83,     1,     2,     3,    38,    39,    78,    79,    23,    80,
      27,   113,    40,    41,    31,    42,    43,    44,    32,    62,
      33,    74,     1,     2,     3,    17,    18,    34,    78,    79,
      63,    35,    64,    65,    24,    75,    37,    73,    81,    77,
      86,    38,    39,    85,    91,    84,    90,    16,   103,    40,
      41,    37,    42,    43,    44,   102,    38,    39,    96,   105,
      37,   107,   106,   109,    40,    41,    39,    42,    43,   108,
      82,   115,   114,    40,    41,   116,    42,    43,    12,    98,
     100,     0,     0,    99
};

static const yytype_int8 yycheck[] =
{
      35,     0,    37,    39,    40,    48,    39,    40,    64,    19,
       0,     7,     8,     9,    19,     5,    26,    21,     3,    23,
       5,    26,     7,     8,     9,    15,    22,    12,    63,    35,
      65,    16,    88,     0,    19,    71,    21,    72,     5,    29,
      22,    26,    27,    25,    80,    81,    82,    83,    84,    34,
      35,    84,    37,    38,    39,    71,    21,    37,    23,    19,
     103,     3,   105,     5,    80,     7,     8,     9,    28,   104,
      12,   107,   115,   116,    16,    24,    27,    19,    20,    21,
      31,     7,     8,     9,    26,    27,    29,    30,    35,    32,
      35,   107,    34,    35,    23,    37,    38,    39,     3,     1,
       5,    35,     7,     8,     9,    25,    26,    12,    29,    30,
      21,    16,    21,    21,    19,    20,    21,    21,    33,    26,
      37,    26,    27,    35,    22,    28,    26,    23,    22,    34,
      35,    21,    37,    38,    39,    24,    26,    27,    35,    22,
      21,    25,    22,    22,    34,    35,    27,    37,    38,    24,
      27,     4,    26,    34,    35,    22,    37,    38,     5,    81,
      83,    -1,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    46,    47,    48,    49,    50,    52,
      54,     0,    48,    35,    51,    21,    23,    25,    26,    22,
      50,    53,    37,    35,    19,    26,    55,    35,    22,    25,
      24,    23,     3,     5,    12,    16,    20,    21,    26,    27,
      34,    35,    37,    38,    39,    49,    50,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    26,
      55,    50,     1,    21,    21,    21,    59,    59,    60,    65,
      65,    21,    23,    21,    35,    20,    57,    26,    29,    30,
      32,    33,    27,    31,    28,    35,    37,    59,    58,    59,
      26,    22,    61,    67,    68,    59,    35,    61,    62,    64,
      63,    65,    24,    22,    58,    22,    22,    25,    24,    22,
      57,    59,    57,    61,    26,     4,    22,    57,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    50,
      50,    50,    51,    51,    51,    51,    52,    52,    53,    53,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    66,    66,
      66,    67,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     7,     3,     4,     1,     6,     5,     4,     3,
       2,     1,     6,     5,     3,     2,     2,     1,     1,     1,
       1,     7,     7,     5,     5,     5,     3,     1,     2,     1,
       3,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     1,     1,     4,     3,     1,     1,     2,
       2,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  switch (yykind)
    {
    case YYSYMBOL_IF: /* IF  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1147 "y.tab.c"
        break;

    case YYSYMBOL_ELSE: /* ELSE  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1153 "y.tab.c"
        break;

    case YYSYMBOL_FOR: /* FOR  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1159 "y.tab.c"
        break;

    case YYSYMBOL_DO: /* DO  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1165 "y.tab.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1171 "y.tab.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1177 "y.tab.c"
        break;

    case YYSYMBOL_VOID: /* VOID  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1183 "y.tab.c"
        break;

    case YYSYMBOL_SWITCH: /* SWITCH  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1189 "y.tab.c"
        break;

    case YYSYMBOL_DEFAULT: /* DEFAULT  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1195 "y.tab.c"
        break;

    case YYSYMBOL_WHILE: /* WHILE  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1201 "y.tab.c"
        break;

    case YYSYMBOL_BREAK: /* BREAK  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1207 "y.tab.c"
        break;

    case YYSYMBOL_CHAR: /* CHAR  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1213 "y.tab.c"
        break;

    case YYSYMBOL_DOUBLE: /* DOUBLE  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1219 "y.tab.c"
        break;

    case YYSYMBOL_RETURN: /* RETURN  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1225 "y.tab.c"
        break;

    case YYSYMBOL_CASE: /* CASE  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1231 "y.tab.c"
        break;

    case YYSYMBOL_CONTINUE: /* CONTINUE  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1237 "y.tab.c"
        break;

    case YYSYMBOL_LCURL: /* LCURL  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1243 "y.tab.c"
        break;

    case YYSYMBOL_RCURL: /* RCURL  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1249 "y.tab.c"
        break;

    case YYSYMBOL_LPAREN: /* LPAREN  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1255 "y.tab.c"
        break;

    case YYSYMBOL_RPAREN: /* RPAREN  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1261 "y.tab.c"
        break;

    case YYSYMBOL_LTHIRD: /* LTHIRD  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1267 "y.tab.c"
        break;

    case YYSYMBOL_RTHIRD: /* RTHIRD  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1273 "y.tab.c"
        break;

    case YYSYMBOL_COMMA: /* COMMA  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1279 "y.tab.c"
        break;

    case YYSYMBOL_SEMICOLON: /* SEMICOLON  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1285 "y.tab.c"
        break;

    case YYSYMBOL_ADDOP: /* ADDOP  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1291 "y.tab.c"
        break;

    case YYSYMBOL_MULOP: /* MULOP  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1297 "y.tab.c"
        break;

    case YYSYMBOL_INCOP: /* INCOP  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1303 "y.tab.c"
        break;

    case YYSYMBOL_DECOP: /* DECOP  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1309 "y.tab.c"
        break;

    case YYSYMBOL_RELOP: /* RELOP  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1315 "y.tab.c"
        break;

    case YYSYMBOL_ASSIGNOP: /* ASSIGNOP  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1321 "y.tab.c"
        break;

    case YYSYMBOL_LOGICOP: /* LOGICOP  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1327 "y.tab.c"
        break;

    case YYSYMBOL_NOT: /* NOT  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1333 "y.tab.c"
        break;

    case YYSYMBOL_ID: /* ID  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1339 "y.tab.c"
        break;

    case YYSYMBOL_CONST_CHAR: /* CONST_CHAR  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1345 "y.tab.c"
        break;

    case YYSYMBOL_CONST_INT: /* CONST_INT  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1351 "y.tab.c"
        break;

    case YYSYMBOL_CONST_FLOAT: /* CONST_FLOAT  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1357 "y.tab.c"
        break;

    case YYSYMBOL_PRINTLN: /* PRINTLN  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1363 "y.tab.c"
        break;

    case YYSYMBOL_MAIN: /* MAIN  */
#line 45 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1369 "y.tab.c"
        break;

    case YYSYMBOL_start: /* start  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1375 "y.tab.c"
        break;

    case YYSYMBOL_program: /* program  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1381 "y.tab.c"
        break;

    case YYSYMBOL_unit: /* unit  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1387 "y.tab.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1393 "y.tab.c"
        break;

    case YYSYMBOL_type_specifier: /* type_specifier  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1399 "y.tab.c"
        break;

    case YYSYMBOL_declaration_list: /* declaration_list  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1405 "y.tab.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1411 "y.tab.c"
        break;

    case YYSYMBOL_parameter_list: /* parameter_list  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1417 "y.tab.c"
        break;

    case YYSYMBOL_func_definition: /* func_definition  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1423 "y.tab.c"
        break;

    case YYSYMBOL_compound_statement: /* compound_statement  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1429 "y.tab.c"
        break;

    case YYSYMBOL_statements: /* statements  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1435 "y.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1441 "y.tab.c"
        break;

    case YYSYMBOL_expression_statement: /* expression_statement  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1447 "y.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1453 "y.tab.c"
        break;

    case YYSYMBOL_variable: /* variable  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1459 "y.tab.c"
        break;

    case YYSYMBOL_logic_expression: /* logic_expression  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1465 "y.tab.c"
        break;

    case YYSYMBOL_rel_expression: /* rel_expression  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1471 "y.tab.c"
        break;

    case YYSYMBOL_simple_expression: /* simple_expression  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1477 "y.tab.c"
        break;

    case YYSYMBOL_term: /* term  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1483 "y.tab.c"
        break;

    case YYSYMBOL_unary_expression: /* unary_expression  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1489 "y.tab.c"
        break;

    case YYSYMBOL_factor: /* factor  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1495 "y.tab.c"
        break;

    case YYSYMBOL_argument_list: /* argument_list  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1501 "y.tab.c"
        break;

    case YYSYMBOL_arguments: /* arguments  */
#line 46 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1507 "y.tab.c"
        break;

      default:
        break;
    }
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
#line 76 "parser.y"
                {
            writeLog("start: program","");

            symbolTable->print_all_scope_table() ;
        }
#line 1781 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 82 "parser.y"
                      {
            (yyval.grammerInfo) = new grammer_info( string((yyvsp[-1].grammerInfo)->text+"\n"+(yyvsp[0].grammerInfo)->text) );
            writeLog("program: program unit",(yyval.grammerInfo)->text);
        }
#line 1790 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 86 "parser.y"
                   {
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            writeLog("program: unit",(yyval.grammerInfo)->text);
        }
#line 1799 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 92 "parser.y"
                        { 
            writeLog("unit: var_declaration",(yyval.grammerInfo)->text); 
        }
#line 1807 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 95 "parser.y"
                          {
            writeLog("unit: func_declaration",(yyval.grammerInfo)->text);
        }
#line 1815 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 98 "parser.y"
                         {
            writeLog("unit: func_definition",(yyval.grammerInfo)->text);
        }
#line 1823 "y.tab.c"
    break;

  case 8: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 102 "parser.y"
                                                           {
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[-2].grammerInfo)->text + " " + (yyvsp[-1].grammerInfo)->text + ";"));
                    writeLog("var_declaration: type_specifier declaration_list SEMICOLON",(yyval.grammerInfo)->text);
                }
#line 1832 "y.tab.c"
    break;

  case 9: /* type_specifier: INT  */
#line 108 "parser.y"
                    {
                    (yyval.grammerInfo) = new grammer_info(string("int"));
                    (yyval.grammerInfo)->text = "int";
                    (yyval.grammerInfo)->type = INT;
                    writeLog("type_specifier: INT",(yyval.grammerInfo)->text);
                }
#line 1843 "y.tab.c"
    break;

  case 10: /* type_specifier: FLOAT  */
#line 114 "parser.y"
                       {
                    (yyval.grammerInfo) = new grammer_info(string("float"));
                    writeLog("type_specifier: FLOAT",(yyval.grammerInfo)->text);
                }
#line 1852 "y.tab.c"
    break;

  case 11: /* type_specifier: VOID  */
#line 118 "parser.y"
                      {
                    (yyval.grammerInfo) = new grammer_info(string("void"));
                    writeLog("type_specifier: VOID",(yyval.grammerInfo)->text);
                }
#line 1861 "y.tab.c"
    break;

  case 12: /* declaration_list: declaration_list COMMA ID LTHIRD error CONST_INT RTHIRD  */
#line 123 "parser.y"
                                                                          {
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[-6].grammerInfo)->text + "," + (yyvsp[-4].symbolInfo)->getName() + "[" + (yyvsp[-1].symbolInfo)->getName() + "]"));
                    writeLog("declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD",(yyval.grammerInfo)->text);                
                }
#line 1870 "y.tab.c"
    break;

  case 13: /* declaration_list: declaration_list COMMA ID  */
#line 127 "parser.y"
                                           {
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[-2].grammerInfo)->text + "," + (yyvsp[0].symbolInfo)->getName()));
                    writeLog("declaration_list: declaration_list COMMA ID",(yyval.grammerInfo)->text);
                }
#line 1879 "y.tab.c"
    break;

  case 14: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 131 "parser.y"
                                             {
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[-3].symbolInfo)->getName() + "[" + (yyvsp[-1].symbolInfo)->getName() + "]"));
                    writeLog("declaration_list: ID LTHIRD CONST_INT RTHIRD",(yyval.grammerInfo)->text) ;
                }
#line 1888 "y.tab.c"
    break;

  case 15: /* declaration_list: ID  */
#line 135 "parser.y"
                     {
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].symbolInfo)->getName()));
                    writeLog("declaration_list: ID",(yyval.grammerInfo)->text);
                }
#line 1897 "y.tab.c"
    break;

  case 16: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 141 "parser.y"
                                                                           {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[-5].grammerInfo)->text+" "+(yyvsp[-4].symbolInfo)->getName()+"("+(yyvsp[-2].grammerInfo)->text+");");
                    writeLog("func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON",(yyval.grammerInfo)->text);
                }
#line 1906 "y.tab.c"
    break;

  case 17: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 145 "parser.y"
                                                            {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[-4].grammerInfo)->text+" "+(yyvsp[-3].symbolInfo)->getName()+"();");
                    writeLog("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",(yyval.grammerInfo)->text);  
                }
#line 1915 "y.tab.c"
    break;

  case 18: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 150 "parser.y"
                                                       {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[-3].grammerInfo)->text +"," + (yyvsp[-1].grammerInfo)->text + " " + (yyvsp[0].symbolInfo)->getName());
                    writeLog("parameter_list: parameter_list COMMA type_specifier ID",(yyval.grammerInfo)->text);
                }
#line 1924 "y.tab.c"
    break;

  case 19: /* parameter_list: parameter_list COMMA type_specifier  */
#line 154 "parser.y"
                                                      {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[-2].grammerInfo)->text +"," + (yyvsp[0].grammerInfo)->text);
                    writeLog("parameter_list: parameter_list COMMA type_specifier",(yyval.grammerInfo)->text);
                }
#line 1933 "y.tab.c"
    break;

  case 20: /* parameter_list: type_specifier ID  */
#line 158 "parser.y"
                                    {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[-1].grammerInfo)->text +" " + (yyvsp[0].symbolInfo)->getName());
                    writeLog("parameter_list: type_specifier ID",(yyval.grammerInfo)->text) ;
                }
#line 1942 "y.tab.c"
    break;

  case 21: /* parameter_list: type_specifier  */
#line 162 "parser.y"
                                 {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                    writeLog("parameter_list: type_specifier",(yyval.grammerInfo)->text) ;
                }
#line 1951 "y.tab.c"
    break;

  case 22: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement  */
#line 168 "parser.y"
                                                                                    {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[-5].grammerInfo)->text+" "+(yyvsp[-4].symbolInfo)->getName()+"("+(yyvsp[-2].grammerInfo)->text+")"+(yyvsp[0].grammerInfo)->text); 
                    writeLog("func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement",(yyval.grammerInfo)->text) ;
                }
#line 1960 "y.tab.c"
    break;

  case 23: /* func_definition: type_specifier ID LPAREN RPAREN compound_statement  */
#line 172 "parser.y"
                                                                     {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[-4].grammerInfo)->text+" "+(yyvsp[-3].symbolInfo)->getName()+"()"+(yyvsp[0].grammerInfo)->text); 
                    writeLog("func_definition: type_specifier ID LPAREN RPAREN compound_statement",(yyval.grammerInfo)->text);
                }
#line 1969 "y.tab.c"
    break;

  case 24: /* compound_statement: LCURL statements RCURL  */
#line 177 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info("{\n"+(yyvsp[-1].grammerInfo)->text+"\n}");
                        writeLog("compound_statement: LCURL statements RCURL",(yyval.grammerInfo)->text); 
                    }
#line 1978 "y.tab.c"
    break;

  case 25: /* compound_statement: LCURL RCURL  */
#line 181 "parser.y"
                                  {
                        (yyval.grammerInfo) = new grammer_info("{\n}");
                        writeLog("compound_statement: LCURL RCURL",(yyval.grammerInfo)->text);
                    }
#line 1987 "y.tab.c"
    break;

  case 26: /* statements: statements statement  */
#line 186 "parser.y"
                                 {
                (yyval.grammerInfo) = new grammer_info((yyvsp[-1].grammerInfo)->text+"\n"+(yyvsp[0].grammerInfo)->text);
                writeLog("statements: statements statement",(yyval.grammerInfo)->text);
            }
#line 1996 "y.tab.c"
    break;

  case 27: /* statements: statement  */
#line 190 "parser.y"
                       {
                (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                writeLog("statements: statement",(yyval.grammerInfo)->text);
            }
#line 2005 "y.tab.c"
    break;

  case 28: /* statement: var_declaration  */
#line 195 "parser.y"
                            {
                (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                writeLog("statement: var_declaration",(yyval.grammerInfo)->text);
            }
#line 2014 "y.tab.c"
    break;

  case 29: /* statement: expression_statement  */
#line 199 "parser.y"
                                  {
                (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                writeLog("statement: expression_statement",(yyval.grammerInfo)->text);
            }
#line 2023 "y.tab.c"
    break;

  case 30: /* statement: compound_statement  */
#line 203 "parser.y"
                                {
                (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                writeLog("statement: compound_statement",(yyval.grammerInfo)->text);
            }
#line 2032 "y.tab.c"
    break;

  case 31: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 207 "parser.y"
                                                                                              {
                (yyval.grammerInfo) = new grammer_info("for("+(yyvsp[-4].grammerInfo)->text+(yyvsp[-3].grammerInfo)->text+(yyvsp[-2].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text);
                writeLog("statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement",(yyval.grammerInfo)->text);  
            }
#line 2041 "y.tab.c"
    break;

  case 32: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 211 "parser.y"
                                                                  {
                (yyval.grammerInfo) = new grammer_info("if("+(yyvsp[-4].grammerInfo)->text+")\n"+(yyvsp[-2].grammerInfo)->text+"\nelse\n"+(yyvsp[0].grammerInfo)->text);
                writeLog("statement: IF LPAREN expression RPAREN statement ELSE statement",(yyval.grammerInfo)->text);
            }
#line 2050 "y.tab.c"
    break;

  case 33: /* statement: IF LPAREN expression RPAREN statement  */
#line 215 "parser.y"
                                                                         {
                (yyval.grammerInfo) = new grammer_info("if("+(yyvsp[-2].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text);
                writeLog("statement: IF LPAREN expression RPAREN statement",(yyval.grammerInfo)->text);
            }
#line 2059 "y.tab.c"
    break;

  case 34: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 219 "parser.y"
                                                      {
                (yyval.grammerInfo) = new grammer_info("while("+(yyvsp[-2].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text);
                writeLog("statement: WHILE LPAREN expression RPAREN statement",(yyval.grammerInfo)->text);
            }
#line 2068 "y.tab.c"
    break;

  case 35: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 223 "parser.y"
                                                {
                (yyval.grammerInfo) = new grammer_info("println("+(yyvsp[-2].symbolInfo)->getName()+");");
                writeLog("statement: PRINTLN LPAREN ID RPAREN SEMICOLON",(yyval.grammerInfo)->text);  
            }
#line 2077 "y.tab.c"
    break;

  case 36: /* statement: RETURN expression SEMICOLON  */
#line 227 "parser.y"
                                         {
                (yyval.grammerInfo) = new grammer_info("return "+(yyvsp[-1].grammerInfo)->text+";");
                writeLog("statement: RETURN expression SEMICOLON",(yyval.grammerInfo)->text);
            }
#line 2086 "y.tab.c"
    break;

  case 37: /* expression_statement: SEMICOLON  */
#line 233 "parser.y"
                                {
                        (yyval.grammerInfo) = new grammer_info(";");
                        writeLog("expression_statement: SEMICOLON",(yyval.grammerInfo)->text);
                    }
#line 2095 "y.tab.c"
    break;

  case 38: /* expression_statement: expression SEMICOLON  */
#line 237 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[-1].grammerInfo)->text+";");
                        writeLog("expression_statement: expression SEMICOLON",(yyval.grammerInfo)->text);
                    }
#line 2104 "y.tab.c"
    break;

  case 39: /* expression: logic_expression  */
#line 242 "parser.y"
                             {
                (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type;

                delete (yyvsp[0].grammerInfo);
                writeLog("expression: logic_expression",(yyval.grammerInfo)->text);
            }
#line 2116 "y.tab.c"
    break;

  case 40: /* expression: variable ASSIGNOP logic_expression  */
#line 249 "parser.y"
                                                 {
                (yyval.grammerInfo) = new grammer_info((yyvsp[-2].grammerInfo)->text+"="+(yyvsp[0].grammerInfo)->text);
                if( (yyvsp[-2].grammerInfo)->type != (yyvsp[0].grammerInfo)->type){
                    writeError("assignment operator, operand types do not match");
                }
                (yyval.grammerInfo)->type = (yyvsp[-2].grammerInfo)->type;    // type conversion 
                delete (yyvsp[-2].grammerInfo); delete (yyvsp[-1].symbolInfo); delete (yyvsp[0].grammerInfo);

                writeLog("expression: variable ASSIGNOP logic_expression",(yyval.grammerInfo)->text);
            }
#line 2131 "y.tab.c"
    break;

  case 41: /* variable: ID  */
#line 260 "parser.y"
               {
                (yyval.grammerInfo) = new grammer_info((yyvsp[0].symbolInfo)->getName());
                (yyval.grammerInfo)->type = getTypeValue((yyvsp[0].symbolInfo)->getType());
                symbol* foundSymbol = symbolTable->lookup((yyvsp[0].symbolInfo)->getName());
                if( foundSymbol == nullptr ){
                    writeError("symbol "+(yyvsp[0].symbolInfo)->to_string()+" not declared");
                }
                else if( foundSymbol->getType() != (yyvsp[0].symbolInfo)->getType() ){
                    writeError("symbol "+(yyvsp[0].symbolInfo)->to_string()+" doesn't match with declared symbol "+foundSymbol->to_string());
                }
                delete (yyvsp[0].symbolInfo);

                writeLog("variable: ID",(yyval.grammerInfo)->text);
            }
#line 2150 "y.tab.c"
    break;

  case 42: /* variable: ID LTHIRD expression RTHIRD  */
#line 274 "parser.y"
                                          {
                (yyval.grammerInfo) = new grammer_info((yyvsp[-3].symbolInfo)->getName()+"["+(yyvsp[-1].grammerInfo)->text+"]");
                symbol* foundSymbol = symbolTable->lookup((yyvsp[-3].symbolInfo)->getName());
                if( foundSymbol == nullptr )
                    writeError("symbol "+(yyvsp[-3].symbolInfo)->to_string()+" not declared");
                else if( foundSymbol->getType() != (yyvsp[-3].symbolInfo)->getType() )
                    writeError("symbol "+(yyvsp[-3].symbolInfo)->to_string()+" doesn't match with declared symbol "+foundSymbol->to_string());
                if( (yyvsp[-1].grammerInfo)->type != INT ){
                    writeError(" array index must be an integer");
                }
                delete (yyvsp[-3].symbolInfo); delete (yyvsp[-1].grammerInfo);

                writeLog("variable: ID LTHIRD expression RTHIRD",(yyval.grammerInfo)->text);
            }
#line 2169 "y.tab.c"
    break;

  case 43: /* logic_expression: rel_expression  */
#line 289 "parser.y"
                                   {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type;    
                        delete (yyvsp[0].grammerInfo);

                        writeLog("logic_expression: rel_expression",(yyval.grammerInfo)->text);
                    }
#line 2181 "y.tab.c"
    break;

  case 44: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 296 "parser.y"
                                                                    {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[-2].grammerInfo)->text+" "+(yyvsp[-1].symbolInfo)->getName()+" "+(yyvsp[0].grammerInfo)->text);
                        if( (yyvsp[-2].grammerInfo)->type != INT || (yyvsp[0].grammerInfo)->type != INT )
                            writeError("operands of LOGICOP must be integers");    
                        (yyval.grammerInfo)->type = INT;
                        delete (yyvsp[-2].grammerInfo); delete (yyvsp[0].grammerInfo);

                        writeLog("logic_expression: rel_expression LOGICOP rel_expression",(yyval.grammerInfo)->text);
                    }
#line 2195 "y.tab.c"
    break;

  case 45: /* rel_expression: simple_expression  */
#line 306 "parser.y"
                                      {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type ;
                        delete (yyvsp[0].grammerInfo);

                        writeLog("rel_expression: simple_expression",(yyval.grammerInfo)->text);
                    }
#line 2207 "y.tab.c"
    break;

  case 46: /* rel_expression: simple_expression RELOP simple_expression  */
#line 313 "parser.y"
                                                                        {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[-2].grammerInfo)->text+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = INT;
                        delete (yyvsp[-2].grammerInfo); delete (yyvsp[0].grammerInfo);

                        writeLog("rel_expression: simple_expression RELOP simple_expression",(yyval.grammerInfo)->text);
                    }
#line 2219 "y.tab.c"
    break;

  case 47: /* simple_expression: term  */
#line 321 "parser.y"
                         {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type ;
                        delete (yyvsp[0].grammerInfo);

                        writeLog("simple_expression: term",(yyval.grammerInfo)->text);
                    }
#line 2231 "y.tab.c"
    break;

  case 48: /* simple_expression: simple_expression ADDOP term  */
#line 328 "parser.y"
                                                           {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[-2].grammerInfo)->text+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        if( (yyvsp[-2].grammerInfo)->type == FLOAT || (yyvsp[0].grammerInfo)->type == FLOAT )
                            (yyval.grammerInfo)->type = FLOAT ;
                        else (yyval.grammerInfo)->type = (yyvsp[-2].grammerInfo)->type ;
                        delete (yyvsp[-2].grammerInfo); delete (yyvsp[0].grammerInfo);

                        writeLog("simple_expression: simple_expression ADDOP term",(yyval.grammerInfo)->text);
                    }
#line 2245 "y.tab.c"
    break;

  case 49: /* term: unary_expression  */
#line 338 "parser.y"
                         {
            (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
            (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type ;
            delete (yyvsp[0].grammerInfo);
            
            writeLog("term: unary_expression",(yyval.grammerInfo)->text);
        }
#line 2257 "y.tab.c"
    break;

  case 50: /* term: term MULOP unary_expression  */
#line 345 "parser.y"
                                     {
            (yyval.grammerInfo) = new grammer_info((yyvsp[-2].grammerInfo)->text+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
            if( (yyvsp[-2].grammerInfo)->type == FLOAT || (yyvsp[0].grammerInfo)->type == FLOAT )
                (yyval.grammerInfo)->type = FLOAT ;
            else (yyval.grammerInfo)->type = (yyvsp[-2].grammerInfo)->type ;
            delete (yyvsp[-2].grammerInfo); delete (yyvsp[0].grammerInfo);

            writeLog("term: term MULOP unary_expression",(yyval.grammerInfo)->text); 
        }
#line 2271 "y.tab.c"
    break;

  case 51: /* unary_expression: ADDOP unary_expression  */
#line 355 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type;
                        delete (yyvsp[-1].symbolInfo);

                        writeLog("unary_expression: ADDOP unary_expression",(yyval.grammerInfo)->text);
                    }
#line 2283 "y.tab.c"
    break;

  case 52: /* unary_expression: NOT unary_expression  */
#line 362 "parser.y"
                                                  {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = INT;
                        delete (yyvsp[-1].symbolInfo); delete (yyvsp[0].grammerInfo);

                        writeLog("unary_expression: NOT unary_expression",(yyval.grammerInfo)->text);
                    }
#line 2295 "y.tab.c"
    break;

  case 53: /* unary_expression: factor  */
#line 369 "parser.y"
                                     {
                        (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type ;
                        delete (yyvsp[0].grammerInfo);

                        writeLog("unary_expression: factor",(yyval.grammerInfo)->text);
                    }
#line 2307 "y.tab.c"
    break;

  case 54: /* factor: variable  */
#line 378 "parser.y"
                 {
            (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
            (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type;
            delete (yyvsp[0].grammerInfo);

            writeLog("factor: variable",(yyval.grammerInfo)->text);
        }
#line 2319 "y.tab.c"
    break;

  case 55: /* factor: ID LPAREN argument_list RPAREN  */
#line 385 "parser.y"
                                             {
            (yyval.grammerInfo) = new grammer_info((yyvsp[-3].symbolInfo)->getName()+"("+(yyvsp[-1].grammerInfo)->text+")");
            writeLog("factor: ID LPAREN argument_list RPAREN",(yyval.grammerInfo)->text);
        }
#line 2328 "y.tab.c"
    break;

  case 56: /* factor: LPAREN expression RPAREN  */
#line 389 "parser.y"
                                       {
            (yyval.grammerInfo) = new grammer_info("("+(yyvsp[-1].grammerInfo)->text+")");
            writeLog("factor: LPAREN expression RPAREN",(yyval.grammerInfo)->text);
        }
#line 2337 "y.tab.c"
    break;

  case 57: /* factor: CONST_INT  */
#line 393 "parser.y"
                        {
            (yyval.grammerInfo) = new grammer_info((yyvsp[0].symbolInfo)->getName());
            writeLog("factor: CONST_INT",(yyval.grammerInfo)->text);  
        }
#line 2346 "y.tab.c"
    break;

  case 58: /* factor: CONST_FLOAT  */
#line 397 "parser.y"
                          {
            (yyval.grammerInfo) = new grammer_info((yyvsp[0].symbolInfo)->getName());
            writeLog("factor: CONST_FLOAT",(yyval.grammerInfo)->text);
        }
#line 2355 "y.tab.c"
    break;

  case 59: /* factor: variable INCOP  */
#line 401 "parser.y"
                             {
            (yyval.grammerInfo) = new grammer_info((yyvsp[-1].grammerInfo)->text+"++");
            writeLog("factor: variable INCOP",(yyval.grammerInfo)->text);
        }
#line 2364 "y.tab.c"
    break;

  case 60: /* factor: variable DECOP  */
#line 405 "parser.y"
                             {
            (yyval.grammerInfo) = new grammer_info((yyvsp[-1].grammerInfo)->text+"--");
            writeLog("factor: variable DECOP",(yyval.grammerInfo)->text);
        }
#line 2373 "y.tab.c"
    break;

  case 61: /* argument_list: arguments  */
#line 411 "parser.y"
                          {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                    writeLog("argument_list: arguments",(yyval.grammerInfo)->text);
                }
#line 2382 "y.tab.c"
    break;

  case 62: /* arguments: arguments COMMA logic_expression  */
#line 417 "parser.y"
                                             {
                (yyval.grammerInfo) = new grammer_info((yyvsp[-2].grammerInfo)->text+","+(yyvsp[0].grammerInfo)->text);
                writeLog("arguments: arguments COMMA logic_expression",(yyval.grammerInfo)->text);
            }
#line 2391 "y.tab.c"
    break;

  case 63: /* arguments: logic_expression  */
#line 421 "parser.y"
                                   {
                (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                writeLog("arguments: logic_expression",(yyval.grammerInfo)->text);
            }
#line 2400 "y.tab.c"
    break;


#line 2404 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

  return yyresult;
}

#line 427 "parser.y"


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
    delete symbolTable;
    logfile.close();
    errorfile.close();
    return 0;
}
