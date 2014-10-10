
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "gramC.y"

#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "treewalk.h"
#include "tabelasimbolos-declaracoes.h"
#include "tabelasimbolos-funcoes.h"
#include "tabelasimbolos-funcoes-parametros.h"
#include "tabelasimbolos-estruturas.h"
#include "tabelasimbolos-estruturas-declaracoes.h"
#include "tabelasimbolos-estruturas-funcoes.h"
#include "tabelasimbolos-estruturas-funcoes-parametros.h"

extern "C"{ 
  extern int yyerror(char*); 
  extern int yylex(); 
  
} 
Ast* ast;
TabelaVariaveis *raizVariaveis;
TabelaFuncoes *raizFuncoes;
int escopo;
int erro;
//char *nomefuncao;
int ordem;

#include "funcoesauxiliares.h"


/* Line 189 of yacc.c  */
#line 104 "gramC.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPEDEF = 283,
     EXTERN = 284,
     STATIC = 285,
     AUTO = 286,
     REGISTER = 287,
     CHAR = 288,
     SHORT = 289,
     INT = 290,
     LONG = 291,
     SIGNED = 292,
     UNSIGNED = 293,
     FLOAT = 294,
     DOUBLE = 295,
     CONST = 296,
     VOLATILE = 297,
     VOID = 298,
     STRUCT = 299,
     UNION = 300,
     ENUM = 301,
     ELLIPSIS = 302,
     CASE = 303,
     DEFAULT = 304,
     IF = 305,
     ELSE = 306,
     SWITCH = 307,
     WHILE = 308,
     DO = 309,
     FOR = 310,
     GOTO = 311,
     CONTINUE = 312,
     BREAK = 313,
     RETURN = 314,
     STRUCT_TYPE = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 32 "gramC.y"

Ast* ast;
            int type;
char *idname;
int line;



