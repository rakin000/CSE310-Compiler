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
FILE *fp,*fp2,*fp3,*fp1;
fstream logfile;
fstream errorfile;
symbol_table *symbolTable = new symbol_table(HASH_TABLE_SIZE);
bool inFunction = 0;
symbol *currentFunction = nullptr, *dummySymbol = new symbol("dummy","dummy");
stack<symbol*> activeFunctions;
scope_table *declaredFunctions = new scope_table(HASH_TABLE_SIZE);


void yyerror(const char *s){
    error_count++;
    cout<<"Error at Line "<<line_count<<": "<<s<<endl;
    errorfile<<"Error at Line "<<line_count<<": "<<s<<endl;
    // yyerrok;
    return ;
}

#define writeLog(grammer,text) logfile<<"Line "<<line_count<<": "<<grammer<<"\n\n"<<text<<"\n"<<endl;

void writeError(string s){
    error_count++;
    errorfile<<"Error at Line "<<line_count<<": "<<s<<endl;
    logfile<<"Error at Line "<<line_count<<": "<<s<<endl;
}


#line 120 "y.tab.c"

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
    PRINTF = 294,                  /* PRINTF  */
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
#define PRINTF 294
#define MAIN 295
#define LOWER_THAN_ELSE 296
#define INT_ARRAY 297
#define FLOAT_ARRAY 298
#define UNKNOWN 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "parser.y"

    symbol* symbolInfo;
    grammer_info* grammerInfo;

#line 266 "y.tab.c"

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
  YYSYMBOL_PRINTF = 39,                    /* PRINTF  */
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
  YYSYMBOL_statement = 61,                 /* statement  */
  YYSYMBOL_expression_statement = 62,      /* expression_statement  */
  YYSYMBOL_expression = 63,                /* expression  */
  YYSYMBOL_variable = 64,                  /* variable  */
  YYSYMBOL_logic_expression = 65,          /* logic_expression  */
  YYSYMBOL_rel_expression = 66,            /* rel_expression  */
  YYSYMBOL_simple_expression = 67,         /* simple_expression  */
  YYSYMBOL_term = 68,                      /* term  */
  YYSYMBOL_unary_expression = 69,          /* unary_expression  */
  YYSYMBOL_factor = 70,                    /* factor  */
  YYSYMBOL_argument_list = 71,             /* argument_list  */
  YYSYMBOL_arguments = 72                  /* arguments  */
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
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

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
       0,    78,    78,    86,    92,   100,   106,   111,   117,   138,
     151,   158,   165,   173,   184,   192,   202,   211,   224,   234,
     247,   256,   264,   272,   281,   281,   325,   325,   357,   367,
     367,   385,   385,   403,   409,   416,   422,   428,   434,   440,
     446,   452,   458,   464,   480,   489,   493,   500,   507,   523,
     537,   562,   569,   579,   586,   594,   601,   619,   626,   649,
     657,   664,   673,   680,   707,   714,   721,   728,   735,   744,
     753,   761
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
  "CONST_CHAR", "CONST_INT", "CONST_FLOAT", "PRINTF", "MAIN",
  "LOWER_THAN_ELSE", "INT_ARRAY", "FLOAT_ARRAY", "UNKNOWN", "$accept",
  "start", "program", "unit", "var_declaration", "type_specifier",
  "declaration_list", "func_declaration", "parameter_list",
  "func_definition", "$@1", "$@2", "compound_statement", "$@3", "$@4",
  "statements", "statement", "expression_statement", "expression",
  "variable", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
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

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      69,   -76,   -76,   -76,    25,    69,   -76,   -76,    10,   -76,
     -76,   -76,   -76,   -12,    -1,    45,   -76,    74,    -9,    12,
     -76,    30,    33,    28,   -17,    62,    66,    -2,   -76,    75,
     -76,    72,    69,   -76,    65,    83,   -76,   -76,   -76,   -76,
      75,    70,    82,    92,    87,   -76,   -76,   -76,    84,    88,
      91,    93,   116,   116,   -76,   116,   116,    14,   -76,   -76,
      94,   -76,    11,   -76,    53,   -76,   -76,    90,    21,   -76,
      89,     7,    95,   -76,   -76,   -76,   -76,   116,   107,   116,
      98,    99,    55,   -76,   -76,   116,   116,    85,   102,   -76,
     -76,   -76,   -76,   -76,   116,   116,   116,   116,   116,   110,
     107,   113,   -76,   -76,   -76,   114,   115,   122,   124,   117,
     -76,   -76,    95,   111,   -76,    92,   116,    92,   -76,   116,
     -76,   123,   144,   130,   -76,   -76,   -76,    92,    92,   -76,
     -76
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
       0,     0,     0,     0,    45,     0,     0,    49,    65,    66,
       0,    35,     0,    37,     0,    34,    36,     0,    62,    47,
      51,    53,    55,    57,    61,    32,    44,     0,     0,     0,
       0,     0,    62,    59,    60,     0,     0,     0,    16,    30,
      33,    46,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,    43,    64,    71,     0,    69,     0,    49,     0,
      48,    52,    56,    54,    58,     0,     0,     0,    63,     0,
      50,     0,    40,     0,    41,    70,    42,     0,     0,    39,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,   112,    18,    16,   -76,   -76,   -76,   -76,
     -76,   -76,   -14,   -76,   -76,   -76,   -60,   -69,   -50,   -55,
     -75,    60,    59,    61,   -49,   -76,   -76,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    61,    62,    15,     9,    24,    10,
      40,    29,    63,    43,    44,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   105,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,    82,    80,    81,    90,    31,    83,    84,    32,   100,
     104,    13,    13,    37,    16,    38,     8,    35,     7,   110,
      17,     8,    18,     7,    36,    11,    45,    99,    25,   101,
      82,   116,   109,    23,    96,    85,   107,    86,    97,    82,
      82,    82,    82,    82,   125,    14,    88,    26,    41,   114,
      92,    93,    27,    94,    48,   122,    49,   124,    50,    28,
       1,     2,     3,    30,    82,    51,   123,   129,   130,    52,
      19,    20,    35,    89,    53,    21,     1,     2,     3,    54,
      55,     1,     2,     3,    92,    93,    33,    56,    57,    34,
      58,    59,    60,    48,    35,    49,    22,    50,    39,     1,
       2,     3,    42,   -31,    51,    46,    47,    75,    52,    77,
      76,    35,    78,    53,    79,    87,    91,    12,    54,    55,
     108,   103,    95,    98,   102,    18,    56,    57,    53,    58,
      59,    60,   115,    54,    55,   117,   118,    53,    96,   121,
     119,    56,    57,    55,    58,    59,   120,    86,   127,   126,
      56,    57,   128,    58,    59,   111,   113,   112
};

