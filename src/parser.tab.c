/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"


    #include <stdio.h>
    #include "parser.h"
	#include "ast.h"
	#include "eval.h"
	#include "typelist.h"
    void yyerror(const char *s);
    int yylex(void);


/* Line 371 of yacc.c  */
#line 80 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     LONG = 259,
     SHORT = 260,
     CHAR = 261,
     FLOAT = 262,
     DOUBLE = 263,
     _BOOL = 264,
     VOID = 265,
     STRUCT = 266,
     TYPEDEF = 267,
     UNION = 268,
     SIGNED = 269,
     UNSIGNED = 270,
     STATIC = 271,
     AUTO = 272,
     VOLATILE = 273,
     _ATOMIC = 274,
     EXTERN = 275,
     CONST = 276,
     RESTRICT = 277,
     REGISTER = 278,
     IF = 279,
     ELSE = 280,
     WHILE = 281,
     DO = 282,
     FOR = 283,
     SWITCH = 284,
     CASE = 285,
     DEFAULT = 286,
     LABEL = 287,
     RETURN = 288,
     GOTO = 289,
     BREAK = 290,
     CONTINUE = 291,
     SHL = 292,
     SHR = 293,
     LE = 294,
     GE = 295,
     NE = 296,
     EQ = 297,
     LOR = 298,
     LAND = 299,
     SIZEOF = 300,
     INC = 301,
     DEC = 302,
     INDIRECT = 303,
     DOTDOTDOT = 304,
     MUL_EQ = 305,
     DIV_EQ = 306,
     MOD_EQ = 307,
     ADD_EQ = 308,
     SUB_EQ = 309,
     SHL_EQ = 310,
     SHR_EQ = 311,
     AND_EQ = 312,
     XOR_EQ = 313,
     OR_EQ = 314,
     STATEMENT = 315,
     COMPOUND = 316,
     FUNCTION = 317,
     BLOCKLIST = 318,
     DECLARATION = 319,
     DECLARATOR = 320,
     DECLARATOR_LIST = 321,
     INIT_EXPRESSION = 322,
     NEGATE = 323,
     ICONSTANT = 324,
     ID = 325
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 15 "parser.y"

    int d;
	char c;
    char *str;
	struct astnode *node;
	struct tlink *link;