/* Line 214 of yacc.c  */
#line 209 "gramC.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 221 "gramC.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  146
/* YYNRULES -- Number of rules.  */
#define YYNRULES  294
/* YYNRULES -- Number of states.  */
#define YYNSTATES  434

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    77,    69,     2,
      61,    62,    70,    72,    68,    73,    67,    71,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,    83,
      74,    84,    75,    81,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,    80,    64,    76,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    51,    53,    55,    57,
      59,    61,    63,    65,    67,    69,    71,    73,    75,    77,
      79,    81,    83,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   103,   105,   107,   109,   111,   113,   115,   117,
     119,   121,   123,   125,   127,   129,   131,   133,   135,   137,
     139,   141,   143,   145,   147,   149,   151,   153,   155,   157,
     159,   161,   163,   165,   167,   169,   172,   174,   176,   178,
     182,   184,   189,   193,   198,   202,   206,   209,   212,   214,
     218,   220,   223,   226,   229,   232,   237,   239,   241,   243,
     245,   247,   249,   251,   256,   258,   262,   266,   270,   272,
     276,   280,   282,   286,   290,   292,   296,   300,   304,   308,
     310,   314,   318,   320,   324,   326,   330,   332,   336,   338,
     342,   344,   348,   350,   356,   358,   362,   364,   366,   368,
     370,   372,   374,   376,   378,   380,   382,   384,   386,   390,
     392,   395,   399,   401,   404,   406,   409,   411,   414,   416,
     420,   422,   426,   428,   430,   432,   434,   436,   438,   440,
     442,   444,   446,   448,   450,   452,   454,   456,   458,   460,
     466,   471,   474,   476,   478,   480,   483,   487,   490,   492,
     495,   497,   499,   503,   505,   508,   512,   517,   523,   526,
     528,   532,   534,   538,   540,   542,   545,   547,   549,   553,
     558,   562,   567,   572,   576,   578,   581,   584,   588,   590,
     593,   595,   599,   601,   605,   608,   611,   613,   615,   619,
     621,   624,   626,   628,   631,   635,   638,   642,   646,   651,
     654,   658,   662,   667,   669,   673,   678,   680,   684,   686,
     688,   690,   692,   694,   696,   700,   705,   709,   712,   716,
     720,   725,   727,   730,   732,   735,   737,   740,   746,   754,
     760,   766,   774,   781,   789,   793,   796,   799,   802,   806,
     808,   810,   815,   819,   823
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     168,     0,    -1,     3,    -1,     4,    -1,     5,    -1,     7,
      -1,    12,    -1,    13,    -1,    14,    -1,    15,    -1,     8,
      -1,     9,    -1,    10,    -1,    11,    -1,    25,    -1,    18,
      -1,    24,    -1,    19,    -1,    26,    -1,    20,    -1,    27,
      -1,    21,    -1,    22,    -1,    23,    -1,     6,    -1,    16,
      -1,    17,    -1,    29,    -1,    28,    -1,    32,    -1,    31,
      -1,    30,    -1,    60,    -1,    38,    -1,    33,    -1,    39,
      -1,    34,    -1,    43,    -1,    35,    -1,    37,    -1,    36,
      -1,    40,    -1,    44,    -1,    45,    -1,    46,    -1,    41,
      -1,    42,    -1,    47,    -1,    49,    -1,    48,    -1,    52,
      -1,    50,    -1,    51,    -1,    53,    -1,    54,    -1,    55,
      -1,    57,    -1,    58,    -1,    56,    -1,    59,    -1,    61,
      -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,    66,
      -1,    67,    -1,    68,    -1,    69,    -1,    70,    -1,    71,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,   229,    -1,   168,
     229,    -1,    86,    -1,    87,    -1,    88,    -1,   144,   188,
     145,    -1,   169,    -1,   170,   148,   188,   149,    -1,   170,
     144,   145,    -1,   170,   144,   171,   145,    -1,   170,   150,
      86,    -1,   170,    89,    86,    -1,   170,    94,    -1,   170,
      95,    -1,   186,    -1,   171,   151,   186,    -1,   170,    -1,
      94,   172,    -1,    95,   172,    -1,   173,   174,    -1,   108,
     172,    -1,   108,   144,   215,   145,    -1,   152,    -1,   153,
      -1,   155,    -1,   156,    -1,   159,    -1,   161,    -1,   172,
      -1,   144,   215,   145,   174,    -1,   174,    -1,   175,   153,
     174,    -1,   175,   154,   174,    -1,   175,   160,   174,    -1,
     175,    -1,   176,   155,   175,    -1,   176,   156,   175,    -1,
     176,    -1,   177,    96,   176,    -1,   177,    97,   176,    -1,
     177,    -1,   178,   157,   177,    -1,   178,   158,   177,    -1,
     178,    90,   177,    -1,   178,    91,   177,    -1,   178,    -1,
     179,    92,   178,    -1,   179,    93,   178,    -1,   179,    -1,
     180,   152,   179,    -1,   180,    -1,   181,   162,   180,    -1,
     181,    -1,   182,   163,   181,    -1,   182,    -1,   183,   109,
     182,    -1,   183,    -1,   184,   110,   183,    -1,   184,    -1,
     184,   164,   188,   165,   185,    -1,   185,    -1,   172,   187,
     186,    -1,   167,    -1,    99,    -1,   101,    -1,   103,    -1,
     105,    -1,   106,    -1,   107,    -1,   100,    -1,    98,    -1,
     102,    -1,   104,    -1,   186,    -1,   188,   151,   186,    -1,
     185,    -1,   191,   166,    -1,   191,   192,   166,    -1,   194,
      -1,   194,   191,    -1,   195,    -1,   195,   191,    -1,   206,
      -1,   206,   191,    -1,   193,    -1,   192,   151,   193,    -1,
     207,    -1,   207,   167,   218,    -1,   112,    -1,   111,    -1,
     115,    -1,   114,    -1,   113,    -1,   121,    -1,   118,    -1,
     120,    -1,   122,    -1,   124,    -1,   119,    -1,   125,    -1,
     123,    -1,   117,    -1,   196,    -1,   203,    -1,   116,    -1,
     197,    86,   146,   198,   147,    -1,   197,   146,   198,   147,
      -1,   197,    86,    -1,   126,    -1,   127,    -1,   199,    -1,
     198,   199,    -1,   200,   201,   166,    -1,   195,   200,    -1,
     195,    -1,   206,   200,    -1,   206,    -1,   202,    -1,   201,
     151,   202,    -1,   207,    -1,   165,   189,    -1,   207,   165,
     189,    -1,   128,   146,   204,   147,    -1,   128,    86,   146,
     204,   147,    -1,   128,    86,    -1,   205,    -1,   204,   151,
     205,    -1,    86,    -1,    86,   167,   189,    -1,   129,    -1,
     130,    -1,   209,   208,    -1,   208,    -1,    86,    -1,    61,
     207,   145,    -1,   208,   148,   189,   149,    -1,   208,   148,
     149,    -1,   208,   144,   211,   145,    -1,   208,   144,   214,
     145,    -1,   208,   144,   145,    -1,   153,    -1,   153,   210,
      -1,   153,   209,    -1,   153,   210,   209,    -1,   206,    -1,
     210,   206,    -1,   212,    -1,   212,   166,   131,    -1,   213,
      -1,   212,   151,   213,    -1,   191,   207,    -1,   191,   216,
      -1,   191,    -1,    86,    -1,   214,   151,    86,    -1,   200,
      -1,   200,   216,    -1,   209,    -1,   217,    -1,   209,   217,
      -1,    61,   216,   145,    -1,   148,   149,    -1,   148,   189,
     149,    -1,   217,   148,   149,    -1,   217,   148,   189,   149,
      -1,   144,   145,    -1,   144,   211,   145,    -1,   217,   144,
     145,    -1,   217,   144,   211,   145,    -1,   186,    -1,   146,
     219,   147,    -1,   146,   219,   151,   147,    -1,   218,    -1,
     219,   151,   218,    -1,   221,    -1,   222,    -1,   225,    -1,
     226,    -1,   227,    -1,   228,    -1,    86,   165,   220,    -1,
     133,   189,   165,   220,    -1,   132,   165,   220,    -1,   146,
     147,    -1,   146,   224,   147,    -1,   146,   223,   147,    -1,
     146,   223,   224,   147,    -1,   190,    -1,   223,   190,    -1,
     220,    -1,   224,   220,    -1,   166,    -1,   188,   166,    -1,
     135,   144,   188,   145,   220,    -1,   135,   144,   188,   145,
     220,   136,   220,    -1,   134,   144,   188,   145,   220,    -1,
     137,   144,   188,   145,   220,    -1,   138,   220,   137,   144,
     188,   145,   166,    -1,   139,   144,   225,   225,   145,   220,
      -1,   139,   144,   225,   225,   188,   145,   220,    -1,   142,
      86,   166,    -1,   140,   166,    -1,   141,   166,    -1,   143,
     166,    -1,   143,   188,   166,    -1,   230,    -1,   190,    -1,
     191,   207,   223,   222,    -1,   191,   207,   222,    -1,   207,
     223,   222,    -1,   207,   222,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   144,   156,   167,   177,   187,   197,   207,
     217,   227,   237,   247,   257,   267,   277,   287,   297,   307,
     317,   327,   337,   347,   357,   367,   377,   387,   397,   407,
     417,   427,   437,   447,   457,   467,   477,   487,   497,   508,
     518,   528,   538,   548,   558,   568,   578,   588,   598,   608,
     618,   628,   638,   648,   658,   668,   679,   690,   701,   712,
     721,   731,   741,   751,   761,   771,   781,   791,   801,   811,
     821,   831,   841,   851,   861,   871,   881,   891,   901,   911,
     921,   931,   941,   952,   964,   972,   984,   991,   998,  1005,
    1017,  1024,  1034,  1043,  1053,  1062,  1071,  1079,  1090,  1097,
    1109,  1116,  1124,  1132,  1140,  1148,  1161,  1168,  1175,  1182,
    1189,  1196,  1206,  1213,  1226,  1233,  1242,  1251,  1263,  1270,
    1279,  1291,  1298,  1307,  1319,  1326,  1335,  1344,  1353,  1365,
    1372,  1381,  1393,  1400,  1412,  1419,  1431,  1438,  1450,  1457,
    1469,  1476,  1488,  1495,  1509,  1516,  1528,  1535,  1542,  1549,
    1556,  1563,  1570,  1577,  1584,  1591,  1598,  1608,  1615,  1627,
    1637,  1646,  1659,  1666,  1674,  1682,  1690,  1697,  1708,  1716,
    1728,  1736,  1748,  1755,  1762,  1769,  1776,  1786,  1793,  1800,
    1807,  1815,  1822,  1829,  1836,  1843,  1850,  1857,  1864,  1874,
    1885,  1895,  1906,  1913,  1923,  1930,  1941,  1953,  1961,  1968,
    1976,  1986,  1993,  2005,  2012,  2020,  2032,  2042,  2053,  2064,
    2071,  2083,  2090,  2102,  2109,  2119,  2127,  2138,  2146,  2161,
    2171,  2180,  2190,  2200,  2212,  2219,  2227,  2235,  2247,  2254,
    2266,  2273,  2285,  2292,  2304,  2312,  2320,  2330,  2337,  2349,
    2356,  2368,  2375,  2382,  2393,  2407,  2415,  2424,  2433,  2443,
    2451,  2460,  2469,  2482,  2489,  2498,  2511,  2518,  2530,  2537,
    2544,  2551,  2558,  2565,  2575,  2584,  2594,  2606,  2614,  2623,
    2632,  2645,  2652,  2663,  2670,  2681,  2688,  2699,  2710,  2723,
    2737,  2748,  2761,  2773,  2789,  2798,  2806,  2814,  2822,  2836,
    2843,  2854,  2864,  2873,  2882
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT",
  "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "STRUCT_TYPE", "'('", "')'", "'{'", "'}'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'/'", "'+'", "'-'", "'<'",
  "'>'", "'~'", "'%'", "'!'", "'^'", "'|'", "'?'", "':'", "';'", "'='",
  "$accept", "identifier", "constant", "string_literal", "ptr_op", "le_op",
  "ge_op", "eq_op", "ne_op", "inc_op", "dec_op", "left_op", "right_op",
  "and_assign", "mul_assign", "right_assign", "div_assign", "xor_assign",
  "mod_assign", "or_assign", "add_assign", "sub_assign", "left_assign",
  "sizeof", "and_op", "or_op", "extern", "typedef", "register", "auto",
  "static", "struct_type", "unsigned", "char", "float", "short", "void",
  "int", "signed", "long", "double", "struct", "union", "enum", "const",
  "volatile", "ellipsis", "default", "case", "switch", "if", "else",
  "while", "do", "for", "continue", "break", "goto", "return", "lparen",
  "rparen", "lkey", "rkey", "lbracket", "rbracket", "point", "comma",
  "and_sign", "mul_sign", "div_sign", "plus_sign", "minus_sign",
  "less_sign", "great_sign", "tilde", "percent", "exclamation_sign",
  "caret", "vertical_bar", "question", "colon", "semicolon", "equal",
  "translation_unit", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "external_declaration", "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,   123,   125,    91,    93,    46,    44,    38,
      42,    47,    43,    45,    60,    62,   126,    37,    33,    94,
     124,    63,    58,    59,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   168,   169,   169,   169,   169,
     170,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     172,   172,   172,   172,   172,   172,   173,   173,   173,   173,
     173,   173,   174,   174,   175,   175,   175,   175,   176,   176,
     176,   177,   177,   177,   178,   178,   178,   178,   178,   179,
     179,   179,   180,   180,   181,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   186,   186,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   188,   188,   189,
     190,   190,   191,   191,   191,   191,   191,   191,   192,   192,
     193,   193,   194,   194,   194,   194,   194,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   196,
     196,   196,   197,   197,   198,   198,   199,   200,   200,   200,
     200,   201,   201,   202,   202,   202,   203,   203,   203,   204,
     204,   205,   205,   206,   206,   207,   207,   208,   208,   208,
     208,   208,   208,   208,   209,   209,   209,   209,   210,   210,
     211,   211,   212,   212,   213,   213,   213,   214,   214,   215,
     215,   216,   216,   216,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   218,   218,   218,   219,   219,   220,   220,
     220,   220,   220,   220,   221,   221,   221,   222,   222,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   226,   226,
     227,   227,   227,   227,   228,   228,   228,   228,   228,   229,
     229,   230,   230,   230,   230
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     3,
       1,     4,     3,     4,     3,     3,     2,     2,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     2,     3,     2,     1,     2,
       1,     1,     3,     1,     2,     3,     4,     5,     2,     1,
       3,     1,     3,     1,     1,     2,     1,     1,     3,     4,
       3,     4,     4,     3,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     2,     1,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       1,     4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     2,    28,    27,    31,    30,    29,    34,    36,    38,
      40,    39,    33,    35,    41,    45,    46,    37,    42,    43,
      44,    32,     0,    69,   217,   173,   172,   176,   175,   174,
     188,   185,   178,   182,   179,   177,   180,   184,   181,   183,
     192,   193,     0,   213,   214,   224,     0,   290,     0,   162,
     164,   186,     0,   187,   166,     0,   216,     0,    84,   289,
       0,    62,   208,     0,   228,   226,   225,     1,    85,    82,
     160,     0,   168,   170,   163,   165,   191,     0,   167,     0,
     271,     0,   294,     0,    60,    64,     0,     0,   215,    61,
     218,     0,   211,     0,   209,   229,   227,    67,     0,   161,
      83,     0,   292,     0,     0,   198,     0,   194,     0,   200,
       3,     4,    24,    10,    11,    49,    48,    51,    50,    53,
      54,    55,    58,    56,    57,    59,    63,    68,    71,    72,
      75,    77,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     267,   106,   107,   108,   109,   110,   111,   275,    90,   100,
     112,     0,   114,   118,   121,   124,   129,   132,   134,   136,
     138,   140,   142,   144,   157,     0,   273,   258,   259,     0,
       0,   260,   261,   262,   263,   170,   272,   293,   237,   223,
     236,     0,   230,   232,     0,    65,    86,   220,   112,   159,
       0,     0,     0,   206,     0,   169,     0,   253,   171,   291,
       0,   197,   190,   195,    81,     0,     0,   201,   203,   199,
       0,     0,   101,   102,     0,   104,     0,     0,     0,     0,
       0,     0,     0,   285,   286,     0,   287,     0,     0,   239,
       0,     5,    66,     0,    96,    97,     0,     0,     0,    15,
      17,    19,    21,    22,    23,    16,    14,    18,    20,   154,
     147,   153,   148,   155,   149,   156,   150,   151,   152,   146,
       0,   103,    70,    76,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     6,     7,    73,    74,     0,     0,     0,
       0,     8,     9,     0,     0,     0,    78,     0,    79,     0,
      25,     0,    26,    80,     0,     0,     0,   276,   269,     0,
     268,   274,    60,     0,     0,   234,   241,   235,   242,   221,
       0,     0,   222,     0,   219,   207,   212,   210,   256,     0,
     189,   204,     0,   196,     0,   264,     0,   266,     0,     0,
       0,     0,     0,     0,   284,   288,    89,    60,   241,   240,
       0,    95,    92,     0,    98,     0,    94,   145,   115,   116,
     117,   119,   120,   122,   123,   127,   128,   125,   126,   130,
     131,   133,   135,   137,   139,   141,     0,   158,   270,     0,
     249,     0,   245,     0,   243,     0,     0,   233,    47,   231,
     238,   254,     0,   202,   205,   105,   265,     0,     0,     0,
       0,     0,   113,    93,     0,    91,     0,   244,   250,   246,
     251,     0,   247,     0,   255,   257,   279,   277,   280,     0,
       0,     0,    99,   143,   252,   248,    52,     0,     0,   282,
       0,   278,   281,   283
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   196,   133,   134,   243,   287,   288,   293,   294,   135,
     136,   281,   282,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   137,   301,   304,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   389,   138,   139,   140,
     141,   427,   142,   143,   144,   145,   146,   147,   148,   149,
      90,    79,   150,   314,   197,   248,   306,   151,   152,   275,
     153,   154,   289,   290,   155,   276,   156,   297,   299,   305,
     215,   157,   101,    46,   158,   159,   353,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   270,   175,   200,    80,    81,    71,    72,    49,
      50,    51,    52,   106,   107,   108,   216,   217,    53,    93,
      94,    54,    55,    56,    57,    66,   191,   192,   193,   194,
     240,   379,   318,   208,   329,   176,   177,   178,    83,   180,
     181,   182,   183,   184,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -285