static const yytype_uint8 yycheck[] =
{
      55,    56,    52,    53,    64,    22,    55,    56,    25,    78,
      85,     1,     1,    27,    26,    29,     0,    19,     0,    94,
      21,     5,    23,     5,    26,     0,    40,    77,    37,    79,
      85,   100,    87,    17,    27,    21,    86,    23,    31,    94,
      95,    96,    97,    98,   119,    35,    35,    35,    32,    98,
      29,    30,    22,    32,     1,   115,     3,   117,     5,    26,
       7,     8,     9,    35,   119,    12,   116,   127,   128,    16,
      25,    26,    19,    20,    21,     1,     7,     8,     9,    26,
      27,     7,     8,     9,    29,    30,    24,    34,    35,    23,
      37,    38,    39,     1,    19,     3,    22,     5,    26,     7,
       8,     9,    37,    20,    12,    35,    24,    20,    16,    21,
      26,    19,    21,    21,    21,    21,    26,     5,    26,    27,
      35,    22,    33,    28,    26,    23,    34,    35,    21,    37,
      38,    39,    22,    26,    27,    22,    22,    21,    27,    22,
      25,    34,    35,    27,    37,    38,    24,    23,     4,    26,
      34,    35,    22,    37,    38,    95,    97,    96
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
      39,    49,    50,    57,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    20,    26,    21,    21,    21,
      63,    63,    64,    69,    69,    21,    23,    21,    35,    20,
      61,    26,    29,    30,    32,    33,    27,    31,    28,    63,
      62,    63,    26,    22,    65,    71,    72,    63,    35,    64,
      65,    66,    68,    67,    69,    22,    62,    22,    22,    25,
      24,    22,    61,    63,    61,    65,    26,     4,    22,    61,
      61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    51,    51,    52,    52,    52,
      53,    53,    53,    53,    55,    54,    56,    54,    54,    58,
      57,    59,    57,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    71,
      72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     6,     3,     4,     1,     6,     5,     6,
       4,     3,     2,     1,     0,     7,     0,     6,     6,     0,
       4,     0,     3,     2,     1,     1,     1,     1,     7,     7,
       5,     5,     5,     3,     2,     1,     2,     1,     3,     1,
       4,     1,     3,     1,     3,     1,     3,     1,     3,     2,
       2,     1,     1,     4,     3,     1,     1,     2,     2,     1,
       3,     1
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
  switch (yykind)
    {
    case YYSYMBOL_IF: /* IF  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1430 "y.tab.c"
        break;

    case YYSYMBOL_ELSE: /* ELSE  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1436 "y.tab.c"
        break;

    case YYSYMBOL_FOR: /* FOR  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1442 "y.tab.c"
        break;

    case YYSYMBOL_DO: /* DO  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1448 "y.tab.c"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1454 "y.tab.c"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1460 "y.tab.c"
        break;

    case YYSYMBOL_VOID: /* VOID  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1466 "y.tab.c"
        break;

    case YYSYMBOL_SWITCH: /* SWITCH  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1472 "y.tab.c"
        break;

    case YYSYMBOL_DEFAULT: /* DEFAULT  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1478 "y.tab.c"
        break;

    case YYSYMBOL_WHILE: /* WHILE  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1484 "y.tab.c"
        break;

    case YYSYMBOL_BREAK: /* BREAK  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1490 "y.tab.c"
        break;

    case YYSYMBOL_CHAR: /* CHAR  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1496 "y.tab.c"
        break;

    case YYSYMBOL_DOUBLE: /* DOUBLE  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1502 "y.tab.c"
        break;

    case YYSYMBOL_RETURN: /* RETURN  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1508 "y.tab.c"
        break;

    case YYSYMBOL_CASE: /* CASE  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1514 "y.tab.c"
        break;

    case YYSYMBOL_CONTINUE: /* CONTINUE  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1520 "y.tab.c"
        break;

    case YYSYMBOL_LCURL: /* LCURL  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1526 "y.tab.c"
        break;

    case YYSYMBOL_RCURL: /* RCURL  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1532 "y.tab.c"
        break;

    case YYSYMBOL_LPAREN: /* LPAREN  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1538 "y.tab.c"
        break;

    case YYSYMBOL_RPAREN: /* RPAREN  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1544 "y.tab.c"
        break;

    case YYSYMBOL_LTHIRD: /* LTHIRD  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1550 "y.tab.c"
        break;

    case YYSYMBOL_RTHIRD: /* RTHIRD  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1556 "y.tab.c"
        break;

    case YYSYMBOL_COMMA: /* COMMA  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1562 "y.tab.c"
        break;

    case YYSYMBOL_SEMICOLON: /* SEMICOLON  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1568 "y.tab.c"
        break;

    case YYSYMBOL_ADDOP: /* ADDOP  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1574 "y.tab.c"
        break;

    case YYSYMBOL_MULOP: /* MULOP  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1580 "y.tab.c"
        break;

    case YYSYMBOL_INCOP: /* INCOP  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1586 "y.tab.c"
        break;

    case YYSYMBOL_DECOP: /* DECOP  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1592 "y.tab.c"
        break;

    case YYSYMBOL_RELOP: /* RELOP  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1598 "y.tab.c"
        break;

    case YYSYMBOL_ASSIGNOP: /* ASSIGNOP  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1604 "y.tab.c"
        break;

    case YYSYMBOL_LOGICOP: /* LOGICOP  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1610 "y.tab.c"
        break;

    case YYSYMBOL_NOT: /* NOT  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1616 "y.tab.c"
        break;

    case YYSYMBOL_ID: /* ID  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1622 "y.tab.c"
        break;

    case YYSYMBOL_CONST_CHAR: /* CONST_CHAR  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1628 "y.tab.c"
        break;

    case YYSYMBOL_CONST_INT: /* CONST_INT  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1634 "y.tab.c"
        break;

    case YYSYMBOL_CONST_FLOAT: /* CONST_FLOAT  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1640 "y.tab.c"
        break;

    case YYSYMBOL_PRINTF: /* PRINTF  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1646 "y.tab.c"
        break;

    case YYSYMBOL_MAIN: /* MAIN  */
#line 74 "parser.y"
            { free(((*yyvaluep).symbolInfo)); }
#line 1652 "y.tab.c"
        break;

    case YYSYMBOL_start: /* start  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1658 "y.tab.c"
        break;

    case YYSYMBOL_program: /* program  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1664 "y.tab.c"
        break;

    case YYSYMBOL_unit: /* unit  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1670 "y.tab.c"
        break;

    case YYSYMBOL_var_declaration: /* var_declaration  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1676 "y.tab.c"
        break;

    case YYSYMBOL_type_specifier: /* type_specifier  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1682 "y.tab.c"
        break;

    case YYSYMBOL_declaration_list: /* declaration_list  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1688 "y.tab.c"
        break;

    case YYSYMBOL_func_declaration: /* func_declaration  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1694 "y.tab.c"
        break;

    case YYSYMBOL_parameter_list: /* parameter_list  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1700 "y.tab.c"
        break;

    case YYSYMBOL_func_definition: /* func_definition  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1706 "y.tab.c"
        break;

    case YYSYMBOL_compound_statement: /* compound_statement  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1712 "y.tab.c"
        break;

    case YYSYMBOL_statements: /* statements  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1718 "y.tab.c"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1724 "y.tab.c"
        break;

    case YYSYMBOL_expression_statement: /* expression_statement  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1730 "y.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1736 "y.tab.c"
        break;

    case YYSYMBOL_variable: /* variable  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1742 "y.tab.c"
        break;

    case YYSYMBOL_logic_expression: /* logic_expression  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1748 "y.tab.c"
        break;

    case YYSYMBOL_rel_expression: /* rel_expression  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1754 "y.tab.c"
        break;

    case YYSYMBOL_simple_expression: /* simple_expression  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1760 "y.tab.c"
        break;

    case YYSYMBOL_term: /* term  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1766 "y.tab.c"
        break;

    case YYSYMBOL_unary_expression: /* unary_expression  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1772 "y.tab.c"
        break;

    case YYSYMBOL_factor: /* factor  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1778 "y.tab.c"
        break;

    case YYSYMBOL_argument_list: /* argument_list  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1784 "y.tab.c"
        break;

    case YYSYMBOL_arguments: /* arguments  */
#line 75 "parser.y"
            { free(((*yyvaluep).grammerInfo)); }
#line 1790 "y.tab.c"
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
#line 78 "parser.y"
                {
            writeLog("start: program","");
            symbolTable->print_all_scope_table() ;

            free((yyvsp[0].grammerInfo));
            YYACCEPT;
        }
#line 2067 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 86 "parser.y"
                      {
            (yyval.grammerInfo) = new grammer_info("program: program unit",string((yyvsp[-1].grammerInfo)->text+"\n"+(yyvsp[0].grammerInfo)->text) );
            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);

            free((yyvsp[-1].grammerInfo)); free((yyvsp[0].grammerInfo));
        }
#line 2078 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 92 "parser.y"
                   {
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            writeLog("program: unit",(yyval.grammerInfo)->text);

            free((yyvsp[0].grammerInfo));
        }
#line 2089 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 100 "parser.y"
                        { 
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            free((yyvsp[0].grammerInfo));

            writeLog("unit: var_declaration",(yyval.grammerInfo)->text); 
        }
#line 2100 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 106 "parser.y"
                          {
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            free((yyvsp[0].grammerInfo));
            writeLog("unit: func_declaration",(yyval.grammerInfo)->text);
        }
#line 2110 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 111 "parser.y"
                         {
            (yyval.grammerInfo) = new grammer_info(string((yyvsp[0].grammerInfo)->text));
            free((yyvsp[0].grammerInfo));
            writeLog("unit: func_definition",(yyval.grammerInfo)->text);
        }
#line 2120 "y.tab.c"
    break;

  case 8: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 117 "parser.y"
                                                           {
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[-2].grammerInfo)->text + " " + (yyvsp[-1].grammerInfo)->text + ";"));
                    if( (yyvsp[-2].grammerInfo)->type == _void_ )
                        writeError("variable type cannot be void");
                        
                    for(int i=0;i<(yyvsp[-1].grammerInfo)->ids.size();i++){
                        (yyvsp[-1].grammerInfo)->ids[i].type = (yyvsp[-2].grammerInfo)->text;
                        symbol* foundSymbol = symbolTable->lookup_current((yyvsp[-1].grammerInfo)->ids[i].name ) ; 
                        if( foundSymbol == nullptr ){
                            foundSymbol = new symbol( (yyvsp[-1].grammerInfo)->ids[i].name,(yyvsp[-1].grammerInfo)->ids[i].type,(yyvsp[-1].grammerInfo)->ids[i].array_size) ;
                            symbolTable->insert(foundSymbol);
                            free(foundSymbol);
                        }
                        else {
                            writeError("multiple declaration of "+(yyvsp[-1].grammerInfo)->ids[i].name);
                        }
                    }
                    free((yyvsp[-2].grammerInfo)); free((yyvsp[-1].grammerInfo)); 

                    writeLog("var_declaration: type_specifier declaration_list SEMICOLON",(yyval.grammerInfo)->text);
                }