/* Line 387 of yacc.c  */
#line 199 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 227 "parser.tab.c"

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  113

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,     2,     2,     2,    89,    82,     2,
      71,    72,    87,    85,    76,    86,     2,    88,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    75,
      83,    77,    84,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    80,    74,    90,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    18,    21,    25,
      27,    30,    32,    34,    38,    40,    42,    44,    48,    50,
      54,    56,    58,    62,    64,    66,    68,    72,    74,    78,
      80,    82,    88,    90,    94,    96,   100,   102,   106,   108,
     112,   114,   118,   120,   124,   128,   130,   134,   138,   142,
     146,   148,   152,   156,   158,   162,   166,   168,   172,   176,
     180,   182,   184,   187,   190,   193,   196,   198,   200,   204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      93,     0,    -1,    94,    -1,    93,    94,    -1,    95,    -1,
      99,    -1,     3,    70,    71,    72,    96,    -1,    73,    74,
      -1,    73,    97,    74,    -1,    98,    -1,    97,    98,    -1,
      99,    -1,   107,    -1,   100,   102,    75,    -1,   101,    -1,
       3,    -1,   103,    -1,   102,    76,   103,    -1,   104,    -1,
     104,    77,   106,    -1,   105,    -1,    70,    -1,    71,   104,
      72,    -1,   110,    -1,   108,    -1,    96,    -1,    33,   109,
      75,    -1,   110,    -1,   109,    76,   110,    -1,   111,    -1,
     112,    -1,   112,    78,   109,    79,   111,    -1,   113,    -1,
     112,    43,   113,    -1,   114,    -1,   113,    44,   114,    -1,
     115,    -1,   114,    80,   115,    -1,   116,    -1,   115,    81,
     116,    -1,   117,    -1,   116,    82,   117,    -1,   118,    -1,
     117,    42,   118,    -1,   117,    41,   118,    -1,   119,    -1,
     118,    83,   119,    -1,   118,    84,   119,    -1,   118,    39,
     119,    -1,   118,    40,   119,    -1,   120,    -1,   119,    37,
     120,    -1,   119,    38,   120,    -1,   121,    -1,   120,    85,
     121,    -1,   120,    86,   121,    -1,   123,    -1,   121,    87,
     123,    -1,   121,    88,   123,    -1,   121,    89,   123,    -1,
     123,    -1,   124,    -1,    85,   122,    -1,    86,   122,    -1,
      90,   122,    -1,    91,   122,    -1,   125,    -1,    69,    -1,
      71,   109,    72,    -1,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    59,    59,    60,    64,    65,    69,    73,    74,    78,
      79,    83,    84,    88,    92,    96,   100,   101,   104,   105,
     109,   113,   114,   118,   123,   124,   128,   132,   133,   141,
     145,   146,   151,   152,   156,   157,   161,   162,   166,   167,
     171,   172,   176,   177,   178,   182,   183,   184,   185,   186,
     190,   191,   192,   196,   197,   198,   202,   203,   204,   205,
     209,   213,   214,   215,   216,   217,   221,   224,   225,   226
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "LONG", "SHORT", "CHAR", "FLOAT",
  "DOUBLE", "_BOOL", "VOID", "STRUCT", "TYPEDEF", "UNION", "SIGNED",
  "UNSIGNED", "STATIC", "AUTO", "VOLATILE", "_ATOMIC", "EXTERN", "CONST",
  "RESTRICT", "REGISTER", "IF", "ELSE", "WHILE", "DO", "FOR", "SWITCH",
  "CASE", "DEFAULT", "LABEL", "RETURN", "GOTO", "BREAK", "CONTINUE", "SHL",
  "SHR", "LE", "GE", "NE", "EQ", "LOR", "LAND", "SIZEOF", "INC", "DEC",
  "INDIRECT", "DOTDOTDOT", "MUL_EQ", "DIV_EQ", "MOD_EQ", "ADD_EQ",
  "SUB_EQ", "SHL_EQ", "SHR_EQ", "AND_EQ", "XOR_EQ", "OR_EQ", "STATEMENT",
  "COMPOUND", "FUNCTION", "BLOCKLIST", "DECLARATION", "DECLARATOR",
  "DECLARATOR_LIST", "INIT_EXPRESSION", "NEGATE", "ICONSTANT", "ID", "'('",
  "')'", "'{'", "'}'", "';'", "','", "'='", "'?'", "':'", "'|'", "'^'",
  "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'!'",
  "$accept", "translation_unit", "external_declaration",
  "function_definition", "compound_statement", "block_item_list",
  "block_item", "declaration", "declaration_specifiers", "type_qualifier",
  "init_declarator_list", "init_declarator", "declarator",
  "direct_declarator", "initializer", "statement", "jump_statement",
  "expression", "assignment_expression", "conditional_expression",
  "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "primary_expression", YY_NULL
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,    40,    41,   123,   125,    59,    44,    61,    63,    58,
     124,    94,    38,    60,    62,    43,    45,    42,    47,    37,
     126,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    94,    94,    95,    96,    96,    97,
      97,    98,    98,    99,   100,   101,   102,   102,   103,   103,
     104,   105,   105,   106,   107,   107,   108,   109,   109,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   117,   117,   117,   118,   118,   118,   118,   118,
     119,   119,   119,   120,   120,   120,   121,   121,   121,   121,
     122,   123,   123,   123,   123,   123,   124,   125,   125,   125
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     5,     2,     3,     1,
       2,     1,     1,     3,     1,     1,     1,     3,     1,     3,
       1,     1,     3,     1,     1,     1,     3,     1,     3,     1,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     1,     2,     2,     2,     2,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,     0,     2,     4,     5,     0,    14,     0,     1,
       3,    21,     0,     0,    16,    18,    20,     0,     0,    13,
       0,     0,     0,    22,    17,    67,    69,     0,     0,     0,
       0,     0,    19,    23,    29,    30,    32,    34,    36,    38,
      40,    42,    45,    50,    53,    56,    61,    66,     0,     6,
       0,    27,    62,    60,    63,    64,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     7,    25,
       0,     9,    11,    12,    24,    68,     0,    33,     0,    35,
      37,    39,    41,    44,    43,    48,    49,    46,    47,    51,
      52,    54,    55,    57,    58,    59,     0,     8,    10,    28,
       0,    26,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    79,    80,    81,     5,     6,     7,
      13,    14,    15,    16,    32,    83,    84,    50,    51,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      52,    45,    46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -62
