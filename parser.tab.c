
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
#line 1 "parser.y"

#include "parser.tab.h"
#include "error.h"
#define YYDEBUG 1


/* Line 189 of yacc.c  */
#line 80 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
     STR = 259,
     COMMA = 260,
     CHAR = 261,
     BIN = 262,
     HEX = 263,
     DEC = 264,
     TRUE = 265,
     FALSE = 266,
     IF = 267,
     ELSE = 268,
     WHILE = 269,
     DO = 270,
     BREAK = 271,
     SEMICOLON = 272,
     LPAREN = 273,
     RPAREN = 274,
     LBRACE = 275,
     RBRACE = 276,
     LBRACKET = 277,
     RBRACKET = 278,
     TYPEDEF = 279,
     RETURN = 280,
     ARRAY_COMMAS = 281,
     OR = 282,
     AND = 283,
     NOT = 284,
     MINUS = 285,
     PLUS = 286,
     PERCENT = 287,
     SLASH = 288,
     STAR = 289,
     GREATERTHANEQ = 290,
     LESSTHANEQ = 291,
     GREATERTHAN = 292,
     LESSTHAN = 293,
     NOTEQUAL = 294,
     EQUAL = 295,
     ASSIGN = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 6 "parser.y"

    ASTNode* node;



/* Line 214 of yacc.c  */
#line 163 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 175 "parser.tab.c"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   430

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    18,    19,    21,
      25,    28,    30,    32,    34,    36,    38,    40,    42,    44,
      46,    48,    50,    52,    55,    58,    60,    63,    67,    69,
      71,    73,    77,    84,    87,    88,    91,    92,    96,    99,
     105,   113,   116,   119,   122,   126,   128,   130,   132,   134,
     136,   138,   140,   142,   144,   148,   152,   156,   160,   164,
     168,   172,   176,   180,   184,   188,   192,   196,   199,   202,
     206,   211,   213,   214,   218,   220,   225,   227,   229,   231,
     233,   235,   237,   239
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    43,    44,    -1,    45,    60,    -1,
      45,    17,    -1,    47,    18,    46,    19,    -1,    -1,    47,
      -1,    47,     5,    46,    -1,    48,     3,    -1,    49,    -1,
      52,    -1,    53,    -1,    24,    -1,    56,    -1,    57,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      51,    -1,    25,    17,    -1,    25,    64,    -1,     3,    -1,
      48,    26,    -1,    55,     5,    54,    -1,    55,    -1,     3,
      -1,    65,    -1,    48,    54,    17,    -1,    12,    18,    67,
      19,    50,    58,    -1,    13,    50,    -1,    -1,    50,    59,
      -1,    -1,    20,    59,    21,    -1,    20,    21,    -1,    14,
      18,    67,    19,    60,    -1,    15,    60,    14,    18,    67,
      19,    17,    -1,    16,    17,    -1,    67,    17,    -1,    65,
      17,    -1,    66,    41,    67,    -1,    75,    -1,    74,    -1,
      69,    -1,    68,    -1,    70,    -1,    71,    -1,    74,    -1,
      75,    -1,    76,    -1,    67,    31,    67,    -1,    67,    30,
      67,    -1,    67,    34,    67,    -1,    67,    33,    67,    -1,
      67,    32,    67,    -1,    67,    40,    67,    -1,    67,    39,
      67,    -1,    67,    38,    67,    -1,    67,    37,    67,    -1,
      67,    36,    67,    -1,    67,    35,    67,    -1,    67,    28,
      67,    -1,    67,    27,    67,    -1,    30,    67,    -1,    29,
      67,    -1,    18,    67,    19,    -1,     3,    18,    72,    19,
      -1,    73,    -1,    -1,    67,     5,    73,    -1,    67,    -1,
      67,    22,    73,    23,    -1,     3,    -1,    10,    -1,    11,
      -1,     4,    -1,     6,    -1,     8,    -1,     7,    -1,     9,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    73,    74,    76,    78,    79,    80,
      82,    85,    86,    87,    89,    91,    92,    93,    94,    95,
      96,    97,    98,   100,   101,   104,   106,   109,   110,   112,
     113,   115,   117,   119,   120,   122,   123,   125,   126,   128,
     130,   132,   134,   135,   137,   138,   139,   141,   142,   143,
     144,   145,   146,   147,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   164,   165,   167,
     169,   170,   171,   173,   174,   175,   177,   179,   180,   181,
     182,   183,   184,   185
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STR", "COMMA", "CHAR",
  "BIN", "HEX", "DEC", "TRUE", "FALSE", "IF", "ELSE", "WHILE", "DO",
  "BREAK", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "TYPEDEF", "RETURN", "ARRAY_COMMAS", "OR", "AND", "NOT",
  "MINUS", "PLUS", "PERCENT", "SLASH", "STAR", "GREATERTHANEQ",
  "LESSTHANEQ", "GREATERTHAN", "LESSTHAN", "NOTEQUAL", "EQUAL", "ASSIGN",
  "$accept", "source", "sourceItem", "funcSignature", "listArgDef",
  "argDef", "typeRef", "builtin", "statement", "return", "custom", "array",
  "listVarDeclared", "listVarDeclaredItem", "var", "if",
  "optionalElseStatement", "listStatement", "block", "while", "do",
  "break", "expression", "assignment", "canAssign", "expr", "binary",
  "unary", "braces", "call", "optionalListExpr", "listExpr", "indexer",
  "place", "literal", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    46,    46,    46,
      47,    48,    48,    48,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    51,    52,    53,    54,    54,    55,
      55,    56,    57,    58,    58,    59,    59,    60,    60,    61,
      62,    63,    64,    64,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      71,    72,    72,    73,    73,    74,    75,    76,    76,    76,
      76,    76,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     4,     0,     1,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     3,     1,     1,
       1,     3,     6,     2,     0,     2,     0,     3,     2,     5,
       7,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       4,     1,     0,     3,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    25,    14,     3,     0,     0,     0,    11,
      12,    13,     5,     0,     4,     7,    10,    26,    76,    79,
      80,    82,    81,    83,    77,    78,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,    36,    22,    15,    16,
       0,    17,    18,    19,    20,    21,     0,     0,     0,    48,
      47,    49,    50,    51,    52,    53,     0,     8,    72,     0,
       0,     0,    41,    76,     0,    51,    52,    23,    24,    68,
      67,    76,     0,    28,    30,     0,    35,    37,    43,     0,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,    74,     0,    71,
       0,     0,     0,    69,    31,     0,    44,     0,    66,    65,
      55,    54,    58,    57,    56,    64,    63,    62,    61,    60,
      59,     9,     0,    70,     0,     0,     0,    27,    75,    73,
      34,    39,     0,     0,    32,     0,    33,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,     6,    56,    57,    35,     9,    36,    37,
      10,    11,    72,    73,    38,    39,   134,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      98,    99,    65,    66,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -114