#line 2146 "y.tab.c"
    break;

  case 9: /* var_declaration: type_specifier error SEMICOLON  */
#line 138 "parser.y"
                                                 {
                    // yyerror("syntax error");
                    yyerrok;
                    (yyval.grammerInfo) = new grammer_info(string((yyvsp[-2].grammerInfo)->text + " ;"));
                    if( (yyvsp[-2].grammerInfo)->type == _void_ )
                        writeError("variable type cannot be void");
    
                    

                    writeLog("var_declaration: type_specifier declaration_list SEMICOLON",(yyval.grammerInfo)->text);
                }
#line 2162 "y.tab.c"
    break;

  case 10: /* type_specifier: INT  */
#line 151 "parser.y"
                    {
                    (yyval.grammerInfo) = new grammer_info(string("int"));
                    (yyval.grammerInfo)->text = "int";
                    (yyval.grammerInfo)->type = _int_ ; 

                    writeLog("type_specifier: INT",(yyval.grammerInfo)->text);
                }
#line 2174 "y.tab.c"
    break;

  case 11: /* type_specifier: FLOAT  */
#line 158 "parser.y"
                       {
                    (yyval.grammerInfo) = new grammer_info(string("float"));
                    (yyval.grammerInfo)->text = "float";
                    (yyval.grammerInfo)->type = _float_; 

                    writeLog("type_specifier: FLOAT",(yyval.grammerInfo)->text);
                }