static const yytype_int16 yypact[] =
{
     941,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,    79,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,    33,  -285,  -285,   200,   897,  -285,    56,  1091,
    1091,  -285,    33,  -285,  1091,  1020,   -21,    16,  -285,  -285,
     -17,  -285,   -36,    61,  -285,  -285,   200,  -285,  -285,  -285,
    -285,   -34,  -285,   585,  -285,  -285,   -36,  1151,  -285,   526,
    -285,    56,  -285,  1020,  -285,  -285,   985,   758,   -21,  -285,
    -285,    61,   -14,     4,  -285,  -285,  -285,  -285,    79,  -285,
    -285,   806,  -285,  1020,  1151,  1151,  1119,  -285,    66,  1151,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,   -15,  -285,  -285,   844,   844,   844,   -15,   844,
      24,    24,    24,   638,    24,    35,    35,    61,   467,   714,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   269,
     468,   844,  -285,   116,    78,   150,   205,   167,    38,    49,
      51,   136,    14,  -285,  -285,   -34,  -285,  -285,  -285,   526,
     602,  -285,  -285,  -285,  -285,   -14,  -285,  -285,  -285,  -285,
     127,   -17,   -34,  -285,   -30,  -285,  -285,  -285,  -285,  -285,
      91,     4,   844,  -285,    61,  -285,   806,  -285,  -285,  -285,
    1119,  -285,  -285,  -285,  -285,   844,   -34,  -285,   -15,  -285,
     638,   844,  -285,  -285,   714,  -285,   638,   -15,   844,   844,
     844,   115,   467,  -285,  -285,    35,  -285,   -34,   -30,   108,
     -17,  -285,  -285,    61,  -285,  -285,   834,   844,    61,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
     844,  -285,  -285,  -285,   844,   844,   844,   844,   844,  -285,
    -285,   844,   844,  -285,  -285,  -285,  -285,   844,   844,   844,
     844,  -285,  -285,   844,   844,   844,  -285,   844,  -285,   844,
    -285,   844,  -285,  -285,   844,   844,   844,  -285,  -285,   602,
    -285,  -285,   127,  1056,   758,  -285,   160,  -285,   -21,  -285,
    1091,   125,  -285,    61,  -285,  -285,  -285,  -285,  -285,     4,
    -285,  -285,    66,  -285,   844,  -285,   -17,  -285,   638,   -30,
     -30,   -30,    24,   467,  -285,  -285,  -285,   108,    77,  -285,
     844,  -285,  -285,   -30,  -285,    22,  -285,  -285,  -285,  -285,
    -285,   116,   116,    78,    78,   150,   150,   150,   150,   205,
     205,   167,    38,    49,    51,   136,    -7,  -285,  -285,   -17,
    -285,   -17,  -285,    91,   -21,  1056,   758,  -285,  -285,  -285,
    -285,  -285,   730,  -285,  -285,  -285,  -285,   638,   638,   638,
     844,   834,  -285,  -285,   844,  -285,   844,  -285,  -285,  -285,
    -285,   -17,  -285,    91,  -285,  -285,  -285,   123,  -285,   -30,
     638,   -30,  -285,  -285,  -285,  -285,  -285,   638,    35,  -285,
     638,  -285,  -285,  -285
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -285,     0,  -285,  -285,  -285,  -285,  -285,  -285,  -285,    44,
      70,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,     5,  -285,  -285,  -285,  -285,  -285,  -285,    65,
     -82,   -39,   -35,   -49,  -120,  -285,    21,  -162,     8,  -285,
    -152,  -136,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,
    -114,   -46,   -77,  -285,  -285,  -285,  -285,   147,  -285,  -151,
     -38,   -32,     2,    17,  -119,   -65,   -53,   -57,   -48,  -285,
     -61,   -87,  -285,   236,  -118,   162,     1,  -285,   169,  -285,
     296,  -285,  -285,   168,   -90,     6,  -285,   -47,  -285,   184,
      84,    28,    -5,   -52,   -25,  -285,  -284,  -285,   -24,  -285,
      71,   -55,  -283,  -197,  -285,    80,  -285,   178,   -13,   119,
    -221,  -285,  -285,  -285,   255,  -285
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      24,    48,    70,    63,   189,    88,   295,    87,    45,   328,
     271,   343,   277,    77,   207,   202,   213,    60,   220,     1,
      65,   227,    24,    91,   226,    99,   199,    61,   278,   381,
      45,   302,    89,   384,    97,    70,     1,   104,    97,    87,
      84,    96,    62,    73,    85,    89,    24,    48,    24,    69,
      74,    75,    76,    45,    45,    78,    45,    24,   203,     1,
     103,    97,   206,    92,     1,   384,   179,   214,   126,     1,
     100,   212,    97,    64,    45,   214,   185,    22,   199,   132,
     324,    24,     1,   269,   326,    84,   188,   190,   195,    45,
      97,    92,    98,   185,    95,   303,    61,   331,    24,   233,
     234,   411,   236,   218,   334,   109,    45,   127,    24,   319,
     247,   211,   322,   338,   204,   219,    45,    22,    69,   207,
     213,    86,   401,   358,   359,   360,    23,    22,   296,   307,
       1,   298,   109,   109,   109,   317,    23,   109,   347,    69,
      22,   199,    85,   132,   308,   310,   321,   235,   214,    23,
     128,   129,   300,    86,   199,   239,   346,   195,   350,   354,
     279,   280,    47,     1,   352,   316,   325,   206,   119,   347,
     333,   274,   388,    85,   426,   330,   371,   109,    23,   132,
     132,   291,   292,   357,   349,   315,    23,   272,   312,   344,
      24,   345,    85,   273,   382,   415,   383,    23,    45,   402,
     221,   221,   224,   244,    92,   228,   229,   230,    47,   232,
     295,   277,   277,   320,   348,   323,   394,   283,   284,   377,
     132,   312,   204,   231,   246,    85,   132,   278,   278,   245,
     239,   380,   372,    82,   198,   405,   342,   332,   109,   361,
     362,    15,    16,   351,   374,   186,   373,    45,   356,   363,
     364,   102,   109,   199,   395,   313,   375,   397,   398,   399,
     311,   187,   406,   409,    88,   186,   412,   205,   413,   386,
      23,   403,   210,   199,   378,   201,   241,   113,   114,   285,
     286,   209,   222,   223,   225,   393,   198,   316,   327,   365,
     366,   367,   368,   425,   391,   336,   387,   407,   309,   408,
     335,    68,     0,   410,   313,   207,   337,    60,   198,   132,
     369,   370,    24,     0,   190,     0,    24,   422,     0,   420,
      45,   190,   348,   390,     0,   199,     0,   218,     0,   424,
      84,     0,    24,     0,    85,   386,   242,   428,   132,   430,
      45,   186,     0,     0,     0,   423,     0,     0,     0,   198,
     392,     0,     0,   206,     0,    45,     0,   414,     0,     0,
       0,     0,   198,     0,     0,     0,     0,     0,     0,   274,
     274,     0,     0,   105,   404,     0,     0,   313,     0,     0,
       0,   313,   432,   385,   237,   238,   190,     0,     0,   311,
       0,     0,     0,     0,     0,     0,     0,   132,   132,   132,
     105,   105,   105,     0,     0,   105,     0,   400,     0,     0,
       0,     0,   313,   313,     0,     0,     0,     0,   396,     0,
     132,   198,   198,   198,   198,   198,     0,   132,   198,   198,
     132,     0,     0,     0,   198,   198,   198,   198,     0,     0,
     198,   198,   198,     0,   198,   105,   198,     0,   198,   385,
       0,   198,     0,     0,     0,     0,     0,   238,     0,     0,
     238,   198,     0,     0,   339,   340,   341,     0,     0,     0,
       1,   110,   111,   112,     0,   113,   114,   416,   417,   418,
       0,   198,     0,   355,     0,     0,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,     0,   198,     0,     0,
     429,     0,     0,     0,     0,     0,   105,   431,     0,     0,
     433,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,    84,     1,
     110,   111,   112,   198,   113,   114,   127,    23,     0,   128,
     129,   376,     0,   130,     0,   131,     0,     0,     0,     0,
      69,     0,   100,   198,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,   115,   116,   117,     0,   118,   119,
     120,   121,   122,   123,   124,   125,    21,    84,     0,    61,
     126,     0,     0,     0,     0,   127,    23,     0,   128,   129,
       0,     0,   130,     0,   131,     1,   110,   111,   112,    69,
     113,   114,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,   419,   421,     0,     0,
       0,     1,   110,   111,   112,    21,   113,   114,    61,     0,
     115,   116,   117,     0,   118,   119,   120,   121,   122,   123,
     124,   125,     0,    84,     0,    61,   126,     0,     0,   100,
       0,   127,    23,     0,   128,   129,     0,     0,   130,     0,
     131,     0,     0,     0,     0,    69,   115,   116,   117,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,    84,
       0,    61,     0,     0,     0,     0,     0,   127,    23,     0,
     128,   129,     0,     0,   130,     0,   131,     1,   110,   111,
     112,    69,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,   110,   111,   112,     0,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,     1,   110,   111,   112,     0,   113,   114,     0,     0,
       0,     0,     0,     0,    21,    84,     0,     0,     0,     0,
       0,     0,     0,   127,    23,     0,   128,   129,     0,     0,
     130,    84,   131,    61,   126,     0,     0,     0,     0,   127,
      23,     0,   128,   129,     0,     0,   130,     0,   131,     1,
     110,   111,   112,     0,   113,   114,     0,     0,     0,    84,
       0,     0,     0,     0,   195,     0,     0,   127,    23,     0,
     128,   129,     0,     0,   130,     0,   131,     1,   110,   111,
     112,     0,   113,   114,     0,     0,     0,     1,   110,   111,
     112,     0,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,    61,
       0,     0,     0,     0,     0,   127,    23,     0,   128,   129,
       0,     0,   130,     0,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    89,    67,     0,     0,
       1,     0,     0,   127,    23,    84,   128,   129,     0,     0,
     130,     0,   131,   127,    23,     0,   128,   129,     0,     0,
     130,     0,   131,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    22,     0,
       0,     0,     0,     0,     0,     0,     0,    23,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,    23,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    89,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,    61,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,    89,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,   126,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21
};