static const yytype_int8 yypact[] =
{
      20,   -39,    21,   -62,   -62,   -62,   -44,   -62,   -24,   -62,
     -62,   -62,   -44,   -30,   -62,   -12,   -62,   -29,     2,   -62,
     -44,   -57,     3,   -62,   -62,   -62,   -62,   -57,   -57,   -57,
     -57,   -57,   -62,   -62,   -62,   -34,    25,    -5,     0,     1,
      12,   -32,    18,   -28,   -51,   -62,   -62,   -62,    -3,   -62,
     -61,   -62,   -62,   -62,   -62,   -62,   -62,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -62,   -57,   -62,   -62,
      -1,   -62,   -62,   -62,   -62,   -62,   -57,    25,   -54,    -5,
       0,     1,    12,   -32,   -32,    18,    18,    18,    18,   -28,
     -28,   -51,   -51,   -62,   -62,   -62,   -16,   -62,   -62,   -62,
     -57,   -62,   -62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,    75,   -62,    56,   -62,     4,   -38,   -62,   -62,
     -62,    59,    68,   -62,   -62,   -62,   -62,   -42,   -20,   -23,
     -62,    28,    23,    26,    27,    29,    -2,   -48,    -6,    -4,
      10,   -25,   -62,   -62
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      76,    33,    76,    53,    53,    53,    53,    65,    66,    57,
      82,    85,    25,    26,    27,    86,    88,    95,    96,    97,
      98,     9,    86,     1,     1,   110,    11,    12,    28,    29,
      77,     8,    77,    30,    31,   106,    73,    74,    75,    54,
      55,    56,    82,    22,    58,    19,    20,    17,   103,   104,
     105,    67,    68,    63,    64,    69,    70,    71,    72,   111,
      86,    93,    94,    99,   100,    21,   109,   101,   102,    59,
      48,    78,    48,   107,    23,    60,    48,    10,    49,    24,
      18,    61,    89,    62,   108,    87,    90,   112,    91,     0,
       0,    92
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-62)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       3,    21,     3,    28,    29,    30,    31,    39,    40,    43,
      48,    72,    69,    70,    71,    76,    58,    65,    66,    67,
      68,     0,    76,     3,     3,    79,    70,    71,    85,    86,
      33,    70,    33,    90,    91,    77,    87,    88,    89,    29,
      30,    31,    80,    72,    78,    75,    76,    71,    73,    74,
      75,    83,    84,    41,    42,    37,    38,    85,    86,    75,
      76,    63,    64,    69,    70,    77,    86,    71,    72,    44,
      73,    74,    73,    74,    72,    80,    73,     2,    22,    20,
      12,    81,    59,    82,    80,    57,    60,   110,    61,    -1,
      -1,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    93,    94,    95,    99,   100,   101,    70,     0,
      94,    70,    71,   102,   103,   104,   105,    71,   104,    75,
      76,    77,    72,    72,   103,    69,    70,    71,    85,    86,
      90,    91,   106,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   123,   124,   125,    73,    96,
     109,   110,   122,   123,   122,   122,   122,    43,    78,    44,
      80,    81,    82,    41,    42,    39,    40,    83,    84,    37,
      38,    85,    86,    87,    88,    89,     3,    33,    74,    96,
      97,    98,    99,   107,   108,    72,    76,   113,   109,   114,
     115,   116,   117,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   123,   123,   123,   109,    74,    98,   110,
      79,    75,   111
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 4:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    {func_eval((yyvsp[(1) - (1)].node));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 65 "parser.y"
    {yyerror("Error: global declaration not implemented\n");}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 69 "parser.y"
    {(yyval.node)=newast(FUNCTION,(void*)(yyvsp[(2) - (5)].str),(yyvsp[(5) - (5)].node));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 73 "parser.y"
    {(yyval.node)=newast(COMPOUND,NULL,NULL);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {(yyval.node)=newast(COMPOUND,(yyvsp[(2) - (3)].node),NULL);}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 78 "parser.y"
    {(yyval.node)=newast(BLOCKLIST,NULL,(yyvsp[(1) - (1)].node));}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    {(yyval.node)=newast(BLOCKLIST,(yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].node));}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 83 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 84 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 88 "parser.y"
    {(yyval.node)=newast(DECLARATION,(yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].node));}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    {(yyval.node)=newast((yyvsp[(1) - (1)].d),NULL,NULL);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    {(yyval.d)=INT;}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    {(yyval.node)=newast(DECLARATOR_LIST,NULL,(yyvsp[(1) - (1)].node));}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    {(yyval.node)=newast(DECLARATOR_LIST,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 104 "parser.y"
    {(yyval.node)=newast(DECLARATOR,(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    {(yyval.node)=newast(DECLARATOR,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 109 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    {(yyval.node)=newast(ID,(yyvsp[(1) - (1)].str),NULL);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 118 "parser.y"
    {(yyval.node)=newast(INIT_EXPRESSION,(yyvsp[(1) - (1)].node),NULL);}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 124 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 128 "parser.y"
    {(yyval.node)=newast(RETURN,(yyvsp[(2) - (3)].node),NULL);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 133 "parser.y"
    {(yyval.node)=newast(',',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    {(yyval.node)=newast('?',(yyvsp[(1) - (5)].node),newast(':',(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)));}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    {(yyval.node)=newast(LOR,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {(yyval.node)=newast(LAND,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    {(yyval.node)=newast('|',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 166 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 167 "parser.y"
    {(yyval.node)=newast('^',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 171 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    {(yyval.node)=newast('&',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    {(yyval.node)=newast(EQ,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 178 "parser.y"
    {(yyval.node)=newast(NE,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 182 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    {(yyval.node)=newast('<',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 184 "parser.y"
    {(yyval.node)=newast('>',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 185 "parser.y"
    {(yyval.node)=newast(LE,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    {(yyval.node)=newast(GE,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 191 "parser.y"
    {(yyval.node)=newast(SHL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    {(yyval.node)=newast(SHL,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 196 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    {(yyval.node)=newast('+',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 198 "parser.y"
    {(yyval.node)=newast('-',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 203 "parser.y"
    {(yyval.node)=newast('*',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 204 "parser.y"
    {(yyval.node)=newast('/',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 205 "parser.y"
    {(yyval.node)=newast('%',(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 213 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 214 "parser.y"
    {(yyval.node)=(yyvsp[(2) - (2)].node);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 215 "parser.y"
    {(yyval.node)=newast(NEGATE,(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 216 "parser.y"
    {(yyval.node)=newast('~',(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    {(yyval.node)=newast('!',(yyvsp[(2) - (2)].node),NULL);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    {(yyval.node)=(yyvsp[(1) - (1)].node);}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 224 "parser.y"
    {(yyval.node)=(void*)newnumber(ICONSTANT,(yyvsp[(1) - (1)].d));}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 225 "parser.y"
    {(yyval.node)=(yyvsp[(2) - (3)].node);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 226 "parser.y"
    {(yyval.node)=newast(ID,(yyvsp[(1) - (1)].str),NULL);}
    break;


/* Line 1792 of yacc.c  */
#line 1924 "parser.tab.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 229 "parser.y"