#line 2186 "y.tab.c"
    break;

  case 12: /* type_specifier: VOID  */
#line 165 "parser.y"
                      {
                    (yyval.grammerInfo) = new grammer_info(string("void"));
                    (yyval.grammerInfo)->text = "void";
                    (yyval.grammerInfo)->type = _void_ ;

                    writeLog("type_specifier: VOID",(yyval.grammerInfo)->text);
                }
#line 2198 "y.tab.c"
    break;

  case 13: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 173 "parser.y"
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
#line 2214 "y.tab.c"
    break;

  case 14: /* declaration_list: declaration_list COMMA ID  */
#line 184 "parser.y"
                                           {
                    (yyval.grammerInfo) = new grammer_info("declaration_list: declaration_list COMMA ID",string((yyvsp[-2].grammerInfo)->text + "," + (yyvsp[0].symbolInfo)->getName()));
                    (yyval.grammerInfo)->ids = (yyvsp[-2].grammerInfo)->ids;
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[0].symbolInfo)->getName(),(yyvsp[0].symbolInfo)->getType(),(yyvsp[0].symbolInfo)->getArraySize()});
                    free((yyvsp[-2].grammerInfo)); free((yyvsp[0].symbolInfo)); 

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 2227 "y.tab.c"
    break;

  case 15: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 192 "parser.y"
                                             {
                    (yyval.grammerInfo) = new grammer_info("declaration_list: ID LTHIRD CONST_INT RTHIRD",string((yyvsp[-3].symbolInfo)->getName() + "[" + (yyvsp[-1].symbolInfo)->getName() + "]"));
                    if( stoi((yyvsp[-1].symbolInfo)->getName()) < 0 )
                        writeError("array size must be positive");
                    (yyvsp[-3].symbolInfo)->setArraySize(stoi((yyvsp[-1].symbolInfo)->getName()));
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[-3].symbolInfo)->getName(),(yyvsp[-3].symbolInfo)->getType(),(yyvsp[-3].symbolInfo)->getArraySize()});
                    free((yyvsp[-3].symbolInfo)); free((yyvsp[-1].symbolInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text) ;
                }
#line 2242 "y.tab.c"
    break;

  case 16: /* declaration_list: ID  */