static const yytype_int16 yypact[] =
{
    -114,    27,  -114,  -114,  -114,  -114,    -3,    -8,    10,  -114,
    -114,  -114,  -114,   121,  -114,    25,  -114,  -114,   149,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,    30,    35,    -4,     1,
     206,  -114,   177,   206,   206,   193,    73,  -114,  -114,  -114,
      47,  -114,  -114,  -114,  -114,  -114,    52,    29,   226,  -114,
    -114,  -114,  -114,    31,    32,  -114,    55,    66,   206,   206,
     206,    72,  -114,    82,   248,  -114,  -114,  -114,  -114,   371,
     390,   172,    87,    85,  -114,   333,  -114,  -114,  -114,   206,
    -114,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,  -114,    25,     7,    86,  -114,
     270,   292,    88,  -114,  -114,   222,   333,    84,   352,   371,
     390,   390,    79,    79,    79,   126,   126,   126,   126,   126,
     126,  -114,   206,  -114,    73,    -4,   206,  -114,  -114,  -114,
      95,  -114,   314,    73,  -114,    92,  -114,  -114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,  -114,  -114,    14,   111,     0,  -114,  -113,  -114,
    -114,  -114,    16,  -114,  -114,  -114,  -114,    90,    -2,  -114,
    -114,  -114,   102,   -30,  -114,   -27,  -114,  -114,  -114,  -114,
    -114,   -72,   -13,   -11,  -114
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -47
static const yytype_int16 yytable[] =
{
      53,     8,    54,    64,    14,    74,    69,    70,    75,   107,
      15,   130,   122,    16,    12,     8,    13,    13,    62,    53,
     136,    54,    53,    53,    54,    54,    61,     2,     3,    81,
       3,    97,   100,   101,    82,    83,    17,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    59,     4,
     129,     4,   106,    60,    97,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    77,    78,
      79,    96,   -46,   -45,    95,    74,    18,    19,    75,    20,
      21,    22,    23,    24,    25,    26,   102,    27,    28,    29,
     105,    30,    53,    13,    54,    97,     8,     4,    32,   132,
      58,    81,    33,    34,   104,   123,   126,   128,   133,   137,
     121,    53,     7,    54,    89,    90,    91,    92,    93,    94,
      53,   127,    54,   131,    18,    19,    76,    20,    21,    22,
      23,    24,    25,    26,    68,    27,    28,    29,     0,    30,
       0,    13,    31,     0,     0,     4,    32,     0,    81,     0,
      33,    34,   -25,   -25,     0,   -25,   -25,   -25,   -25,   -25,
     -25,   -47,   -47,   -47,   -47,   -47,   -47,    58,     0,     0,
       0,     0,     0,     0,     0,   -25,     0,   -29,   -25,   -25,
      63,    19,     0,    20,    21,    22,    23,    24,    25,   -29,
      58,     0,     0,     0,    67,    30,    71,    19,     0,    20,
      21,    22,    23,    24,    25,     0,    33,    34,     0,    63,
      19,    30,    20,    21,    22,    23,    24,    25,     0,    17,
       0,     0,    33,    34,    30,    71,    19,     0,    20,    21,
      22,    23,    24,    25,     0,    33,    34,     0,     0,     0,
      30,     0,     0,    80,     0,     0,     0,     0,    81,     0,
       0,    33,    34,    82,    83,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   103,     0,     0,
      81,     0,     0,     0,     0,    82,    83,     0,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   124,
       0,     0,    81,     0,     0,     0,     0,    82,    83,     0,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,   125,     0,     0,    81,     0,     0,     0,     0,    82,
      83,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,   135,     0,     0,    81,     0,     0,     0,
       0,    82,    83,     0,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    81,     0,     0,     0,     0,
      82,    83,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    81,     0,     0,     0,     0,     0,
      83,     0,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    81,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94
};

static const yytype_int16 yycheck[] =
{
      13,     1,    13,    30,     6,    35,    33,    34,    35,    81,
      18,   124,     5,     3,    17,    15,    20,    20,    17,    32,
     133,    32,    35,    36,    35,    36,    28,     0,     3,    22,
       3,    58,    59,    60,    27,    28,    26,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    18,    24,
     122,    24,    79,    18,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    21,    17,
      41,     5,    41,    41,    19,   105,     3,     4,   105,     6,
       7,     8,     9,    10,    11,    12,    14,    14,    15,    16,
       5,    18,   105,    20,   105,   122,    96,    24,    25,   126,
      18,    22,    29,    30,    17,    19,    18,    23,    13,    17,
      96,   124,     1,   124,    35,    36,    37,    38,    39,    40,
     133,   105,   133,   125,     3,     4,    36,     6,     7,     8,
       9,    10,    11,    12,    32,    14,    15,    16,    -1,    18,
      -1,    20,    21,    -1,    -1,    24,    25,    -1,    22,    -1,
      29,    30,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    35,    36,    37,    38,    39,    40,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,     5,    29,    30,
       3,     4,    -1,     6,     7,     8,     9,    10,    11,    17,
      18,    -1,    -1,    -1,    17,    18,     3,     4,    -1,     6,
       7,     8,     9,    10,    11,    -1,    29,    30,    -1,     3,
       4,    18,     6,     7,     8,     9,    10,    11,    -1,    26,
      -1,    -1,    29,    30,    18,     3,     4,    -1,     6,     7,
       8,     9,    10,    11,    -1,    29,    30,    -1,    -1,    -1,
      18,    -1,    -1,    17,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    29,    30,    27,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    27,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    19,    -1,    -1,    22,    -1,    -1,    -1,    -1,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    19,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    22,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,     0,     3,    24,    44,    45,    47,    48,    49,
      52,    53,    17,    20,    60,    18,     3,    26,     3,     4,
       6,     7,     8,     9,    10,    11,    12,    14,    15,    16,
      18,    21,    25,    29,    30,    48,    50,    51,    56,    57,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    74,    75,    76,    46,    47,    18,    18,
      18,    60,    17,     3,    67,    74,    75,    17,    64,    67,
      67,     3,    54,    55,    65,    67,    59,    21,    17,    41,
      17,    22,    27,    28,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    19,     5,    67,    72,    73,
      67,    67,    14,    19,    17,     5,    67,    73,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    46,     5,    19,    19,    19,    18,    54,    23,    73,
      50,    60,    67,    13,    58,    19,    50,    17
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
#line 70 "parser.y"
    {{(yyval.node) = NULL;};}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    {{(yyval.node) = createNode("source", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), "");};}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    {{(yyval.node) = createNode(sourceItem, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), "");};}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {{(yyval.node) = createNode(sourceItem, (yyvsp[(1) - (2)].node), NULL, "");};}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {{(yyval.node) = createNode(funcSignature, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), "");};}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {{(yyval.node) = NULL;};}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    {{(yyval.node) = createNode("listArgDef", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {{(yyval.node) = createNode("argDef", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), "");};}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {{(yyval.node) =  (yyvsp[(1) - (1)].node);};}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {{(yyval.node)=createNode("return", NULL, NULL, (yyvsp[(2) - (2)].node)->value);};}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {{(yyval.node)=createNode("return", (yyvsp[(2) - (2)].node), NULL, (yyvsp[(2) - (2)].node)->value);};}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {{(yyval.node) = createNode("array", (yyvsp[(1) - (2)].node), NULL, (yyvsp[(2) - (2)].node)->value);};}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {{(yyval.node) = createNode("listVarDeclared", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {{(yyval.node) = createNode("listVarDeclared", (yyvsp[(1) - (1)].node), NULL, "");};}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {{(yyval.node) = createNode("var", (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node), "");};}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {{(yyval.node) = createNode("if", (yyvsp[(3) - (6)].node), createNode("ifStatements", (yyvsp[(5) - (6)].node), (yyvsp[(6) - (6)].node), ""), "");};}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {{(yyval.node) = createNode("else", (yyvsp[(2) - (2)].node), NULL, "");};}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {{(yyval.node) = NULL;};}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {{(yyval.node) = createNode("listStatement", (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node), "");};}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {{(yyval.node) = NULL;};}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {{(yyval.node) = createNode("block", (yyvsp[(2) - (3)].node), NULL, "");};}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {{(yyval.node) = createNode("block", NULL, NULL, "");};}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {{(yyval.node) = createNode("while", (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node), "");};}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {{(yyval.node) = createNode("dowhile", (yyvsp[(2) - (7)].node), (yyvsp[(5) - (7)].node), "");};}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {{(yyval.node) = createNode("break", NULL, NULL, "");};}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (2)].node);};}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (2)].node);};}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {{(yyval.node) = createNode("assigment", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {{(yyval.node) = createNode("PLUS", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {{(yyval.node) = createNode("MINUS", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {{(yyval.node) = createNode("STAR", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {{(yyval.node) = createNode("SLASH", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {{(yyval.node) = createNode("PERCENT", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {{(yyval.node) = createNode("EQUALITY", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {{(yyval.node) = createNode("NOTEQUAL", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {{(yyval.node) = createNode("LESSTHAN", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {{(yyval.node) = createNode("GREATERTHAN", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {{(yyval.node) = createNode("LESSTHANEQ", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {{(yyval.node) = createNode("GREATERTHANEQ", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {{(yyval.node) = createNode("AND", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {{(yyval.node) = createNode("OR", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {{(yyval.node) = createNode("MINUS_UNARY", (yyvsp[(2) - (2)].node), NULL, "");};}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {{(yyval.node) = createNode("NOT", (yyvsp[(2) - (2)].node), NULL, "");};}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {{(yyval.node) = createNode("braces", (yyvsp[(2) - (3)].node), NULL, "");};}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {{(yyval.node) = createNode("CALL", (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), "");};}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {{(yyval.node) = createNode("optionalListExpr", (yyvsp[(1) - (1)].node), NULL, "");};}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {{(yyval.node) = createNode("optionalListExpr", NULL, NULL, "");};}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {{(yyval.node) = createNode("listExpr", (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), "");};}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {{(yyval.node) = createNode("listExpr", (yyvsp[(1) - (1)].node), NULL, "");};}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 175 "parser.y"
    {{(yyval.node) = createNode("indexer", (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), "");};}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {{(yyval.node) = (yyvsp[(1) - (1)].node);};}
    break;



/* Line 1455 of yacc.c  */
#line 2111 "parser.tab.c"
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
#line 186 "parser.y"