static const yytype_int16 yycheck[] =
{
       0,     0,    48,    42,    86,    57,   168,    56,     0,   206,
     161,   232,   164,    52,   101,    92,   106,    22,   132,     3,
      45,   139,    22,    62,   138,    71,    87,    63,   164,   313,
      22,    17,    62,   316,    68,    81,     3,    76,    68,    88,
      61,    66,    42,    48,    65,    62,    46,    46,    48,    83,
      49,    50,    52,    45,    46,    54,    48,    57,    93,     3,
      73,    68,   101,    63,     3,   348,    79,    82,    64,     3,
      84,   106,    68,    45,    66,    82,    81,    61,   139,    79,
     200,    81,     3,   160,   202,    61,    86,    86,    66,    81,
      68,    91,    71,    98,    66,    81,    63,   215,    98,   145,
     146,   385,   148,   108,   218,    77,    98,    69,   108,   191,
     159,   105,   194,   227,    93,   109,   108,    61,    83,   206,
     210,    56,   343,   274,   275,   276,    70,    61,    79,   175,
       3,    80,   104,   105,   106,   190,    70,   109,    61,    83,
      61,   202,    65,   143,   179,   180,   192,   147,    82,    70,
      72,    73,    16,    88,   215,   149,   238,    66,   240,   246,
      10,    11,     0,     3,   246,   190,   201,   206,    53,    61,
     216,   163,    47,    65,    51,   210,   295,   149,    70,   179,
     180,    14,    15,   270,   239,   190,    70,    71,    61,   235,
     190,   237,    65,    77,   314,   392,   314,    70,   190,   350,
     135,   136,   137,   159,   204,   140,   141,   142,    46,   144,
     372,   363,   364,   192,   239,   194,   334,    12,    13,   306,
     220,    61,   201,   143,   159,    65,   226,   363,   364,   159,
     224,   313,   297,    55,    87,   355,   231,   216,   210,   277,
     278,    41,    42,   243,   301,    83,   299,   239,   248,   281,
     282,    73,   224,   314,   336,   190,   304,   339,   340,   341,
     180,    83,   376,   383,   316,   103,   386,    98,   386,   318,
      70,   353,   104,   334,   309,    91,     7,     8,     9,    74,
      75,   103,   135,   136,   137,   332,   139,   312,   204,   287,
     288,   289,   290,   413,   329,   224,   320,   379,   179,   381,
     220,    46,    -1,   385,   239,   392,   226,   312,   161,   309,
     293,   294,   312,    -1,   313,    -1,   316,   404,    -1,   401,
     312,   320,   347,   323,    -1,   386,    -1,   332,    -1,   411,
      61,    -1,   332,    -1,    65,   384,    67,   419,   338,   421,
     332,   179,    -1,    -1,    -1,   406,    -1,    -1,    -1,   202,
     329,    -1,    -1,   392,    -1,   347,    -1,   392,    -1,    -1,
      -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,    -1,   361,
     362,    -1,    -1,    77,   353,    -1,    -1,   312,    -1,    -1,
      -1,   316,   428,   318,   148,   149,   385,    -1,    -1,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,   398,   399,
     104,   105,   106,    -1,    -1,   109,    -1,   342,    -1,    -1,
      -1,    -1,   347,   348,    -1,    -1,    -1,    -1,   338,    -1,
     420,   274,   275,   276,   277,   278,    -1,   427,   281,   282,
     430,    -1,    -1,    -1,   287,   288,   289,   290,    -1,    -1,
     293,   294,   295,    -1,   297,   149,   299,    -1,   301,   384,
      -1,   304,    -1,    -1,    -1,    -1,    -1,   221,    -1,    -1,
     224,   314,    -1,    -1,   228,   229,   230,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,   397,   398,   399,
      -1,   334,    -1,   247,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,   350,    -1,    -1,
     420,    -1,    -1,    -1,    -1,    -1,   210,   427,    -1,    -1,
     430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,     3,
       4,     5,     6,   386,     8,     9,    69,    70,    -1,    72,
      73,   305,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,
      83,    -1,    84,   406,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    63,
      64,    -1,    -1,    -1,    -1,    69,    70,    -1,    72,    73,
      -1,    -1,    76,    -1,    78,     3,     4,     5,     6,    83,
       8,     9,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,   400,   401,    -1,    -1,
      -1,     3,     4,     5,     6,    60,     8,     9,    63,    -1,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    -1,    63,    64,    -1,    -1,    84,
      -1,    69,    70,    -1,    72,    73,    -1,    -1,    76,    -1,
      78,    -1,    -1,    -1,    -1,    83,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      72,    73,    -1,    -1,    76,    -1,    78,     3,     4,     5,
       6,    83,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    -1,    72,    73,    -1,    -1,
      76,    61,    78,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    -1,    72,    73,    -1,    -1,    76,    -1,    78,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    70,    -1,
      72,    73,    -1,    -1,    76,    -1,    78,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    72,    73,
      -1,    -1,    76,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,     0,    -1,    -1,
       3,    -1,    -1,    69,    70,    61,    72,    73,    -1,    -1,
      76,    -1,    78,    69,    70,    -1,    72,    73,    -1,    -1,
      76,    -1,    78,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    63,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    60,    61,    70,    86,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   153,   168,   190,   191,   194,
     195,   196,   197,   203,   206,   207,   208,   209,   229,   230,
     207,    63,    86,   146,   206,   209,   210,     0,   229,    83,
     166,   192,   193,   207,   191,   191,    86,   146,   191,   146,
     190,   191,   222,   223,    61,    65,   144,   148,   208,    62,
     145,   146,    86,   204,   205,   206,   209,    68,   151,   166,
      84,   167,   222,   223,   146,   195,   198,   199,   200,   206,
       4,     5,     6,     8,     9,    48,    49,    50,    52,    53,
      54,    55,    56,    57,    58,    59,    64,    69,    72,    73,
      76,    78,    86,    87,    88,    94,    95,   108,   132,   133,
     134,   135,   137,   138,   139,   140,   141,   142,   143,   144,
     147,   152,   153,   155,   156,   159,   161,   166,   169,   170,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   188,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   207,   190,   222,    86,   145,
     191,   211,   212,   213,   214,    66,    86,   149,   172,   185,
     189,   204,   167,   147,   151,   193,   146,   186,   218,   222,
     198,   200,   147,   199,    82,   165,   201,   202,   207,   200,
     165,   144,   172,   172,   144,   172,   165,   189,   144,   144,
     144,   220,   144,   166,   166,    86,   166,   188,   188,   200,
     215,     7,    67,    89,    94,    95,   144,   148,   150,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   167,
     187,   174,    71,    77,   153,   154,   160,   155,   156,    10,
      11,    96,    97,    12,    13,    74,    75,    90,    91,   157,
     158,    14,    15,    92,    93,   152,    79,   162,    80,   163,
      16,   109,    17,    81,   110,   164,   151,   166,   147,   224,
     147,   220,    61,   144,   148,   207,   209,   216,   217,   145,
     151,   166,   145,   151,   149,   147,   189,   205,   218,   219,
     147,   189,   151,   166,   165,   220,   215,   220,   165,   188,
     188,   188,   137,   225,   166,   166,   145,    61,   209,   216,
     145,    86,   145,   171,   186,   188,    86,   186,   174,   174,
     174,   175,   175,   176,   176,   177,   177,   177,   177,   178,
     178,   179,   180,   181,   182,   183,   188,   186,   147,   216,
     145,   211,   149,   189,   217,   144,   148,   213,    47,   131,
      86,   147,   151,   202,   189,   145,   220,   145,   145,   145,
     144,   225,   174,   145,   151,   149,   165,   145,   145,   149,
     145,   211,   149,   189,   147,   218,   220,   220,   220,   188,
     145,   188,   186,   185,   145,   149,    51,   136,   145,   220,
     145,   220,   166,   220
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 134 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(yylval.idname));
               strcpy(temp->text,yylval.idname); //yytext
               temp->value = 300; //symboltable
          //     printf("FOLHA: IDENTIFIER = '%s' %d \n",temp->text,temp->value);
               (yyval.ast) = temp;
            ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 145 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("CONSTANT"));
               strcpy(temp->text,"CONSTANT"); //yytext
         //      printf("\n\n\n%d\n\n\n",yylval.type);
               temp->value = yylval.type; //yylval
         //      printf("FOLHA: CONSTANT %d ",temp->value);
               (yyval.ast) = temp;
            ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 157 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STRING_LITERAL"));
               strcpy(temp->text,"STRING_LITERAL"); //yytext
               temp->value = 3; //string_literal
               (yyval.ast) = temp;
        //       printf("FOLHA: STRING_LITERAL %d ",temp->value);
            ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 168 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("PTR_OP"));
               strcpy(temp->text,"PTR_OP"); //yytext
               temp->value = 5; //ptr_op
               (yyval.ast) = temp;
           ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 178 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("LE_OP"));
               strcpy(temp->text,"GE_OP"); //yytext
               temp->value = 6; //ptr_op
               (yyval.ast) = temp;
           ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 188 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("GE_OP"));
               strcpy(temp->text,"GE_OP"); //yytext
               temp->value = 7; //ptr_op
               (yyval.ast) = temp;
           ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 198 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("EQ_OP"));
               strcpy(temp->text,"EQ_OP"); //yytext
               temp->value = 8; //ptr_op
               (yyval.ast) = temp;
           ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 208 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("NE_OP"));
               strcpy(temp->text,"NE_OP"); //yytext
               temp->value = 9; //ptr_op
               (yyval.ast) = temp;
           ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 218 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("INC_OP"));
               strcpy(temp->text,"INC_OP"); //yytext
               temp->value = 10; //INC_op
               (yyval.ast) = temp;
        ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 228 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("DEC_OP"));
               strcpy(temp->text,"DEC_OP"); //yytext
               temp->value = 11; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 238 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("LEFT_OPP"));
               strcpy(temp->text,"LEFT_OP"); //yytext
               temp->value = 12; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 248 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("RIGHT_OP"));
               strcpy(temp->text,"RIGHT_OP"); //yytext
               temp->value = 13; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 258 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("AND_ASSIGN"));
               strcpy(temp->text,"AND_ASSIGN"); //yytext
               temp->value = 14; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 268 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("MUL_ASSIGN"));
               strcpy(temp->text,"MUL_ASSIGN"); //yytext
               temp->value = 15; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 278 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("RIGHT_ASSIGN"));
               strcpy(temp->text,"RIGHT_ASSIGN"); //yytext
               temp->value = 16; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 288 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("DIV_ASSIGN"));
               strcpy(temp->text,"DIV_ASSIGN"); //yytext
               temp->value = 17; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 298 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("XOR_ASSIGN"));
               strcpy(temp->text,"XOR_ASSIGN"); //yytext
               temp->value = 18; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 308 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("MOD_ASSIGN"));
               strcpy(temp->text,"MOD_ASSIGN"); //yytext
               temp->value = 19; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 318 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("OR_ASSIGN"));
               strcpy(temp->text,"OR_ASSIGN"); //yytext
               temp->value = 20; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 328 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("ADD_ASSIGN"));
               strcpy(temp->text,"ADD_ASSIGN"); //yytext
               temp->value = 21; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 338 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SUB_ASSIGN"));
               strcpy(temp->text,"SUB_ASSIGN"); //yytext
               temp->value = 22; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 348 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("LEFT_ASSIGN"));
               strcpy(temp->text,"LEFT_ASSIGN"); //yytext
               temp->value = 23; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 358 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SIZEOF"));
               strcpy(temp->text,"SIZEOF"); //yytext
               temp->value = 24; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 368 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("AND_OP"));
               strcpy(temp->text,"AND_OP"); //yytext
               temp->value = 25; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 378 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("OR_OP"));
               strcpy(temp->text,"OR_OP"); //yytext
               temp->value = 26; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 388 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("EXTERN"));
               strcpy(temp->text,"EXTERN"); //yytext
               temp->value = 27; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 398 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("TYPEDEF"));
               strcpy(temp->text,"TYPEDEF"); //yytext
               temp->value = 28; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 408 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("REGISTER"));
               strcpy(temp->text,"REGISTER"); //yytext
               temp->value = 29; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 418 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("AUTO"));
               strcpy(temp->text,"AUTO"); //yytext
               temp->value = 30; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 428 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STATIC"));
               strcpy(temp->text,"STATIC"); //yytext
               temp->value = 31; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 438 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STRUCT_TYPE"));
               strcpy(temp->text,"STRUCT_TYPE"); //yytext
               temp->value = 32; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 448 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("UNSIGNED"));
               strcpy(temp->text,"UNSIGNED"); //yytext
               temp->value = 33; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 458 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("CHAR"));
               strcpy(temp->text,"CHAR"); //yytext
               temp->value = 34; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 468 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("FLOAT"));
               strcpy(temp->text,"FLOAT"); //yytext
               temp->value = 35; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 478 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SHORT"));
               strcpy(temp->text,"SHORT"); //yytext
               temp->value = 36; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 488 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("VOID"));
               strcpy(temp->text,"VOID"); //yytext
               temp->value = 37; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 498 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("INT"));
               strcpy(temp->text,"INT"); //yytext
               temp->value = 38; //ptr_op
              // printf("FOLHA: INT %d \n",temp->value);
               (yyval.ast) = temp;
       ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 509 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SIGNED"));
               strcpy(temp->text,"SIGNED"); //yytext
               temp->value = 39; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 519 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("LONG"));
               strcpy(temp->text,"LONG"); //yytext
               temp->value = 40; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 529 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STATIC"));
               strcpy(temp->text,"STATIC"); //yytext
               temp->value = 41; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 539 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("STRUCT"));
               strcpy(temp->text,"STRUCT"); //yytext
               temp->value = 42; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 549 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("UNION"));
               strcpy(temp->text,"UNION"); //yytext
               temp->value = 43; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 559 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("ENUM"));
               strcpy(temp->text,"ENUM"); //yytext
               temp->value = 44; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 569 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("VOLATILE"));
               strcpy(temp->text,"VOLATILE"); //yytext
               temp->value = 45; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 579 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("VOLATILE"));
               strcpy(temp->text,"VOLATILE"); //yytext
               temp->value = 46; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 589 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("ELLIPSIS"));
               strcpy(temp->text,"ELLIPSIS"); //yytext
               temp->value = 47; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 599 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("DEFAULT"));
               strcpy(temp->text,"DEFAULT"); //yytext
               temp->value = 48; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 609 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("CASE"));
               strcpy(temp->text,"CASE"); //yytext
               temp->value = 49; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 619 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("SWITCH"));
               strcpy(temp->text,"SWITCH"); //yytext
               temp->value = 50; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 629 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("IF"));
               strcpy(temp->text,"IF"); //yytext
               temp->value = 51; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 639 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("ELSE"));
               strcpy(temp->text,"ELSE"); //yytext
               temp->value = 52; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 649 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("WHILE"));
               strcpy(temp->text,"WHILE"); //yytext
               temp->value = 53; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 659 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("DO"));
               strcpy(temp->text,"DO"); //yytext
               temp->value = 54; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 669 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("FOR"));
               strcpy(temp->text,"FOR"); //yytext
               temp->value = 55; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 680 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("CONTINUE"));
               strcpy(temp->text,"CONTINUE"); //yytext
               temp->value = 56; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 691 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("BREAK"));
               strcpy(temp->text,"BREAK"); //yytext
               temp->value = 57; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 702 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("GOTO"));
               strcpy(temp->text,"GOTO"); //yytext
               temp->value = 58; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 713 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("RETURN"));
               strcpy(temp->text,"RETURN"); //yytext
               temp->value = 59; //ptr_op
               (yyval.ast) = temp;
       ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 722 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("("));
               strcpy(temp->text,"("); //yytext
               temp->value = 60; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 732 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(")"));
               strcpy(temp->text,")"); //yytext
               temp->value = 61; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 742 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("{"));
               strcpy(temp->text,"{"); //yytext
               temp->value = 62; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 752 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("}"));
               strcpy(temp->text,"}"); //yytext
               temp->value = 63; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 762 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("["));
               strcpy(temp->text,"["); //yytext
               temp->value = 64; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 772 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("]"));
               strcpy(temp->text,"]"); //yytext
               temp->value = 65; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 782 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("."));
               strcpy(temp->text,"."); //yytext
               temp->value = 66; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 792 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(","));
               strcpy(temp->text,","); //yytext
               temp->value = 67; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 802 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("&"));
               strcpy(temp->text,"&"); //yytext
               temp->value = 68; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 812 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("*"));
               strcpy(temp->text,"*"); //yytext
               temp->value = 69; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 822 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("/"));
               strcpy(temp->text,"/"); //yytext
               temp->value = 70; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 832 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("+"));
               strcpy(temp->text,"+"); //yytext
               temp->value = 71; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 842 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("-"));
               strcpy(temp->text,"-"); //yytext
               temp->value = 72; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 852 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("<"));
               strcpy(temp->text,"<"); //yytext
               temp->value = 73; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 862 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(">"));
               strcpy(temp->text,">"); //yytext
               temp->value = 74; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 872 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("~"));
               strcpy(temp->text,"~"); //yytext
               temp->value = 75; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 882 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("%"));
               strcpy(temp->text,"%"); //yytext
               temp->value = 76; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 892 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("!"));
               strcpy(temp->text,"!"); //yytext
               temp->value = 77; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 902 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("^"));
               strcpy(temp->text,"^"); //yytext
               temp->value = 78; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 912 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("|"));
               strcpy(temp->text,"|"); //yytext
               temp->value = 79; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 922 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof("?"));
               strcpy(temp->text,"?"); //yytext
               temp->value = 80; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 932 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(":"));
               strcpy(temp->text,":"); //yytext
               temp->value = 81; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 942 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(":"));
               strcpy(temp->text,";"); //yytext
               temp->value = 82; //lparen
           //    printf("FOLHA: ; %d \n",temp->value);
               (yyval.ast) = temp;
       ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 953 "gramC.y"
    {
               Folha *temp = new Folha();
               temp->text = (char *) malloc(sizeof(":"));
               strcpy(temp->text,"="); //yytext
               temp->value = 83; //lparen
               (yyval.ast) = temp;
       ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 965 "gramC.y"
    {
                    ast = new Ast();
                    ast->a = (yyvsp[(1) - (1)].ast);
                    ast->value = 84;
                 //   printf("translation_unit: external_declaration %d \n",ast->value);
                    (yyval.ast) = ast;                
              ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 973 "gramC.y"
    {
                    ast = new Ast();
                    ast->a = (yyvsp[(1) - (2)].ast);
                    ast->b = (yyvsp[(2) - (2)].ast);
                    ast->value = 85;
               //     printf("translation_unit: translation_unit external_declaration %d \n",ast->value);
                    (yyval.ast) = ast;      
              ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 985 "gramC.y"
    {/* printf("IDENTIFIER |"); */
                    PrimaryExpression *temp = new PrimaryExpression();
                    temp->a = (yyvsp[(1) - (1)].ast);
                    temp->value = 86;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 992 "gramC.y"
    {/* printf(" CONSTANT |"); */
                    PrimaryExpression *temp = new PrimaryExpression();
                    temp->a = (yyvsp[(1) - (1)].ast);
                    temp->value = 87;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 999 "gramC.y"
    {/* printf(" STRING_LITERAL |"); */
                    PrimaryExpression *temp = new PrimaryExpression();
                    temp->a = (yyvsp[(1) - (1)].ast);
                    temp->value = 88;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1006 "gramC.y"
    {/* printf(" '(' expression ')' | "); */
                    PrimaryExpression *temp = new PrimaryExpression();
                    temp->a = (yyvsp[(1) - (3)].ast);
                    temp->b = (yyvsp[(2) - (3)].ast);
                    temp->c = (yyvsp[(3) - (3)].ast);
                    temp->value = 89;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1018 "gramC.y"
    {
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 90;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1025 "gramC.y"
    {
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 91;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1035 "gramC.y"
    {/* printf("postfix_expression '(' ')' |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 92;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1044 "gramC.y"
    {/* printf("postfix_expression '(' argument_expression_list ')'  |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 93;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1054 "gramC.y"
    {/* printf("postfix_expression '.' IDENTIFIER |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 94;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1063 "gramC.y"
    {/* printf("postfix_expression PTR_OP IDENTIFIER  |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast); 
                  temp->value = 95;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1072 "gramC.y"
    {/* printf("postfix_expression INC_OP |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 96;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1080 "gramC.y"
    {/* printf("postfix_expression DEC_OP |"); */
                  PostfixExpression *temp = new PostfixExpression();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 97;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1091 "gramC.y"
    {/* printf("assignment_expression |"); */
                 ArgumentExpressionList *temp = new ArgumentExpressionList();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 98;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1098 "gramC.y"
    {/* printf("argument_expression_list ',' assignment_expression |"); */
                 ArgumentExpressionList *temp = new ArgumentExpressionList();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast); 
                 temp->value = 99;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1110 "gramC.y"
    {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 100;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1117 "gramC.y"
    {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = (yyvsp[(1) - (2)].ast);
               temp->b = (yyvsp[(2) - (2)].ast);
               temp->value = 101;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1125 "gramC.y"
    {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = (yyvsp[(1) - (2)].ast);
               temp->b = (yyvsp[(2) - (2)].ast);
               temp->value = 102;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1133 "gramC.y"
    {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = (yyvsp[(1) - (2)].ast);
               temp->b = (yyvsp[(2) - (2)].ast);
               temp->value = 103;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1141 "gramC.y"
    {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = (yyvsp[(1) - (2)].ast);
               temp->b = (yyvsp[(2) - (2)].ast);
               temp->value = 104;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1149 "gramC.y"
    {/* printf(" |"); */
               UnaryExpression *temp = new UnaryExpression();
               temp->a = (yyvsp[(1) - (4)].ast);
               temp->b = (yyvsp[(2) - (4)].ast);
               temp->c = (yyvsp[(3) - (4)].ast);
               temp->d = (yyvsp[(4) - (4)].ast);
               temp->value = 105;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 1162 "gramC.y"
    {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 106;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1169 "gramC.y"
    {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 107;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1176 "gramC.y"
    {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 108;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1183 "gramC.y"
    {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 109;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1190 "gramC.y"
    {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 110;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1197 "gramC.y"
    {/* printf(" |"); */
               UnaryOperator *temp = new UnaryOperator();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 111;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1207 "gramC.y"
    {/* printf(" |"); */
               CastExpression *temp = new CastExpression();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 112;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1214 "gramC.y"
    {/* printf(" |"); */
               CastExpression *temp = new CastExpression();
               temp->a = (yyvsp[(1) - (4)].ast);
               temp->b = (yyvsp[(2) - (4)].ast);
               temp->c = (yyvsp[(3) - (4)].ast);
               temp->d = (yyvsp[(4) - (4)].ast);
               temp->value = 113;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1227 "gramC.y"
    {/* printf(" |"); */
               MultiplicativeExpression *temp = new MultiplicativeExpression();
               temp->a = (yyvsp[(1) - (1)].ast);
               temp->value = 114;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1234 "gramC.y"
    {/* printf(" |"); */
               MultiplicativeExpression *temp = new MultiplicativeExpression();
               temp->a = (yyvsp[(1) - (3)].ast);
               temp->b = (yyvsp[(2) - (3)].ast);
               temp->c = (yyvsp[(3) - (3)].ast);
               temp->value = 115;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1243 "gramC.y"
    {/* printf(" |"); */
               MultiplicativeExpression *temp = new MultiplicativeExpression();
               temp->a = (yyvsp[(1) - (3)].ast);
               temp->b = (yyvsp[(2) - (3)].ast);
               temp->c = (yyvsp[(3) - (3)].ast);
               temp->value = 116;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1252 "gramC.y"
    {/* printf(" |"); */
               MultiplicativeExpression *temp = new MultiplicativeExpression();
               temp->a = (yyvsp[(1) - (3)].ast);
               temp->b = (yyvsp[(2) - (3)].ast);
               temp->c = (yyvsp[(3) - (3)].ast);
               temp->value = 117;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1264 "gramC.y"
    {/* printf(" |"); */
                  AdditiveExpression *temp = new AdditiveExpression();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 118;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1271 "gramC.y"
    {/* printf(" |"); */
                  AdditiveExpression *temp = new AdditiveExpression();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 119;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 1280 "gramC.y"
    {/* printf(" |"); */
                  AdditiveExpression *temp = new AdditiveExpression();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 120;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1292 "gramC.y"
    {/* printf(" |"); */
                 ShiftExpression *temp = new ShiftExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 121;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1299 "gramC.y"
    {/* printf(" |"); */
                 ShiftExpression *temp = new ShiftExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 122;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1308 "gramC.y"
    {/* printf(" |"); */
                 ShiftExpression *temp = new ShiftExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 123;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1320 "gramC.y"
    {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 124;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1327 "gramC.y"
    {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 125;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1336 "gramC.y"
    {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 126;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1345 "gramC.y"
    {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 127;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1354 "gramC.y"
    {/* printf(" |"); */
                 RelationalExpression *temp = new RelationalExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 128;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1366 "gramC.y"
    {
                 EqualityExpression *temp = new EqualityExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 129;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1373 "gramC.y"
    {/* printf(" |"); */
                 EqualityExpression *temp = new EqualityExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 130;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1382 "gramC.y"
    {/* printf(" |"); */
                 EqualityExpression *temp = new EqualityExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 131;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1394 "gramC.y"
    {/* printf(" |"); */
                 AndExpression *temp = new AndExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 132;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1401 "gramC.y"
    {/* printf(" |"); */
                 AndExpression *temp = new AndExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 133;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1413 "gramC.y"
    {/* printf(" |"); */
                 ExclusiveOrExpression *temp = new ExclusiveOrExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 134;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1420 "gramC.y"
    {/* printf(" |"); */
                 ExclusiveOrExpression *temp = new ExclusiveOrExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 135;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1432 "gramC.y"
    {/* printf(" |"); */
                 InclusiveOrExpression *temp = new InclusiveOrExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 136;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1439 "gramC.y"
    {/* printf(" |"); */
                 InclusiveOrExpression *temp = new InclusiveOrExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 137;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1451 "gramC.y"
    {/* printf(" |"); */
                 LogicalAndExpression *temp = new LogicalAndExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 138;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1458 "gramC.y"
    {/* printf(" |"); */
                 LogicalAndExpression *temp = new LogicalAndExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 139;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1470 "gramC.y"
    {/* printf(" |"); */
                 LogicalOrExpression *temp = new LogicalOrExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 140;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1477 "gramC.y"
    {/* printf(" |"); */
                 LogicalOrExpression *temp = new LogicalOrExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 141;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1489 "gramC.y"
    {/* printf(" |"); */
                 ConditionalExpression *temp = new ConditionalExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 142;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1496 "gramC.y"
    {/* printf(" |"); */
                 ConditionalExpression *temp = new ConditionalExpression();
                 temp->a = (yyvsp[(1) - (5)].ast);
                 temp->b = (yyvsp[(2) - (5)].ast);
                 temp->c = (yyvsp[(3) - (5)].ast);
                 temp->d = (yyvsp[(4) - (5)].ast);
                 temp->e = (yyvsp[(5) - (5)].ast);
                 temp->value = 143;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1510 "gramC.y"
    {/* printf(" |"); */
                 AssignmentExpression *temp = new AssignmentExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 144;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1517 "gramC.y"
    {/* printf(" |"); */
                 AssignmentExpression *temp = new AssignmentExpression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 145;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1529 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 146;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1536 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 147;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1543 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 148;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1550 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 149;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1557 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 150;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1564 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 151;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1571 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 152;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1578 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 153;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1585 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 154;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1592 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 155;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1599 "gramC.y"
    {/* printf(" |"); */
                 AssignmentOperator *temp = new AssignmentOperator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 156;
                    (yyval.ast) = temp;     
            ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1609 "gramC.y"
    {/* printf(" |"); */
                 Expression *temp = new Expression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 157;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1616 "gramC.y"
    {/* printf(" |"); */
                 Expression *temp = new Expression();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 158;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1628 "gramC.y"
    {/* printf(" |"); */
                 ConstantExpression *temp = new ConstantExpression();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 159;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1638 "gramC.y"
    {/* printf ("declaration_specifiers ; | "); */
                 Declaration *temp = new Declaration();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 160;
                // printf("declaration: declaration_specifiers semicolon %d \n",temp->value);
                    (yyval.ast) = temp;     
              ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1647 "gramC.y"
    {
                 Declaration *temp = new Declaration();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 161;
                // printf("declaration: declaration_specifiers init_declarator_list semicolon %d \n",temp->value);
                 (yyval.ast) = temp;     
              ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1660 "gramC.y"
    {
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 162;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1667 "gramC.y"
    {
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 163;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1675 "gramC.y"
    {
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 164;
               //  printf("DeclarationSpecifier: type_specifier %d \n",temp->value);
                    (yyval.ast) = temp;     
              ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1683 "gramC.y"
    {
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 165;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1691 "gramC.y"
    {/* printf ("type_qualifier | "); */
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 166;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1698 "gramC.y"
    {/* printf ("type_qualifier declaration_specifiers | "); */
                 DeclarationSpecifiers *temp = new DeclarationSpecifiers();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 167;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1709 "gramC.y"
    {
                 InitDeclaratorList *temp = new InitDeclaratorList();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 168;
               //  printf("InitDeclaratorList: init_declarator %d \n",temp->value);
                 (yyval.ast) = temp;     
              ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1717 "gramC.y"
    {
                 InitDeclaratorList *temp = new InitDeclaratorList();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 169;
                 (yyval.ast) = temp;     
              ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1729 "gramC.y"
    {
                 InitDeclarator *temp = new InitDeclarator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 170;
               //  printf("InitDeclarator: declarator %d \n",temp->value);
                 (yyval.ast) = temp;     
              ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1737 "gramC.y"
    {
                 InitDeclarator *temp = new InitDeclarator();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 171;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1749 "gramC.y"
    {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 172;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1756 "gramC.y"
    {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 173;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1763 "gramC.y"
    {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 174;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1770 "gramC.y"
    {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 175;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1777 "gramC.y"
    {/* printf(" |"); */
                 StorageClassSpecifier *temp = new StorageClassSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 176;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1787 "gramC.y"
    {/* printf ("VOID | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 177;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1794 "gramC.y"
    {/* printf ("CHAR  | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 178;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1801 "gramC.y"
    {/* printf ("SHORT | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 179;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1808 "gramC.y"
    {/* printf ("INT| "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 180;
              //   printf("typeSpecifier: int %d \n",temp->value);
                    (yyval.ast) = temp;     
              ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1816 "gramC.y"
    {/* printf ("LONG | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 181;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1823 "gramC.y"
    {/* printf ("FLOAT | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 182;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1830 "gramC.y"
    {/* printf ("DOUBLE | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 183;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1837 "gramC.y"
    {/* printf ("SIGNED | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 184;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1844 "gramC.y"
    {/* printf ("UNSIGNED  | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 185;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1851 "gramC.y"
    {/* printf ("struct_or_union_specifier | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 186;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1858 "gramC.y"
    {/* printf ("enum_specifier | "); */
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 187;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1865 "gramC.y"
    {  //printf("não entendi"); 
                 TypeSpecifier *temp = new TypeSpecifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 188;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1875 "gramC.y"
    {/* printf ("struct_or_union IDENTIFIER { struct_declaration_list }  | "); */
                 StructOrUnionSpecifier *temp = new StructOrUnionSpecifier();
                 temp->a = (yyvsp[(1) - (5)].ast);
                 temp->b = (yyvsp[(2) - (5)].ast);
                 temp->c = (yyvsp[(3) - (5)].ast);
                 temp->d = (yyvsp[(4) - (5)].ast);
                 temp->e = (yyvsp[(5) - (5)].ast);
                 temp->value = 189;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1886 "gramC.y"
    {
                 StructOrUnionSpecifier *temp = new StructOrUnionSpecifier();
                 temp->a = (yyvsp[(1) - (4)].ast);
                 temp->b = (yyvsp[(2) - (4)].ast);
                 temp->c = (yyvsp[(3) - (4)].ast);
                 temp->d = (yyvsp[(4) - (4)].ast);
                 temp->value = 190;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1896 "gramC.y"
    {/* printf ("struct_or_union IDENTIFIER | "); */
                 StructOrUnionSpecifier *temp = new StructOrUnionSpecifier();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 191;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1907 "gramC.y"
    {/* printf ("STRUCT | "); */
                 StructOrUnion *temp = new StructOrUnion();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 192;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1914 "gramC.y"
    {/* printf ("UNION | "); */
                 StructOrUnion *temp = new StructOrUnion();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 193;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1924 "gramC.y"
    {/* printf ("struct_declaration | "); */
                 StructDeclarationList *temp = new StructDeclarationList();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 194;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1931 "gramC.y"
    {/* printf ("struct_declaration_list struct_declaration| "); */
                 StructDeclarationList *temp = new StructDeclarationList();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 195;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1942 "gramC.y"
    {
                 StructOrUnionSpecifier *temp = new StructOrUnionSpecifier();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 196;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1954 "gramC.y"
    {/* printf ("type_specifier specifier_qualifier_list | "); */
                 SpecifierQualifierList *temp = new SpecifierQualifierList();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 197;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1962 "gramC.y"
    {/* printf ("type_specifier  | "); */
                 SpecifierQualifierList *temp = new SpecifierQualifierList();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 198;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1969 "gramC.y"
    {/* printf ("type_qualifier specifier_qualifier_list | "); */
                 SpecifierQualifierList *temp = new SpecifierQualifierList();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 199;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1977 "gramC.y"
    {/* printf ("type_qualifier | "); */
                 SpecifierQualifierList *temp = new SpecifierQualifierList();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 200;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1987 "gramC.y"
    {/* printf ("struct_declarator | "); */
                 StructDeclaratorList *temp = new StructDeclaratorList();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 201;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1994 "gramC.y"
    {/* printf ("struct_declarator_list ',' struct_declarator  | "); */
                 StructDeclaratorList *temp = new StructDeclaratorList();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 202;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 2006 "gramC.y"
    {/* printf ("declarator | "); */
                 StructDeclarator *temp = new StructDeclarator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 203;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 2013 "gramC.y"
    {/* printf ("':' constant_expression | "); */
                 StructDeclarator *temp = new StructDeclarator();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 204;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 2021 "gramC.y"
    {/* printf ("declarator ':' constant_expression | "); */
                 StructDeclarator *temp = new StructDeclarator();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 205;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 2033 "gramC.y"
    {/* printf(" |"); */
                 EnumSpecifier *temp = new EnumSpecifier();
                 temp->a = (yyvsp[(1) - (4)].ast);
                 temp->b = (yyvsp[(2) - (4)].ast);
                 temp->c = (yyvsp[(3) - (4)].ast);
                 temp->d = (yyvsp[(4) - (4)].ast);
                 temp->value = 206;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 2043 "gramC.y"
    {/* printf(" |"); */
                 EnumSpecifier *temp = new EnumSpecifier();
                 temp->a = (yyvsp[(1) - (5)].ast);
                 temp->b = (yyvsp[(2) - (5)].ast);
                 temp->c = (yyvsp[(3) - (5)].ast);
                 temp->d = (yyvsp[(4) - (5)].ast);
                 temp->e = (yyvsp[(5) - (5)].ast);
                 temp->value = 207;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 2054 "gramC.y"
    {/* printf(" |"); */
                 EnumSpecifier *temp = new EnumSpecifier();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 208;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 2065 "gramC.y"
    {/* printf(" |"); */
                 EnumeratorList *temp = new EnumeratorList();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 209;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 2072 "gramC.y"
    {/* printf(" |"); */
                 EnumeratorList *temp = new EnumeratorList();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 210;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 2084 "gramC.y"
    {/* printf(" |"); */
                 Enumerator *temp = new Enumerator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 211;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 2091 "gramC.y"
    {/* printf(" |"); */
                 Enumerator *temp = new Enumerator();
                 temp->a = (yyvsp[(1) - (3)].ast);
                 temp->b = (yyvsp[(2) - (3)].ast);
                 temp->c = (yyvsp[(3) - (3)].ast);
                 temp->value = 212;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 2103 "gramC.y"
    {/* printf("CONST |"); */
                 TypeQualifier *temp = new TypeQualifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 213;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 2110 "gramC.y"
    {/* printf("VOLATILE  |"); */
                 TypeQualifier *temp = new TypeQualifier();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 214;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 2120 "gramC.y"
    {/* printf("pointer direct_declarator |"); */
                 Declarator *temp = new Declarator();
                 temp->a = (yyvsp[(1) - (2)].ast);
                 temp->b = (yyvsp[(2) - (2)].ast);
                 temp->value = 215;
                    (yyval.ast) = temp;                       
              ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 2128 "gramC.y"
    {/* printf("direct_declarator |"); */
                 Declarator *temp = new Declarator();
                 temp->a = (yyvsp[(1) - (1)].ast);
                 temp->value = 216;
               //  printf("Declarator: direct_declarator %d \n",temp->value);
                 (yyval.ast) = temp;                       
              ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 2139 "gramC.y"
    {/* printf("IDENTIFIER |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 217;
                //  printf("DirectDeclarator: identifier %d \n",temp->value);
                    (yyval.ast) = temp;     
              ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 2147 "gramC.y"
    {/* printf("'(' declarator ')' |"); */ //GAMBS se algum dia bugar eh aqui
                  DirectDeclarator *temp = new DirectDeclarator();

                  temp->a = new Folha();
                  temp->a->text = (char *) malloc(sizeof("("));
                  strcpy(temp->a->text,"("); //yytext
                  temp->a->value = 0; //lparen
 
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 218;
                    (yyval.ast) = temp;     

              ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 2162 "gramC.y"
    {/* printf("direct_declarator '[' constant_expression ']' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 219;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 2172 "gramC.y"
    {/* printf("direct_declarator '[' ']' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 220;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 2181 "gramC.y"
    {/* printf("direct_declarator '(' parameter_type_list ')' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 221;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 2191 "gramC.y"
    {/* printf("direct_declarator '(' identifier_list ')' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 222;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 2201 "gramC.y"
    {/* printf("direct_declarator '(' ')' |"); */
                  DirectDeclarator *temp = new DirectDeclarator();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 223;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 2213 "gramC.y"
    {/* printf(" |"); */
                  Pointer *temp = new Pointer();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 224;
                    (yyval.ast) = temp;     
             ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 2220 "gramC.y"
    {/* printf(" |"); */
                  Pointer *temp = new Pointer();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 225;
                    (yyval.ast) = temp;     
             ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 2228 "gramC.y"
    {/* printf(" |"); */
                  Pointer *temp = new Pointer();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 226;
                    (yyval.ast) = temp;     
             ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 2236 "gramC.y"
    {/* printf(" |"); */
                  Pointer *temp = new Pointer();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 227;
                    (yyval.ast) = temp;     
             ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 2248 "gramC.y"
    {/* printf("type_qualifier |"); */
                  TypeQualifierList *temp = new TypeQualifierList();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 228;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 2255 "gramC.y"
    {/* printf("type_qualifier_list type_qualifier |"); */
                  TypeQualifierList *temp = new TypeQualifierList();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 229;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 2267 "gramC.y"
    {/* printf("parameter_list |"); */
                  ParameterTypeList *temp = new ParameterTypeList();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 230;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 2274 "gramC.y"
    {/* printf("parameter_list ',' ELLIPSIS |"); */
                  ParameterTypeList *temp = new ParameterTypeList();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 231;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 2286 "gramC.y"
    {/* printf("parameter_declaration |"); */
                  ParameterList *temp = new ParameterList();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 232;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 2293 "gramC.y"
    {/* printf("parameter_list ',' parameter_declaration |"); */
                  ParameterList *temp = new ParameterList();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 233;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 2305 "gramC.y"
    {
                  ParameterDeclaration *temp = new ParameterDeclaration();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 234;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 2313 "gramC.y"
    {
                  ParameterDeclaration *temp = new ParameterDeclaration();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 235;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 2321 "gramC.y"
    {
                  ParameterDeclaration *temp = new ParameterDeclaration();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 236;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 2331 "gramC.y"
    {/* printf("IDENTIFIER  |"); */
                  IdentifierList *temp = new IdentifierList();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 237;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 2338 "gramC.y"
    {/* printf("identifier_list ',' IDENTIFIER  |"); */
                  IdentifierList *temp = new IdentifierList();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 238;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 2350 "gramC.y"
    {/* printf("specifier_qualifier_list  |"); */
                  TypeName *temp = new TypeName();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 239;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 2357 "gramC.y"
    {/* printf("specifier_qualifier_list abstract_declarator |"); */
                  TypeName *temp = new TypeName();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 240;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 2369 "gramC.y"
    {/* printf(" |"); */
                  AbstractDeclarator *temp = new AbstractDeclarator();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 241;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 2376 "gramC.y"
    {/* printf(" |"); */
                  AbstractDeclarator *temp = new AbstractDeclarator();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 242;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 2383 "gramC.y"
    {/* printf(" |"); */
                  AbstractDeclarator *temp = new AbstractDeclarator();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 243;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 2394 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();

                  temp->a = new Folha();
                  temp->a->text = (char *) malloc(sizeof("("));
                  strcpy(temp->a->text,"("); //yytext
                  temp->a->value = 0; //lparen
 
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 244;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 2408 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 245;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 2416 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 246;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 2425 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 247;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 2434 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 248;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 2444 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 249;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 2452 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 250;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 2461 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 251;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 2470 "gramC.y"
    {/* printf(" |"); */
                  DirectAbstractDeclarator *temp = new DirectAbstractDeclarator();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 252;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 2483 "gramC.y"
    {/* printf("assignment_expression |"); */
                  Initializer *temp = new Initializer();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 253;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 2490 "gramC.y"
    {
                  Initializer *temp = new Initializer();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 254;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 2499 "gramC.y"
    {
                  Initializer *temp = new Initializer();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 255;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 2512 "gramC.y"
    {/* printf("initializer |"); */
                  InitializerList *temp = new InitializerList();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 256;
                    (yyval.ast) = temp;                    
              ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 2519 "gramC.y"
    {/* printf("initializer_list ',' initializer |"); */
                  InitializerList *temp = new InitializerList();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 257;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 2531 "gramC.y"
    {/* printf("labeled_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 258;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 2538 "gramC.y"
    {/* printf("compound_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 259;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 2545 "gramC.y"
    {/* printf("expression_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 260;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 2552 "gramC.y"
    {/* printf("selection_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 261;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 2559 "gramC.y"
    {/* printf("iteration_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 262;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 2566 "gramC.y"
    {/* printf("jump_statement |"); */
                  Statement *temp = new Statement();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 263;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 2576 "gramC.y"
    {/* printf(" |"); */
                  LabeledStatement *temp = new LabeledStatement();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 264;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 2585 "gramC.y"
    {/* printf(" |"); */
                  LabeledStatement *temp = new LabeledStatement();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 265;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 2595 "gramC.y"
    {/* printf(" |"); */
                  LabeledStatement *temp = new LabeledStatement();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 266;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 2607 "gramC.y"
    {
                  CompoundStatement *temp = new CompoundStatement();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 267;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 2615 "gramC.y"
    {
                  CompoundStatement *temp = new CompoundStatement();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 268;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 2624 "gramC.y"
    {
                  CompoundStatement *temp = new CompoundStatement();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 269;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 2633 "gramC.y"
    {
                  CompoundStatement *temp = new CompoundStatement();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast); 
                  temp->value = 270;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 2646 "gramC.y"
    {/* printf("declaration |"); */
                  DeclarationList *temp = new DeclarationList();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 271;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 2653 "gramC.y"
    {/* printf("declaration_list declaration |"); */
                  DeclarationList *temp = new DeclarationList();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 272;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 2664 "gramC.y"
    {/* printf("statement  |"); */
                  StatementList *temp = new StatementList();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 273;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 2671 "gramC.y"
    {/* printf("statement_list statement |"); */
                  StatementList *temp = new StatementList();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 274;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 2682 "gramC.y"
    {
                  ExpressionStatement *temp = new ExpressionStatement();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 275;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 2689 "gramC.y"
    {
                  ExpressionStatement *temp = new ExpressionStatement();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 276;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 2700 "gramC.y"
    {/* printf("IF '(' expression ')' statement |"); */
                  SelectionStatement *temp = new SelectionStatement();
                  temp->a = (yyvsp[(1) - (5)].ast);
                  temp->b = (yyvsp[(2) - (5)].ast);
                  temp->c = (yyvsp[(3) - (5)].ast);
                  temp->d = (yyvsp[(4) - (5)].ast);
                  temp->e = (yyvsp[(5) - (5)].ast);
                  temp->value = 277;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 2711 "gramC.y"
    {/* printf("IF '(' expression ')' statement ELSE statement |"); */
                  SelectionStatement *temp = new SelectionStatement();
                  temp->a = (yyvsp[(1) - (7)].ast);
                  temp->b = (yyvsp[(2) - (7)].ast);
                  temp->c = (yyvsp[(3) - (7)].ast);
                  temp->d = (yyvsp[(4) - (7)].ast);
                  temp->e = (yyvsp[(5) - (7)].ast);
                  temp->f = (yyvsp[(6) - (7)].ast);
                  temp->g = (yyvsp[(7) - (7)].ast);
                  temp->value = 278;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 2724 "gramC.y"
    {/* printf("SWITCH '(' expression ')' statement |"); */
                  SelectionStatement *temp = new SelectionStatement();
                  temp->a = (yyvsp[(1) - (5)].ast);
                  temp->b = (yyvsp[(2) - (5)].ast);
                  temp->c = (yyvsp[(3) - (5)].ast);
                  temp->d = (yyvsp[(4) - (5)].ast);
                  temp->e = (yyvsp[(5) - (5)].ast);
                  temp->value = 279;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 2738 "gramC.y"
    {/* printf("WHILE '(' expression ')' statement |"); */
                  IterationStatement *temp = new IterationStatement();
                  temp->a = (yyvsp[(1) - (5)].ast);
                  temp->b = (yyvsp[(2) - (5)].ast);
                  temp->c = (yyvsp[(3) - (5)].ast);
                  temp->d = (yyvsp[(4) - (5)].ast);
                  temp->e = (yyvsp[(5) - (5)].ast);
                  temp->value = 280;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 2749 "gramC.y"
    {
                  IterationStatement *temp = new IterationStatement();
                  temp->a = (yyvsp[(1) - (7)].ast);
                  temp->b = (yyvsp[(2) - (7)].ast);
                  temp->c = (yyvsp[(3) - (7)].ast);
                  temp->d = (yyvsp[(4) - (7)].ast);
                  temp->e = (yyvsp[(5) - (7)].ast);
                  temp->f = (yyvsp[(6) - (7)].ast);
                  temp->g = (yyvsp[(7) - (7)].ast);
                  temp->value = 281;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 2762 "gramC.y"
    {/* printf("FOR '(' expression_statement expression_statement ')' statement |"); */
                  IterationStatement *temp = new IterationStatement();
                  temp->a = (yyvsp[(1) - (6)].ast);
                  temp->b = (yyvsp[(2) - (6)].ast);
                  temp->c = (yyvsp[(3) - (6)].ast);
                  temp->d = (yyvsp[(4) - (6)].ast);
                  temp->e = (yyvsp[(5) - (6)].ast);
                  temp->f = (yyvsp[(6) - (6)].ast);
                  temp->value = 282;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 2774 "gramC.y"
    {/* printf("FOR '(' expression_statement expression_statement expression ')' statement |"); */
                  IterationStatement *temp = new IterationStatement();
                  temp->a = (yyvsp[(1) - (7)].ast);
                  temp->b = (yyvsp[(2) - (7)].ast);
                  temp->c = (yyvsp[(3) - (7)].ast);
                  temp->d = (yyvsp[(4) - (7)].ast);
                  temp->e = (yyvsp[(5) - (7)].ast);
                  temp->f = (yyvsp[(6) - (7)].ast);
                  temp->g = (yyvsp[(7) - (7)].ast);
                  temp->value = 283;
                    (yyval.ast) = temp;      
              ;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 2790 "gramC.y"
    {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 284;
                    (yyval.ast) = temp;        
              ;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 2799 "gramC.y"
    {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 285;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 2807 "gramC.y"
    {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 286;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 2815 "gramC.y"
    {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 287;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 2823 "gramC.y"
    {
                  JumpStatement *temp = new JumpStatement();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 288;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 2837 "gramC.y"
    {/* printf("function_definition | "); */
                  ExternalDeclaration *temp = new ExternalDeclaration();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 289;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 2844 "gramC.y"
    {/* printf("declaration | "); */
                  ExternalDeclaration *temp = new ExternalDeclaration();
                  temp->a = (yyvsp[(1) - (1)].ast);
                  temp->value = 290;
                //  printf("ExternalDeclartion: declaration %d \n",temp->value);
                  (yyval.ast) = temp;     
              ;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 2855 "gramC.y"
    {/* printf("declaration_specifiers declarator declaration_list compound_statement |"); */
                  FunctionDefinition *temp = new FunctionDefinition();
                  temp->a = (yyvsp[(1) - (4)].ast);
                  temp->b = (yyvsp[(2) - (4)].ast);
                  temp->c = (yyvsp[(3) - (4)].ast);
                  temp->d = (yyvsp[(4) - (4)].ast);
                  temp->value = 291;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 2865 "gramC.y"
    {/* printf("declaration_specifiers declarator compound_statement |"); */
                  FunctionDefinition *temp = new FunctionDefinition();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 292;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 2874 "gramC.y"
    {/* printf("declarator declaration_list compound_statement |"); */
                  FunctionDefinition *temp = new FunctionDefinition();
                  temp->a = (yyvsp[(1) - (3)].ast);
                  temp->b = (yyvsp[(2) - (3)].ast);
                  temp->c = (yyvsp[(3) - (3)].ast);
                  temp->value = 293;
                    (yyval.ast) = temp;     
              ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 2883 "gramC.y"
    {/* printf("declarator compound_statement |"); */
                  FunctionDefinition *temp = new FunctionDefinition();
                  temp->a = (yyvsp[(1) - (2)].ast);
                  temp->b = (yyvsp[(2) - (2)].ast);
                  temp->value = 294;
                    (yyval.ast) = temp;     
              ;}
    break;



/* Line 1455 of yacc.c  */
#line 5916 "gramC.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2892 "gramC.y"

extern char yytext[];

int yyerror(char *s)
{
	fflush(stdout);
	printf("\n%s\n", s);
}

main(int argc,char **argv)
{
extern FILE* yyin;
ast = new Ast();
raizVariaveis = 0;
raizFuncoes = 0;
escopo = 0;
ordem = 0;
	      if ( argc > 1 )
	      {
		       printf("%s",argv[1]);
		       yyin = fopen( argv[1], "r" );
		    
	      }
	       yyparse();
                   treewalk(ast);
                   mainAst(ast,0);
//excluir
                   imprimirTabelaVariaveis(raizVariaveis);
}