#line 202 "parser.y"
                     {
                    (yyval.grammerInfo) = new grammer_info("declaration_list: ID",string((yyvsp[0].symbolInfo)->getName()));
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[0].symbolInfo)->getName(),(yyvsp[0].symbolInfo)->getType(),(yyvsp[0].symbolInfo)->getArraySize()}); // default array_size = -1;
                    free((yyvsp[0].symbolInfo));  

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 2254 "y.tab.c"
    break;

  case 17: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 211 "parser.y"
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
#line 2272 "y.tab.c"
    break;

  case 18: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 224 "parser.y"
                                                            {
                    (yyval.grammerInfo) = new grammer_info("func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON",(yyvsp[-4].grammerInfo)->text+" "+(yyvsp[-3].symbolInfo)->getName()+"();");
                    (yyvsp[-3].symbolInfo)->setType((yyvsp[-4].grammerInfo)->text);
                    (yyvsp[-3].symbolInfo)->markAsFunction();
                    declaredFunctions->insert((yyvsp[-3].symbolInfo));
                    
                    free((yyvsp[-4].grammerInfo)); free((yyvsp[-3].symbolInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
                }
#line 2287 "y.tab.c"
    break;

  case 19: /* func_declaration: type_specifier ID LPAREN error RPAREN SEMICOLON  */
#line 234 "parser.y"
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
#line 2304 "y.tab.c"
    break;

  case 20: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 247 "parser.y"
                                                       {
                    (yyval.grammerInfo) = new grammer_info("parameter_list: parameter_list COMMA type_specifier ID",(yyvsp[-3].grammerInfo)->text +"," + (yyvsp[-1].grammerInfo)->text + " " + (yyvsp[0].symbolInfo)->getName());
                    (yyval.grammerInfo)->ids = (yyvsp[-3].grammerInfo)->ids;
                    (yyvsp[0].symbolInfo)->setType((yyvsp[-1].grammerInfo)->text);
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[0].symbolInfo)->getName(),(yyvsp[0].symbolInfo)->getType(),(yyvsp[0].symbolInfo)->getArraySize()});
                    free((yyvsp[-3].grammerInfo)); free((yyvsp[-1].grammerInfo)); free((yyvsp[0].symbolInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 2318 "y.tab.c"
    break;

  case 21: /* parameter_list: parameter_list COMMA type_specifier  */
#line 256 "parser.y"
                                                      {
                    (yyval.grammerInfo) = new grammer_info("parameter_list: parameter_list COMMA type_specifier",(yyvsp[-2].grammerInfo)->text +"," + (yyvsp[0].grammerInfo)->text);
                    (yyval.grammerInfo)->ids = (yyvsp[-2].grammerInfo)->ids;
                    (yyvsp[-2].grammerInfo)->ids.push_back({"_",(yyvsp[0].grammerInfo)->text,-1}); 
                    free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo)); 

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 2331 "y.tab.c"
    break;

  case 22: /* parameter_list: type_specifier ID  */
#line 264 "parser.y"
                                    {
                    (yyval.grammerInfo) = new grammer_info("parameter_list: type_specifier ID",(yyvsp[-1].grammerInfo)->text +" " + (yyvsp[0].symbolInfo)->getName());
                    (yyvsp[0].symbolInfo)->setType((yyvsp[-1].grammerInfo)->text);
                    (yyval.grammerInfo)->ids.push_back({(yyvsp[0].symbolInfo)->getName(),(yyvsp[0].symbolInfo)->getType(),(yyvsp[0].symbolInfo)->getArraySize()});
                    free((yyvsp[-1].grammerInfo)); free((yyvsp[0].symbolInfo));
                    
                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text) ;
                }
#line 2344 "y.tab.c"
    break;

  case 23: /* parameter_list: type_specifier  */
#line 272 "parser.y"
                                 {
                    (yyval.grammerInfo) = new grammer_info((yyvsp[0].grammerInfo)->text);
                    (yyval.grammerInfo)->ids.push_back({"_",(yyvsp[0].grammerInfo)->text,-1});
                    free((yyvsp[0].grammerInfo));

                    writeLog("parameter_list: type_specifier",(yyval.grammerInfo)->text) ;
                }
#line 2356 "y.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 281 "parser.y"
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

                        for(int i=0;i<(yyvsp[-1].grammerInfo)->ids.size();i++){
                            foundSymbol = symbolTable->lookup_current((yyvsp[-1].grammerInfo)->ids[i].name);
                            if( foundSymbol == nullptr){
                                foundSymbol = new symbol((yyvsp[-1].grammerInfo)->ids[i].name,(yyvsp[-1].grammerInfo)->ids[i].type,(yyvsp[-1].grammerInfo)->ids[i].array_size);
                                symbolTable->insert(foundSymbol);
                                free(foundSymbol);
                            }
                            else 
                                writeError("multiple parameters of same name");
                        }
                    }
#line 2401 "y.tab.c"
    break;

  case 25: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 320 "parser.y"
                                         {
                    (yyval.grammerInfo) = new grammer_info("func_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement",(yyvsp[-6].grammerInfo)->text+" "+(yyvsp[-5].symbolInfo)->getName()+"("+(yyvsp[-3].grammerInfo)->text+")"+(yyvsp[0].grammerInfo)->text); 
                    free((yyvsp[-6].grammerInfo)); free((yyvsp[-3].grammerInfo)); 
                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text) ;
                }
#line 2411 "y.tab.c"
    break;

  case 26: /* $@2: %empty  */
#line 325 "parser.y"
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

                    }
#line 2443 "y.tab.c"
    break;

  case 27: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 351 "parser.y"
                                         {
                    (yyval.grammerInfo) = new grammer_info("func_definition: type_specifier ID LPAREN RPAREN compound_statement",(yyvsp[-5].grammerInfo)->text+" "+(yyvsp[-4].symbolInfo)->getName()+"()"+(yyvsp[0].grammerInfo)->text); 
                    free((yyvsp[-5].grammerInfo)); free((yyvsp[-4].symbolInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 2454 "y.tab.c"
    break;

  case 28: /* func_definition: type_specifier ID LPAREN error RPAREN compound_statement  */
#line 357 "parser.y"
                                                                           {
                    // yyerror("syntax error, function definition");
                    yyerrok;
                    (yyval.grammerInfo) = new grammer_info("func_definition: type_specifier ID LPAREN RPAREN compound_statement",(yyvsp[-5].grammerInfo)->text+" "+(yyvsp[-4].symbolInfo)->getName()+"()"+(yyvsp[0].grammerInfo)->text); 
                    // delete $1; delete $2;

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);

                }
#line 2468 "y.tab.c"
    break;

  case 29: /* $@3: %empty  */
#line 367 "parser.y"
                          {
                            if( !inFunction ){
                                symbolTable->enter_scope();
                                currentFunction = dummySymbol ;
                                activeFunctions.push(currentFunction);
                            }
                            inFunction = 0;
                        }
#line 2481 "y.tab.c"
    break;

  case 30: /* compound_statement: LCURL $@3 statements RCURL  */
#line 374 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info("compound_statement: LCURL statements RCURL","{\n"+(yyvsp[-1].grammerInfo)->text+"\n}");

                        free((yyvsp[-1].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text); 
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                        activeFunctions.pop();
                        currentFunction = activeFunctions.top();
                    }
#line 2497 "y.tab.c"
    break;

  case 31: /* $@4: %empty  */
#line 385 "parser.y"
                            {
                            if( !inFunction ){
                                symbolTable->enter_scope();
                                currentFunction = dummySymbol ;
                                activeFunctions.push(currentFunction);
                            }
                            inFunction = 0;
                        }
#line 2510 "y.tab.c"
    break;

  case 32: /* compound_statement: LCURL $@4 RCURL  */
#line 393 "parser.y"
                              {
                        (yyval.grammerInfo) = new grammer_info("compound_statement: LCURL RCURL","{\n}");

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                        symbolTable->print_all_scope_table();
                        symbolTable->exit_scope();
                        activeFunctions.pop();
                        currentFunction = activeFunctions.top();
                    }
#line 2524 "y.tab.c"
    break;

  case 33: /* statements: statements statement  */
#line 403 "parser.y"
                                 {
                (yyval.grammerInfo) = new grammer_info("statements: statements statement",(yyvsp[-1].grammerInfo)->text+"\n"+(yyvsp[0].grammerInfo)->text);
                free((yyvsp[-1].grammerInfo)); free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2535 "y.tab.c"
    break;

  case 34: /* statements: statement  */
#line 409 "parser.y"
                       {
                (yyval.grammerInfo) = new grammer_info("statements: statement",(yyvsp[0].grammerInfo)->text);
                free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2546 "y.tab.c"
    break;

  case 35: /* statement: var_declaration  */
#line 416 "parser.y"
                            {
                (yyval.grammerInfo) = new grammer_info("statement: var_declaration",(yyvsp[0].grammerInfo)->text);
                free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2557 "y.tab.c"
    break;

  case 36: /* statement: expression_statement  */
#line 422 "parser.y"
                                  {
                (yyval.grammerInfo) = new grammer_info("statement: expression_statement",(yyvsp[0].grammerInfo)->text);
                free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2568 "y.tab.c"
    break;

  case 37: /* statement: compound_statement  */
#line 428 "parser.y"
                                {
                (yyval.grammerInfo) = new grammer_info("statement: compound_statement",(yyvsp[0].grammerInfo)->text);
                free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2579 "y.tab.c"
    break;

  case 38: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 434 "parser.y"
                                                                                              {
                (yyval.grammerInfo) = new grammer_info("statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement","for("+(yyvsp[-4].grammerInfo)->text+(yyvsp[-3].grammerInfo)->text+(yyvsp[-2].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text);
                free((yyvsp[-4].grammerInfo)); free((yyvsp[-3].grammerInfo)); free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));
                
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
            }
#line 2590 "y.tab.c"
    break;

  case 39: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 440 "parser.y"
                                                                  {
                (yyval.grammerInfo) = new grammer_info("statement: IF LPAREN expression RPAREN statement ELSE statement","if("+(yyvsp[-4].grammerInfo)->text+")\n"+(yyvsp[-2].grammerInfo)->text+"\nelse\n"+(yyvsp[0].grammerInfo)->text);
                free((yyvsp[-4].grammerInfo)); free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));   
                
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2601 "y.tab.c"
    break;

  case 40: /* statement: IF LPAREN expression RPAREN statement  */
#line 446 "parser.y"
                                                                         {
                (yyval.grammerInfo) = new grammer_info("statement: IF LPAREN expression RPAREN statement","if("+(yyvsp[-2].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text);
                free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2612 "y.tab.c"
    break;

  case 41: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 452 "parser.y"
                                                      {
                (yyval.grammerInfo) = new grammer_info("statement: WHILE LPAREN expression RPAREN statement","while("+(yyvsp[-2].grammerInfo)->text+")\n"+(yyvsp[0].grammerInfo)->text);
                free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2623 "y.tab.c"
    break;

  case 42: /* statement: PRINTF LPAREN variable RPAREN SEMICOLON  */
#line 458 "parser.y"
                                                     {
                (yyval.grammerInfo) = new grammer_info("statement: PRINTLN LPAREN ID RPAREN SEMICOLON","printf("+(yyvsp[-2].grammerInfo)->text+");");
                free((yyvsp[-2].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
            }
#line 2634 "y.tab.c"
    break;

  case 43: /* statement: RETURN expression SEMICOLON  */
#line 464 "parser.y"
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
#line 2655 "y.tab.c"
    break;

  case 44: /* statement: error SEMICOLON  */
#line 480 "parser.y"
                              {
                // yyerror("syntax error, invalid statement");

                yyerrok;
                (yyval.grammerInfo) = new grammer_info("statement: error");
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2667 "y.tab.c"
    break;

  case 45: /* expression_statement: SEMICOLON  */
#line 489 "parser.y"
                                {
                        (yyval.grammerInfo) = new grammer_info("expression_statement: SEMICOLON",";");
                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2676 "y.tab.c"
    break;

  case 46: /* expression_statement: expression SEMICOLON  */
#line 493 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info("expression_statement: expression SEMICOLON",(yyvsp[-1].grammerInfo)->text+";");
                        free((yyvsp[-1].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2687 "y.tab.c"
    break;

  case 47: /* expression: logic_expression  */
#line 500 "parser.y"
                             {
                (yyval.grammerInfo) = new grammer_info("expression: logic_expression",(yyvsp[0].grammerInfo)->text);
                (yyval.grammerInfo)->type = (yyvsp[0].grammerInfo)->type;
                free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2699 "y.tab.c"
    break;

  case 48: /* expression: variable ASSIGNOP logic_expression  */
#line 507 "parser.y"
                                                 {
                (yyval.grammerInfo) = new grammer_info("expression: variable ASSIGNOP logic_expression",(yyvsp[-2].grammerInfo)->text+"="+(yyvsp[0].grammerInfo)->text);
                if( (yyvsp[-2].grammerInfo)->type != (yyvsp[0].grammerInfo)->type ){
                    if( ((yyvsp[-2].grammerInfo)->type == _int_ && (yyvsp[0].grammerInfo)->type == _float_) || ((yyvsp[-2].grammerInfo)->type==_float_&&(yyvsp[0].grammerInfo)->type==_int_) ){
                        (yyval.grammerInfo)->type = (yyvsp[-2].grammerInfo)->type; // type conversion 
                    }
                    else {
                        writeError((yyvsp[-1].symbolInfo)->getName()+" operator ,"+"type mismatch "+(yyvsp[-2].grammerInfo)->type+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->type);
                        (yyval.grammerInfo)->type = _unknown_;
                    }
                }
                free((yyvsp[-2].grammerInfo)); free((yyvsp[-1].symbolInfo)); free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2719 "y.tab.c"
    break;

  case 49: /* variable: ID  */
#line 523 "parser.y"
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
                free((yyvsp[0].symbolInfo));

                writeLog("variable: ID",(yyval.grammerInfo)->text);
            }
#line 2738 "y.tab.c"
    break;

  case 50: /* variable: ID LTHIRD expression RTHIRD  */
#line 537 "parser.y"
                                          {
                (yyval.grammerInfo) = new grammer_info("variable: ID LTHIRD expression RTHIRD",(yyvsp[-3].symbolInfo)->getName()+"["+(yyvsp[-1].grammerInfo)->text+"]");
                symbol* foundSymbol = symbolTable->lookup((yyvsp[-3].symbolInfo)->getName());
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
                }

                if( (yyvsp[-1].grammerInfo)->type != _int_ ){
                    writeError("expression inside third brackets not an integer");
                }
                
                free((yyvsp[-3].symbolInfo)); free((yyvsp[-1].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 2767 "y.tab.c"
    break;

  case 51: /* logic_expression: rel_expression  */
#line 562 "parser.y"
                                   {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->name = "logic_expression: rel_expression";
                        free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2779 "y.tab.c"
    break;

  case 52: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 569 "parser.y"
                                                                    {
                        (yyval.grammerInfo) = new grammer_info("logic_expression: rel_expression LOGICOP rel_expression",(yyvsp[-2].grammerInfo)->text+" "+(yyvsp[-1].symbolInfo)->getName()+" "+(yyvsp[0].grammerInfo)->text);
                        if( (yyvsp[-2].grammerInfo)->type != _int_ || (yyvsp[0].grammerInfo)->type != _int_ )
                            writeError("operands of LOGICOP must be integers");    
                        (yyval.grammerInfo)->type = _int_;
                        free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2793 "y.tab.c"
    break;

  case 53: /* rel_expression: simple_expression  */
#line 579 "parser.y"
                                      {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->name = "rel_expression: simple_expression";
                        free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2805 "y.tab.c"
    break;

  case 54: /* rel_expression: simple_expression RELOP simple_expression  */
#line 586 "parser.y"
                                                                        {
                        (yyval.grammerInfo) = new grammer_info("rel_expression: simple_expression RELOP simple_expression",(yyvsp[-2].grammerInfo)->text+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = _int_;
                        free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2817 "y.tab.c"
    break;

  case 55: /* simple_expression: term  */
#line 594 "parser.y"
                         {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->name = "simple_expression: term"; 
                        free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2829 "y.tab.c"
    break;

  case 56: /* simple_expression: simple_expression ADDOP term  */
#line 601 "parser.y"
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

                        free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2851 "y.tab.c"
    break;

  case 57: /* term: unary_expression  */
#line 619 "parser.y"
                         {
            (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
            (yyval.grammerInfo)->name = "term: unary_expression";
            free((yyvsp[0].grammerInfo));
            
            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 2863 "y.tab.c"
    break;

  case 58: /* term: term MULOP unary_expression  */
#line 626 "parser.y"
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

            free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text); 
        }
#line 2890 "y.tab.c"
    break;

  case 59: /* unary_expression: ADDOP unary_expression  */
#line 649 "parser.y"
                                           {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->text = string((yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->name = "unary_expression: ADDOP unary_expression";
                        free((yyvsp[-1].symbolInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2903 "y.tab.c"
    break;

  case 60: /* unary_expression: NOT unary_expression  */
#line 657 "parser.y"
                                                  {
                        (yyval.grammerInfo) = new grammer_info("unary_expression: NOT unary_expression",(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].grammerInfo)->text);
                        (yyval.grammerInfo)->type = _int_;
                        free((yyvsp[-1].symbolInfo)); free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2915 "y.tab.c"
    break;

  case 61: /* unary_expression: factor  */
#line 664 "parser.y"
                                     {
                        (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
                        (yyval.grammerInfo)->name = "unary_expression: factor"; 
                        free((yyvsp[0].grammerInfo));

                        writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                    }
#line 2927 "y.tab.c"
    break;

  case 62: /* factor: variable  */
#line 673 "parser.y"
                 {
            (yyval.grammerInfo) = new grammer_info(*(yyvsp[0].grammerInfo));
            (yyval.grammerInfo)->name = "factor: variable"; 
            free((yyvsp[0].grammerInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 2939 "y.tab.c"
    break;

  case 63: /* factor: ID LPAREN argument_list RPAREN  */
#line 680 "parser.y"
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
            free((yyvsp[-3].symbolInfo)); free((yyvsp[-1].grammerInfo)); 

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 2971 "y.tab.c"
    break;

  case 64: /* factor: LPAREN expression RPAREN  */
#line 707 "parser.y"
                                       {
            (yyval.grammerInfo) = new grammer_info("factor: LPAREN expression RPAREN","("+(yyvsp[-1].grammerInfo)->text+")");
            (yyval.grammerInfo)->type = (yyvsp[-1].grammerInfo)->type;
            free((yyvsp[-1].grammerInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 2983 "y.tab.c"
    break;

  case 65: /* factor: CONST_INT  */
#line 714 "parser.y"
                        {
            (yyval.grammerInfo) = new grammer_info("factor: CONST_INT",(yyvsp[0].symbolInfo)->getName());
            (yyval.grammerInfo)->type = _int_;
            free((yyvsp[0].symbolInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);  
        }
#line 2995 "y.tab.c"
    break;

  case 66: /* factor: CONST_FLOAT  */
#line 721 "parser.y"
                          {
            (yyval.grammerInfo) = new grammer_info("factor: CONST_FLOAT",(yyvsp[0].symbolInfo)->getName());
            (yyval.grammerInfo)->type = _float_;
            free((yyvsp[0].symbolInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3007 "y.tab.c"
    break;

  case 67: /* factor: variable INCOP  */
#line 728 "parser.y"
                             {
            (yyval.grammerInfo) = new grammer_info("factor: variable INCOP",(yyvsp[-1].grammerInfo)->text+"++");
            (yyval.grammerInfo)->type = (yyvsp[-1].grammerInfo)->type ;
            free((yyvsp[-1].grammerInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3019 "y.tab.c"
    break;

  case 68: /* factor: variable DECOP  */
#line 735 "parser.y"
                             {
            (yyval.grammerInfo) = new grammer_info("factor: variable DECOP",(yyvsp[-1].grammerInfo)->text+"--");
            (yyval.grammerInfo)->type = (yyvsp[-1].grammerInfo)->type ;
            free((yyvsp[-1].grammerInfo));

            writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
        }
#line 3031 "y.tab.c"
    break;

  case 69: /* argument_list: arguments  */
#line 744 "parser.y"
                          {
                    (yyval.grammerInfo) = new grammer_info("argument_list: arguments",(yyvsp[0].grammerInfo)->text);
                    (yyval.grammerInfo)->ids = (yyvsp[0].grammerInfo)->ids;
                    free((yyvsp[0].grammerInfo));

                    writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
                }
#line 3043 "y.tab.c"
    break;

  case 70: /* arguments: arguments COMMA logic_expression  */
#line 753 "parser.y"
                                             {
                (yyval.grammerInfo) = new grammer_info("arguments: arguments COMMA logic_expression",(yyvsp[-2].grammerInfo)->text+","+(yyvsp[0].grammerInfo)->text);
                (yyval.grammerInfo)->ids = (yyvsp[-2].grammerInfo)->ids;
                (yyval.grammerInfo)->ids.push_back({"arg",(yyvsp[0].grammerInfo)->type,(yyvsp[0].grammerInfo)->array?1:-1});
                free((yyvsp[-2].grammerInfo)); free((yyvsp[0].grammerInfo));

                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 3056 "y.tab.c"
    break;

  case 71: /* arguments: logic_expression  */
#line 761 "parser.y"
                                  {
                (yyval.grammerInfo) = new grammer_info("arguments: logic_expression",(yyvsp[0].grammerInfo)->text);
                (yyval.grammerInfo)->ids.push_back({"argument",(yyvsp[0].grammerInfo)->type,(yyvsp[0].grammerInfo)->array?1:-1});
                free((yyvsp[0].grammerInfo));
                
                writeLog((yyval.grammerInfo)->name,(yyval.grammerInfo)->text);
            }
#line 3068 "y.tab.c"
    break;


#line 3072 "y.tab.c"

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

#line 770 "parser.y"


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

    activeFunctions.push(dummySymbol);
    
    yyin = fp;

    yyparse();

    fclose(fp);
    // delete symbolTable;
    free(symbolTable);
    free(dummySymbol) ;
    free(declaredFunctions);
    logfile.close();
    errorfile.close();
    return 0;
}
