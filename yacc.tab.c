/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <fstream>
#include "main.h"

using namespace std;
extern "C"{
	void yyerror(string s);
	extern int yylex(void);
}

Symbol_Table symbol_table;
fstream output;
vector<array_range> range;
int error = 0;
string className = "example";
bool hasValue = false;
Label label;
bool first = true;

#line 94 "yacc.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    DOT = 259,
    COMMA = 260,
    COLON = 261,
    SEMICOLON = 262,
    LP = 263,
    RP = 264,
    LMB = 265,
    RMB = 266,
    LB = 267,
    RB = 268,
    MOD = 269,
    ADD = 270,
    SUB = 271,
    MUL = 272,
    DIV = 273,
    LT = 274,
    LET = 275,
    GETH = 276,
    GT = 277,
    EQ = 278,
    NEQ = 279,
    AND = 280,
    OR = 281,
    NOT = 282,
    ARRAY = 283,
    BYG = 284,
    BOOL = 285,
    CHAR = 286,
    CONST = 287,
    DECREASING = 288,
    DEFAULT = 289,
    DO = 290,
    ELSE = 291,
    END = 292,
    EXIT = 293,
    FAL = 294,
    FOR = 295,
    FUNCTION = 296,
    GET = 297,
    IF = 298,
    INT = 299,
    LOOP = 300,
    OF = 301,
    PUT = 302,
    PROCEDURE = 303,
    REAL = 304,
    RESULT = 305,
    RETURN = 306,
    SKIP = 307,
    STR = 308,
    THEN = 309,
    TRU = 310,
    VAR = 311,
    WHEN = 312,
    INTEGER = 313,
    FLOAT = 314,
    BOOLEAN = 315,
    IDENTIFIER = 316,
    STRING = 317,
    UMINUS = 318
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   452

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  256

#define YYUNDEFTOK  2
#define YYMAXUTOK   318


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    52,    53,    54,    54,    72,    73,    74,
      75,    76,    79,    80,    81,    82,    85,    85,    85,   157,
     157,   246,   246,   269,   269,   336,   339,   351,   368,   368,
     392,   392,   413,   413,   455,   455,   501,   537,   556,   557,
     560,   561,   562,   563,   564,   567,   567,   585,   588,   620,
     628,   628,   650,   651,   652,   653,   654,   655,   659,   660,
     661,   699,   737,   819,   857,   895,   979,   980,  1014,  1048,
    1066,  1095,  1117,  1139,  1161,  1177,  1201,  1244,  1277,  1370,
    1401,  1449,  1450,  1460,  1470,  1477,  1500,  1627,  1633,  1645,
    1645,  1652,  1645,  1663,  1663,  1663,  1674,  1675,  1713,  1751,
    1833,  1871,  1909,  1991,  2025,  2060,  2078,  2202,  2219,  2220,
    2221,  2222,  2225,  2225,  2235,  2235,  2274,  2274,  2304,  2314,
    2324,  2331,  2354
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "DOT", "COMMA", "COLON",
  "SEMICOLON", "LP", "RP", "LMB", "RMB", "LB", "RB", "MOD", "ADD", "SUB",
  "MUL", "DIV", "LT", "LET", "GETH", "GT", "EQ", "NEQ", "AND", "OR", "NOT",
  "ARRAY", "BYG", "BOOL", "CHAR", "CONST", "DECREASING", "DEFAULT", "DO",
  "ELSE", "END", "EXIT", "FAL", "FOR", "FUNCTION", "GET", "IF", "INT",
  "LOOP", "OF", "PUT", "PROCEDURE", "REAL", "RESULT", "RETURN", "SKIP",
  "STR", "THEN", "TRU", "VAR", "WHEN", "INTEGER", "FLOAT", "BOOLEAN",
  "IDENTIFIER", "STRING", "UMINUS", "$accept", "init", "program", "$@1",
  "declarations", "type", "function_declarations", "$@2", "$@3", "$@4",
  "procedure_declarations", "$@5", "$@6", "formal_arguments", "args",
  "const_declarations", "$@7", "$@8", "variable_declarations", "$@9",
  "$@10", "array_declarations", "statement_sequence", "statements",
  "block", "$@11", "simple", "$@12", "expressions", "operand_expression",
  "procedure_invocation", "operand_term", "arguments", "conditional",
  "$@13", "$@14", "$@15", "$@16", "$@17", "boolean_expression",
  "description", "loop", "$@18", "$@19", "$@20", "const_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-94)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     195,   -23,   -48,   -18,    -7,   -21,    -6,    30,  -121,  -121,
       5,   155,  -121,  -121,     6,    95,    65,  -121,   195,  -121,
    -121,  -121,  -121,  -121,  -121,   157,  -121,  -121,  -121,  -121,
    -121,  -121,   212,    26,    30,     9,    72,    63,  -121,    30,
     161,   161,  -121,  -121,   279,   261,  -121,   400,  -121,    25,
     212,   155,    87,   155,   161,  -121,    39,  -121,   413,    45,
     155,     0,   155,  -121,  -121,   195,  -121,    48,   212,   212,
     212,    75,  -121,    64,  -121,   108,   170,   106,   297,   114,
     161,  -121,   315,    15,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,    88,    90,
    -121,     2,   119,   333,   392,   161,   161,   161,   161,   161,
     161,   161,   161,  -121,    53,  -121,  -121,   140,   138,   148,
    -121,   101,  -121,  -121,  -121,  -121,   170,  -121,  -121,  -121,
    -121,   159,   170,  -121,  -121,  -121,  -121,  -121,   156,   158,
     105,  -121,  -121,   387,  -121,   164,    19,  -121,   132,   132,
    -121,  -121,   426,   426,   426,   426,   426,   426,   351,   369,
     212,   212,   120,  -121,   168,   166,  -121,  -121,   426,   426,
     426,   426,   426,   426,   392,   104,   170,   109,   167,   155,
    -121,   173,    64,  -121,  -121,   175,   176,    64,   174,  -121,
    -121,  -121,  -121,  -121,   212,    64,  -121,  -121,   180,  -121,
    -121,   155,   170,   181,   170,  -121,   183,   160,   169,   188,
     187,   212,   189,   170,  -121,  -121,   170,  -121,   212,    64,
    -121,   151,   137,   105,   197,   143,  -121,  -121,   212,   202,
    -121,   212,  -121,  -121,  -121,   142,   165,   212,   211,   144,
     212,   216,  -121,    64,   221,   172,  -121,   223,   206,  -121,
     186,  -121,   149,  -121,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    45,     0,    56,     0,     0,     0,     0,   112,    50,
       0,     0,    54,    57,     0,     0,     0,     2,     3,    10,
      11,     7,     9,     8,     5,    38,    40,    41,    44,    42,
      43,    47,   108,     0,     0,     0,     0,     0,    52,     0,
       0,     0,    83,    84,   107,   106,    82,     0,    66,     0,
     108,     0,     0,     0,     0,    85,    86,    53,    58,     0,
       0,     0,     0,     1,     4,     3,    39,     0,   108,   108,
     108,     0,    30,     0,    55,     0,     0,    16,     0,     0,
       0,    75,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
      51,     0,     0,     0,    69,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,    48,    77,    87,     0,     0,
       6,     0,   109,   110,   111,    46,     0,    15,    13,    14,
      12,     0,     0,   119,   120,   121,   122,   118,     0,     0,
       0,    81,    96,     0,    79,     0,     0,    74,    70,    71,
      72,    73,    97,    98,   100,   101,    99,   102,   104,   103,
     108,   108,     0,    23,     0,     0,    25,    59,    60,    61,
      63,    64,    62,    65,    68,    67,     0,     0,    36,     0,
      76,     0,     0,    31,    28,     0,     0,     0,     0,    78,
      80,    90,    94,   113,   108,     0,    21,    33,     0,    34,
      88,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      26,   108,     0,     0,    49,    29,     0,   116,   108,     0,
      91,     0,     0,     0,     0,     0,    35,   114,   108,     0,
      17,   108,    95,    24,    27,     0,     0,   108,     0,     0,
     108,     0,    22,     0,     0,     0,    20,     0,     0,    37,
       0,   117,     0,    92,   115,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -121,  -121,    -1,  -121,  -121,   -71,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,   121,    42,     4,  -121,  -121,     7,  -121,
    -121,  -121,     3,  -121,  -121,  -121,  -121,  -121,   -10,    46,
    -121,  -121,   -78,  -121,  -121,  -121,  -121,  -121,  -121,   -24,
     -50,  -121,  -121,  -121,  -121,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,    17,    65,    18,   178,    19,   140,   240,   218,
      20,   211,   194,   165,   166,    68,   202,   126,    69,   176,
     213,    23,    70,    25,    26,    32,    27,    51,   117,    58,
      28,    48,   118,    29,   160,   207,   231,   161,   208,    49,
      71,    30,    50,   237,   228,   138
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      99,    57,   131,    24,    21,   145,   183,    22,    53,   116,
      74,   163,   185,    33,    31,    79,    40,    64,   122,   123,
     124,    24,    21,    53,   144,    22,    35,    54,    66,    72,
     190,    40,    73,    85,    86,    87,    88,    89,    39,    34,
      37,   100,    54,   102,   111,   112,    40,    83,   113,    84,
     115,   114,   119,    47,    36,    38,   197,    41,    42,    43,
      55,    56,    46,   164,   120,    63,    52,    59,    24,    21,
      75,    77,    22,    42,    43,    55,    56,    46,    76,    98,
      47,   177,   215,   127,   217,    78,    81,    82,    42,    43,
      44,    45,    46,   226,   127,   101,   227,   128,    60,   103,
     104,   200,   129,    61,   113,    62,   130,   182,   128,   121,
     191,   192,   125,   129,   132,   139,   205,   130,    85,    86,
      87,    88,    89,   142,   210,   -93,   143,   162,   167,   111,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   209,   179,    85,   180,   230,    88,
      89,   168,   169,   170,   171,   172,   173,   174,   175,   181,
     186,   224,   184,    53,   187,   193,   164,   198,   229,    80,
     199,    40,   249,   189,   195,   196,   201,    40,   238,   203,
     204,   241,    54,   206,   212,   216,     1,   244,    54,   219,
     247,   214,   223,   225,   232,     3,   220,     4,   233,     6,
       7,   236,     8,   242,     9,   246,   221,    11,    12,    13,
     255,   243,   251,    42,    43,    55,    56,    46,    15,    42,
      43,    55,    56,    46,     1,   222,   254,     2,   133,   134,
     135,   136,   137,     3,   235,     4,     5,     6,     7,   239,
       8,     1,     9,    10,     2,    11,    12,    13,   245,   253,
       3,    14,     4,   248,     6,     7,    15,     8,   250,     9,
     252,   188,    11,    12,    13,   234,     0,     0,    67,    83,
     -86,    84,     0,    15,     0,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -85,     0,
       0,     0,     0,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   141,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   -69,     0,     0,     0,     0,    85,
      86,    87,    88,    89,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   141,     0,     0,     0,     0,    85,    86,    87,
      88,    89,   105,   106,   107,   108,   109,   110,   111,   112,
     -68,     0,     0,     0,     0,    85,    86,    87,    88,    89,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -67,     0,
       0,     0,     0,    85,    86,    87,    88,    89,   -67,   -67,
     -67,   -67,   -67,   -67,   111,   -67,   141,     0,     0,     0,
       0,    85,    86,    87,    88,    89,    85,    86,    87,    88,
      89,     0,   111,   112,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    85,    86,    87,
      88,    89,   105,   106,   107,   108,   109,   110,   111,   112,
      85,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,   111,   112
};

static const yytype_int16 yycheck[] =
{
      50,    11,    73,     0,     0,    83,   126,     0,     8,     9,
      34,     9,   132,    61,    37,    39,    16,    18,    68,    69,
      70,    18,    18,     8,     9,    18,    33,    27,    25,     3,
      11,    16,     6,    14,    15,    16,    17,    18,     8,    57,
      61,    51,    27,    53,    25,    26,    16,     8,     3,    10,
      60,     6,    62,     7,    61,    61,   176,    27,    58,    59,
      60,    61,    62,    61,    65,     0,    61,    61,    65,    65,
      61,     8,    65,    58,    59,    60,    61,    62,     6,    54,
      34,    28,   202,    30,   204,    39,    40,    41,    58,    59,
      60,    61,    62,   213,    30,     8,   216,    44,     3,    53,
      54,   179,    49,     8,     3,    10,    53,     6,    44,    61,
     160,   161,    37,    49,     6,     9,   187,    53,    14,    15,
      16,    17,    18,     9,   195,    37,    80,    37,     9,    25,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   194,     5,    14,     9,   219,    17,
      18,   105,   106,   107,   108,   109,   110,   111,   112,    11,
       4,   211,     3,     8,     6,    45,    61,    58,   218,     8,
       3,    16,   243,     9,     6,     9,     3,    16,   228,     4,
       4,   231,    27,     9,     4,     4,    29,   237,    27,     6,
     240,   201,     5,     4,    43,    38,    36,    40,    61,    42,
      43,    58,    45,    61,    47,    61,    37,    50,    51,    52,
      61,    46,    40,    58,    59,    60,    61,    62,    61,    58,
      59,    60,    61,    62,    29,    37,    40,    32,    58,    59,
      60,    61,    62,    38,    37,    40,    41,    42,    43,    37,
      45,    29,    47,    48,    32,    50,    51,    52,    37,    43,
      38,    56,    40,    37,    42,    43,    61,    45,    37,    47,
      37,   140,    50,    51,    52,   223,    -1,    -1,    56,     8,
       9,    10,    -1,    61,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     9,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     9,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     9,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     9,    -1,    -1,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       9,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     9,    -1,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     9,    -1,    -1,    -1,
      -1,    14,    15,    16,    17,    18,    14,    15,    16,    17,
      18,    -1,    25,    26,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    32,    38,    40,    41,    42,    43,    45,    47,
      48,    50,    51,    52,    56,    61,    65,    66,    68,    70,
      74,    79,    82,    85,    86,    87,    88,    90,    94,    97,
     105,    37,    89,    61,    57,    33,    61,    61,    61,     8,
      16,    27,    58,    59,    60,    61,    62,    93,    95,   103,
     106,    91,    61,     8,    27,    60,    61,    92,    93,    61,
       3,     8,    10,     0,    66,    67,    86,    56,    79,    82,
      86,   104,     3,     6,   103,    61,     6,     8,    93,   103,
       8,    93,    93,     8,    10,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    54,   104,
      92,     8,    92,    93,    93,    19,    20,    21,    22,    23,
      24,    25,    26,     3,     6,    92,     9,    92,    96,    92,
      66,    61,   104,   104,   104,    37,    81,    30,    44,    49,
      53,    69,     6,    58,    59,    60,    61,    62,   109,     9,
      71,     9,     9,    93,     9,    96,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      98,   101,    37,     9,    61,    77,    78,     9,    93,    93,
      93,    93,    93,    93,    93,    93,    83,    28,    69,     5,
       9,    11,     6,   109,     3,   109,     4,     6,    77,     9,
      11,   104,   104,    45,    76,     6,     9,   109,    58,     3,
      96,     3,    80,     4,     4,    69,     9,    99,   102,   104,
      69,    75,     4,    84,    92,   109,     4,   109,    73,     6,
      36,    37,    37,     5,   104,     4,   109,   109,   108,   104,
      69,   100,    43,    61,    78,    37,    58,   107,   104,    37,
      72,   104,    61,    46,   104,    37,    61,   104,    37,    69,
      37,    40,    37,    43,    40,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    66,    68,    68,    68,
      68,    68,    69,    69,    69,    69,    71,    72,    70,    73,
      70,    75,    74,    76,    74,    77,    78,    78,    80,    79,
      81,    79,    83,    82,    84,    82,    82,    85,    86,    86,
      87,    87,    87,    87,    87,    89,    88,    88,    90,    90,
      91,    90,    90,    90,    90,    90,    90,    90,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    98,
      99,   100,    97,   101,   102,    97,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   106,   105,   107,   105,   108,   105,   109,   109,
     109,   109,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,    12,     0,
      10,     0,     9,     0,     8,     1,     3,     5,     0,     7,
       0,     5,     0,     5,     0,     7,     4,    10,     1,     2,
       1,     1,     1,     1,     1,     0,     4,     2,     3,     6,
       0,     3,     2,     2,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     2,
       3,     3,     3,     3,     3,     2,     4,     3,     4,     3,
       4,     3,     1,     1,     1,     1,     1,     1,     3,     0,
       0,     0,    11,     0,     0,     8,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     0,     2,
       2,     2,     0,     5,     0,    12,     0,    11,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 5:
#line 54 "yacc.y"
                                     {
					if(first){
						output << "class " << className << endl;
						output << "{" << endl;
						output << "method public static void main(java.lang.String[])" << endl;
						output << "max_stack 15"<< endl;
						output << "max_locals 15" << endl;
						output << "{" << endl;
					}
					first = false;
				}
#line 1607 "yacc.tab.c"
    break;

  case 6:
#line 65 "yacc.y"
                                        {
					output << "}" << endl;
					output << "return" << endl;
					output << "}" << endl;	
				}
#line 1617 "yacc.tab.c"
    break;

  case 12:
#line 79 "yacc.y"
                {(yyval.typical_type) = 0;}
#line 1623 "yacc.tab.c"
    break;

  case 13:
#line 80 "yacc.y"
                {(yyval.typical_type) = 1;}
#line 1629 "yacc.tab.c"
    break;

  case 14:
#line 81 "yacc.y"
                {(yyval.typical_type) = 2;}
#line 1635 "yacc.tab.c"
    break;

  case 15:
#line 82 "yacc.y"
                {(yyval.typical_type) = 3;}
#line 1641 "yacc.tab.c"
    break;

  case 16:
#line 85 "yacc.y"
                                                 {symbol_table.create();}
#line 1647 "yacc.tab.c"
    break;

  case 17:
#line 85 "yacc.y"
                                                                                                         {
										output << "method public static ";
										switch((yyvsp[0].typical_type)){
											case 0:
												output << "java.lang.String ";
												break;
											case 1:
												output << "int ";
												break;
											case 2: 
												output << "float ";
												break;
											case 3: //bool
												output << "int ";
												break;
											default:
												output << "ERROR ";
												break;
										}
										output << (yyvsp[-6].variable) << "(";
										vector<int> arg = (yyvsp[-3].argument_list);
										for(int i=0;i<arg.size();i++){
											switch(arg[i]){
												case 0:
													output << "java.lang.String";
													break;
												case 1:
													output << "int";
													break;
												case 2: 
													output << "float";
													break;
												case 3: // bool
													output << "int";
													break;
												default:
													output << "ERROR";
													break;
											}
											if(i != arg.size() - 1){
												output<<", ";
											}
										}
										output << ")" << endl;
									    	output << "max_stack 15" << endl;
									    	output << "max_locals 15" << endl;
										output << "{" << endl;
										
										cout << symbol_table.table_index << endl;
										symbol_table.argument_place.push_back(symbol_table.table_index);
										vector<int> where;
										where = symbol_table.ALL_lookup((yyvsp[-6].variable));
										if(where.empty()){
											symbol_node temp;
											temp.name = (yyvsp[-6].variable);
											temp.content = "none";
											temp.type = (yyvsp[0].typical_type);
											temp.Symbol_type = 0;
											temp.argument_type = (yyvsp[-3].argument_list);
											symbol_table.insert(temp);
										}
										else{
											yyerror("this id is already exist(function)");
										}
										}
#line 1717 "yacc.tab.c"
    break;

  case 18:
#line 150 "yacc.y"
                                                                                                                        {
											output << "}" << endl;
											//vector<vector<symbol_node> >::iterator it;
											//it = symbol_table.symboltable.begin() + symbol_table.table_index;
											symbol_table.dump(symbol_table.table_index);
											//symbol_table.symboltable.erase(it);
											}
#line 1729 "yacc.tab.c"
    break;

  case 19:
#line 157 "yacc.y"
                                                               {
								output << "method public static ";
								switch((yyvsp[0].typical_type)){
									case 0:
										output << "java.lang.String ";
										break;
									case 1:
										output << "int ";
										break;
									case 2: 
										output << "float ";
										break;
									case 3: //bool
										output << "int ";
										break;
									default:
										output << "ERROR ";
										break;
								}	
								output << (yyvsp[-4].variable) << "()" << endl;
								output << "max_stack 15" << endl;
								output << "max_locals 15" << endl;
								output << "{" << endl;	
								symbol_table.create();
								vector<int> where;
								where = symbol_table.ALL_lookup((yyvsp[-4].variable));
								if(where.empty()){
									symbol_node temp;
									temp.name = (yyvsp[-4].variable);
									temp.content = "none";
									temp.type = (yyvsp[0].typical_type);
									temp.Symbol_type = 0;
									symbol_table.insert(temp);
								}
								else{
									yyerror("this id is already exist(function)");
								}
								}
#line 1772 "yacc.tab.c"
    break;

  case 20:
#line 195 "yacc.y"
                                                                                                {
								output << "}" << endl;
								//vector<vector<symbol_node> >::iterator it;
								//it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								//symbol_table.symboltable.erase(it);
								}
#line 1784 "yacc.tab.c"
    break;

  case 21:
#line 246 "yacc.y"
                                                                      { 
									symbol_table.create(); symbol_table.argument_place.push_back(symbol_table.table_index);
									vector<int> where;
									where = symbol_table.ALL_lookup((yyvsp[-3].variable));
									if(where.empty()){
										symbol_node temp;
										temp.name = (yyvsp[-3].variable);
										temp.content = "none";
										temp.type = -1;
										temp.Symbol_type = 1;
										temp.argument_type = (yyvsp[-1].argument_list);
										symbol_table.insert(temp);
									}
									else{
										yyerror("this id is already exist(procedure)");
									}
									}
#line 1806 "yacc.tab.c"
    break;

  case 22:
#line 263 "yacc.y"
                                                                                                        {
									//vector<vector<symbol_node> >::iterator it;
									//it = symbol_table.symboltable.begin() + symbol_table.table_index;
									symbol_table.dump(symbol_table.table_index);
									//symbol_table.symboltable.erase(it);
									}
#line 1817 "yacc.tab.c"
    break;

  case 23:
#line 269 "yacc.y"
                                                     { symbol_table.create();
									vector<int> where;
									where = symbol_table.ALL_lookup((yyvsp[-2].variable));
									if(where.empty()){
										symbol_node temp;
										temp.name = (yyvsp[-2].variable);
										temp.content = "none";
										temp.type = -1;
										temp.Symbol_type = 1;
										symbol_table.insert(temp);
									}
									else{
										yyerror("this id is already exist(procedure)");
									}
									}
#line 1837 "yacc.tab.c"
    break;

  case 24:
#line 284 "yacc.y"
                                                                                                        {
									//vector<vector<symbol_node> >::iterator it;
									//it = symbol_table.symboltable.begin() + symbol_table.table_index;
									symbol_table.dump(symbol_table.table_index);
									//symbol_table.symboltable.erase(it);
									}
#line 1848 "yacc.tab.c"
    break;

  case 26:
#line 339 "yacc.y"
                                                {
							vector<int> temp;
							temp = (yyval.argument_list);
							temp.push_back((yyvsp[0].typical_type));
							symbol_node node;
							node.name = (yyvsp[-2].variable);
							node.type = (yyvsp[0].typical_type);
							node.Symbol_type = 3;
							
							symbol_table.insert(node);
							(yyval.argument_list) = temp;						
							}
#line 1865 "yacc.tab.c"
    break;

  case 27:
#line 351 "yacc.y"
                                                                {
								vector<int> temp;
								temp = (yyvsp[0].argument_list);
								temp.push_back((yyvsp[-2].typical_type));
								/*for(int i = 0;i < temp.size();i++){
									cout << temp[i] << " | ";
								}
								cout << endl;*/
								symbol_node node;
								node.name = (yyvsp[-4].variable);
								node.type = (yyvsp[-2].typical_type);
								node.Symbol_type = 3;
								symbol_table.insert(node);
								(yyval.argument_list) = temp;
								}
#line 1885 "yacc.tab.c"
    break;

  case 28:
#line 368 "yacc.y"
                                                             {hasValue = true;}
#line 1891 "yacc.tab.c"
    break;

  case 29:
#line 368 "yacc.y"
                                                                                                        { 
											if(symbol_table.scope_lookup(symbol_table.table_index,(yyvsp[-5].variable))== 99999){
												if ((yyvsp[-3].typical_type) == (yyvsp[0].expr_result).type){
													if((yyvsp[0].expr_result).isNotVariable){
														symbol_node temp;
														temp.name = (yyvsp[-5].variable);
														temp.content = (yyvsp[0].expr_result).content;
														temp.type = (yyvsp[-3].typical_type);
														temp.Symbol_type = 2;
														symbol_table.insert(temp);
													}	
													else{
														yyerror("can't assign variable to const");
													}
												}
												else{
													yyerror("CONST TYPE ERROR");
												}
											}
											else{
												yyerror("this id is already exist(const)");
											}
											hasValue = false;
											}
#line 1920 "yacc.tab.c"
    break;

  case 30:
#line 392 "yacc.y"
                                                  {hasValue = true;}
#line 1926 "yacc.tab.c"
    break;

  case 31:
#line 392 "yacc.y"
                                                                                        {
									if(symbol_table.scope_lookup(symbol_table.table_index,(yyvsp[-3].variable)) == 99999){
										if((yyvsp[0].expr_result).isNotVariable){
											symbol_node temp;
											temp.name = (yyvsp[-3].variable);
											temp.content = (yyvsp[0].expr_result).content;
											temp.type = (yyvsp[0].expr_result).type;
											temp.Symbol_type = 2;
											symbol_table.insert(temp);
										}
										else{
											yyerror("can't assign variable to const");
										} 
									}
									else{
										yyerror("this id is already exist(const)");
									}
									hasValue = false;
									}
#line 1950 "yacc.tab.c"
    break;

  case 32:
#line 413 "yacc.y"
                                                {hasValue = true;}
#line 1956 "yacc.tab.c"
    break;

  case 33:
#line 413 "yacc.y"
                                                                                        { 
									if(symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[-3].variable)) == 99999){
										
										symbol_node temp;
										temp.name = (yyvsp[-3].variable);
										temp.content = (yyvsp[0].expr_result).content;
										temp.type = (yyvsp[0].expr_result).type;
										temp.Symbol_type = 3;
										symbol_table.insert(temp);
										int where = symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[-3].variable));
										if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
											output << "field static ";
											switch(symbol_table.symboltable[symbol_table.table_index][where].type){
											case 0:
												output << "java.lang.String ";
												break;
											case 1:
												output << "int ";
												break;
											case 2: 
												output << "float ";
												break;
											case 3: //bool
												output << "int ";
												break;
											default:
												output << "ERROR ";
												break;
											}
											output << symbol_table.symboltable[symbol_table.table_index][where].name  << "=" << (yyvsp[0].expr_result).content << endl;
										}
										else{
											output << "sipush " << (yyvsp[0].expr_result).content << endl;
                                							output << "istore " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
										}
										
									}
									else{
										yyerror("this id is already exist(var)");
									}	
									hasValue = false;					
									}
#line 2003 "yacc.tab.c"
    break;

  case 34:
#line 455 "yacc.y"
                                                           {hasValue = true;}
#line 2009 "yacc.tab.c"
    break;

  case 35:
#line 455 "yacc.y"
                                                                                                {
									if(symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[-5].variable)) == 99999){
										if ((yyvsp[-3].typical_type) == (yyvsp[0].expr_result).type){
											symbol_node temp;
											temp.name = (yyvsp[-5].variable);
											temp.content = (yyvsp[0].expr_result).content;
											temp.type = (yyvsp[-3].typical_type);
											temp.Symbol_type = 3;
											symbol_table.insert(temp);
											int where = symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[-5].variable));
											if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
												output << "field static ";
												switch(symbol_table.symboltable[symbol_table.table_index][where].type){
												case 0:
													output << "java.lang.String ";
													break;
												case 1:
													output << "int ";
													break;
												case 2: 
													output << "float ";
													break;
												case 3: // bool
													output << "int ";
													break;
												default:
													output << "ERROR ";
													break;
												}
												output << symbol_table.symboltable[symbol_table.table_index][where].name  << "=" << (yyvsp[0].expr_result).content << endl;
											}
											else{
												output << "sipush " << (yyvsp[0].expr_result).content << endl;
		                        							output << "istore " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
											}
										}
										else{	
											//cout << $4 << " " << $6.type;
											yyerror("VARIABLE TYPE ERROR");
										}
									}
									else{
										yyerror("this id is already exist(var)");
									}
									hasValue = false;
									}
#line 2060 "yacc.tab.c"
    break;

  case 36:
#line 501 "yacc.y"
                                                        { 
							if(symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[-2].variable)) == 99999){
								symbol_node temp;
								temp.name = (yyvsp[-2].variable);
								temp.type = (yyvsp[0].typical_type);
								temp.Symbol_type = 3;
								symbol_table.insert(temp);
								int where = symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[-2].variable));
								if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
									output << "field static ";
									switch(symbol_table.symboltable[symbol_table.table_index][where].type){
									case 0:
										output << "java.lang.String ";
										break;
									case 1:
										output << "int ";
										break;
									case 2: 
										output << "float ";
										break;
									case 3: // bool 
										output << "int ";
										break;
									default:
										output << "ERROR ";
										break;
									}
									output << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
								}
							}
							else{
								yyerror("this id is already exist(var)");
							}
							}
#line 2099 "yacc.tab.c"
    break;

  case 37:
#line 537 "yacc.y"
                                                                                        { 
											if(symbol_table.scope_lookup(symbol_table.table_index ,(yyvsp[-8].variable)) == 99999){
												symbol_node temp;
												temp.name = (yyvsp[-8].variable);
												temp.type = (yyvsp[0].typical_type);
												temp.Symbol_type = 4;
												symbol_table.insert(temp);
												array_range tempp;
												tempp.array_name = (yyvsp[-8].variable);
												tempp.start = (yyvsp[-5].int_val);
												tempp.end = (yyvsp[-2].int_val);
												range.push_back(tempp);
											}
											else{
												yyerror("this id is already exist(array)");
											}
											}
#line 2121 "yacc.tab.c"
    break;

  case 45:
#line 567 "yacc.y"
              {symbol_table.create();}
#line 2127 "yacc.tab.c"
    break;

  case 46:
#line 567 "yacc.y"
                                                       {
						vector<vector<symbol_node> >::iterator it;
						it = symbol_table.symboltable.begin() + symbol_table.table_index;
						symbol_table.dump(symbol_table.table_index);
						symbol_table.symboltable.erase(it);
						}
#line 2138 "yacc.tab.c"
    break;

  case 48:
#line 588 "yacc.y"
                                        {
						int where = symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[-2].variable));
						if(where == 99999)	{
							where = symbol_table.scope_lookup(0, (yyvsp[-2].variable));
							if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
								output << "putstatic";
								switch(symbol_table.symboltable[symbol_table.table_index][where].type){
								    case 0:
									output << "java.lang.String ";
									break;
								    case 1:
									output << "int ";
									break;
								    case 2:
									output << "float ";
									break;
								    case 3: // bool
									output << "int ";
									break;
								    default:
									output << "ERROR ";
									break;
								}
								cout << "this is global variable" << endl;
								output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
							} 
						}
						else{
							cout << "this is local variable" << endl;
							output << "istore" << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
						}				
						}
#line 2175 "yacc.tab.c"
    break;

  case 49:
#line 620 "yacc.y"
                                                                {
								if(!symbol_table.ALL_lookup((yyvsp[-5].variable)).empty()){
									// keep doing
								}
								else{
									yyerror("Array didn't exist.");
								}
								}
#line 2188 "yacc.tab.c"
    break;

  case 50:
#line 628 "yacc.y"
              { output << "getstatic java.io.PrintStream java.lang.System.out" << endl;}
#line 2194 "yacc.tab.c"
    break;

  case 51:
#line 629 "yacc.y"
                      {
	  	output << "invokevirtual void java.io.PrintStream.println(";
			switch((yyvsp[0].expr_result).type){
		            case 0:
		                output << "java.lang.String ";
		                break;
		            case 1:
		                output << "int ";
		                break;
		            case 2: 
		                output << "float ";
		                break;
		            case 3: // bool
		                output << "int ";
		                break;
		            default:
		                output << "ERROR";
		                break;
		    }
                    output << ")" << endl;
                    }
#line 2220 "yacc.tab.c"
    break;

  case 53:
#line 651 "yacc.y"
                             { output << "ireturn" << endl;}
#line 2226 "yacc.tab.c"
    break;

  case 54:
#line 652 "yacc.y"
                 { output << "return" << endl;}
#line 2232 "yacc.tab.c"
    break;

  case 57:
#line 655 "yacc.y"
               { output << "getstatic java.io.PrintStream java.lang.System.out" <<endl;
		output << "invokevirtual void java.io.PrintStream.println()" << endl;}
#line 2239 "yacc.tab.c"
    break;

  case 58:
#line 659 "yacc.y"
                                        {(yyval.expr_result) = (yyvsp[0].expr_result);}
#line 2245 "yacc.tab.c"
    break;

  case 59:
#line 660 "yacc.y"
                                        {(yyval.expr_result) = (yyvsp[-1].expr_result);}
#line 2251 "yacc.tab.c"
    break;

  case 60:
#line 661 "yacc.y"
                                                                {
								expr_term temp;
								if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stoi((yyvsp[-2].expr_result).content) < stoi((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "iflt L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
									}
								}
								else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ // compare float or int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stof((yyvsp[-2].expr_result).content) < stof((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								(yyval.expr_result) = temp;
								}
#line 2294 "yacc.tab.c"
    break;

  case 61:
#line 699 "yacc.y"
                                                                {
								expr_term temp;
								if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stoi((yyvsp[-2].expr_result).content) <= stoi((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifle L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
									}
								}
								else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ //compare float or int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stof((yyvsp[-2].expr_result).content) <= stof((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								(yyval.expr_result) = temp;
								}
#line 2337 "yacc.tab.c"
    break;

  case 62:
#line 737 "yacc.y"
                                                                {
								expr_term temp;
								if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stoi((yyvsp[-2].expr_result).content) == stoi((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifeq L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
									}
								}
								else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ // compare float or int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stof((yyvsp[-2].expr_result).content) == stof((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else if((yyvsp[-2].expr_result).type == 3 && (yyvsp[0].expr_result).type == 3){ // compare boolean
									temp.type = 3;
									bool i1,i2;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if((yyvsp[-2].expr_result).content == "true"){
											i1 = true;
										}
										else{
											i1 = false;
										}
										if((yyvsp[0].expr_result).content == "true"){
											i2 = true;
										}
										else{
											i2 = false;
										}
										if(i1 == i2){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifeq L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
									}
								}
								else if((yyvsp[-2].expr_result).type == 0 && (yyvsp[0].expr_result).type == 0){ // compare string
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if((yyvsp[-2].expr_result).content == (yyvsp[0].expr_result).content){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								(yyval.expr_result) = temp;
								}
#line 2424 "yacc.tab.c"
    break;

  case 63:
#line 819 "yacc.y"
                                                                {
								expr_term temp;
								if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stoi((yyvsp[-2].expr_result).content) >= stoi((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifge L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
									}
								else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ //compare float or int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stof((yyvsp[-2].expr_result).content) >= stof((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								(yyval.expr_result) = temp;
								}
								}
#line 2467 "yacc.tab.c"
    break;

  case 64:
#line 857 "yacc.y"
                                                                {
								expr_term temp;
								if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stoi((yyvsp[-2].expr_result).content) > stoi((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifgt L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
									}
								}
								else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ //compare float or int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stof((yyvsp[-2].expr_result).content) > stof((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								(yyval.expr_result) = temp;
								}
#line 2510 "yacc.tab.c"
    break;

  case 65:
#line 895 "yacc.y"
                                                                {
								expr_term temp;
								if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stoi((yyvsp[-2].expr_result).content) != stoi((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifne L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
									}
								}
								else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ // compare float or int
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if(stof((yyvsp[-2].expr_result).content) != stof((yyvsp[0].expr_result).content)){
											temp.content = "true";
										}
										else{
											temp.content = "flase";
										}
									}
								}
								else if((yyvsp[-2].expr_result).type == 3 && (yyvsp[0].expr_result).type == 3){ // compare boolean
									temp.type = 3;
									bool i1,i2;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if((yyvsp[-2].expr_result).content == "true"){
											i1 = true;
										}
										else{
											i1 = false;
										}
										if((yyvsp[0].expr_result).content == "true"){
											i2 = true;
										}
										else{
											i2 = false;
										}
										if(i1 != i2){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
									int boolexpr_number = label.Boolexpr();
									if(!hasValue){
										output << "isub" << endl;
										output << "ifne L" << boolexpr_number << endl; // goto true
										output << "iconst_0" << endl; // false
										output << "goto L" << boolexpr_number << endl;// goto false
										output << "iconst_1" << endl; // true
										output << "exit Lexit" << ":" << endl;
									}
								}
								else if((yyvsp[-2].expr_result).type == 0 && (yyvsp[0].expr_result).type == 0){ // compare string
									temp.type = 3;
									if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
										if((yyvsp[-2].expr_result).content != (yyvsp[0].expr_result).content){
											temp.content = "true";
										}
										else{
											temp.content = "false";
										}
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								(yyval.expr_result) = temp;
								}
#line 2597 "yacc.tab.c"
    break;

  case 66:
#line 979 "yacc.y"
                                        {(yyval.expr_result) = (yyvsp[0].expr_result);}
#line 2603 "yacc.tab.c"
    break;

  case 67:
#line 980 "yacc.y"
                                                                        {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 3 && (yyvsp[0].expr_result).type == 3){
										temp.type = 3;
										bool i1, i2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if((yyvsp[-2].expr_result).content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if((yyvsp[0].expr_result).content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 || i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										if(!hasValue) {
											output << "ior" << endl;
										}
									}
									else{
										yyerror("Content type error");
									}
									(yyval.expr_result) =  temp;
									}
#line 2642 "yacc.tab.c"
    break;

  case 68:
#line 1014 "yacc.y"
                                                                        {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 3 && (yyvsp[0].expr_result).type == 3){
										temp.type = 3;
										bool i1, i2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if((yyvsp[-2].expr_result).content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if((yyvsp[0].expr_result).content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 && i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										if(!hasValue) {
											output << "iand" << endl;
										}
									}
									else{
										yyerror("Content type error");
									}
									(yyval.expr_result) =  temp;
									}
#line 2681 "yacc.tab.c"
    break;

  case 69:
#line 1048 "yacc.y"
                                                        {
							expr_term temp = (yyvsp[0].expr_result);
							if((yyvsp[0].expr_result).type == 3){
								temp.type = 3;
								if((yyvsp[0].expr_result).isNotVariable){
									if((yyvsp[0].expr_result).content == "true"){
										temp.content = "false";
									}		
									else{
										temp.content = "true";
									}
								}
							}
							else{
								yyerror("Content type error");
							}
							(yyval.expr_result) =  temp;
							}
#line 2704 "yacc.tab.c"
    break;

  case 70:
#line 1066 "yacc.y"
                                                                        {
									expr_term temp;
									cout << (yyvsp[-2].expr_result).type << " ... " << (yyvsp[0].expr_result).type << endl;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){
										temp.type = 1;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stoi((yyvsp[-2].expr_result).content) + stoi((yyvsp[0].expr_result).content));
										}
										if(!hasValue){
											output << "iadd" << endl;
										} 
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){
										temp.type = 2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stof((yyvsp[-2].expr_result).content) + stof((yyvsp[0].expr_result).content));
										}
									}
									else if((yyvsp[-2].expr_result).type == 0 && (yyvsp[0].expr_result).type == 0){
										temp.type = 0;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = (yyvsp[-2].expr_result).content + (yyvsp[0].expr_result).content;
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 2738 "yacc.tab.c"
    break;

  case 71:
#line 1095 "yacc.y"
                                                                        {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){
										temp.type = 1;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stoi((yyvsp[-2].expr_result).content) - stoi((yyvsp[0].expr_result).content));
										}
										if(!hasValue){
											output << "isub" << endl;
										} 	
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){
										temp.type = 2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stof((yyvsp[-2].expr_result).content) - stof((yyvsp[0].expr_result).content));
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 2765 "yacc.tab.c"
    break;

  case 72:
#line 1117 "yacc.y"
                                                                        {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){
										temp.type = 1;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stoi((yyvsp[-2].expr_result).content) * stoi((yyvsp[0].expr_result).content));
										}
										if(!hasValue) {
											output << "imul" << endl;
										}
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){
										temp.type = 2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stof((yyvsp[-2].expr_result).content) * stof((yyvsp[0].expr_result).content));
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 2792 "yacc.tab.c"
    break;

  case 73:
#line 1139 "yacc.y"
                                                                        {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){
										temp.type = 1;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stoi((yyvsp[-2].expr_result).content) / stoi((yyvsp[0].expr_result).content));
										}
										if(!hasValue){
											output << "idiv" << endl;
										} 
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){
										temp.type = 2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stof((yyvsp[-2].expr_result).content) / stof((yyvsp[0].expr_result).content));
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 2819 "yacc.tab.c"
    break;

  case 74:
#line 1161 "yacc.y"
                                                                        {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){
										temp.type = 1;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											temp.content = to_string(stoi((yyvsp[-2].expr_result).content) % stoi((yyvsp[0].expr_result).content));
										}
										if(!hasValue){
											output << "irem" << endl;
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 2840 "yacc.tab.c"
    break;

  case 75:
#line 1177 "yacc.y"
                                                                {
								expr_term temp;
								if((yyvsp[0].expr_result).type == 1){
									temp.type = 1;
									if((yyvsp[0].expr_result).isNotVariable){
										temp.content = to_string(stoi((yyvsp[0].expr_result).content) * (-1));
									}
									if(!hasValue){
										output << "ineg" << endl;
									} 
								}
								else if((yyvsp[0].expr_result).type == 2){
									temp.type = 2;
									if((yyvsp[0].expr_result).isNotVariable){
										temp.content = to_string(stof((yyvsp[0].expr_result).content) * (-1));
									}
								}
								else{
									yyerror("Content type didn't match");
								}
								(yyval.expr_result) = temp;
								}
#line 2867 "yacc.tab.c"
    break;

  case 76:
#line 1201 "yacc.y"
                                                        {
									vector<int> where;
									for(int i = 0;i < symbol_table.argument_place.size();i++){
										for(int j = 0;j < symbol_table.symboltable[i].size();j++){
											if(!symbol_table.ALL_lookup((yyvsp[-3].variable)).empty()){
												where = symbol_table.ALL_lookup((yyvsp[-3].variable));
												break;
											}
											else{
											
											}
										}
									}
									if(where.empty()){
										yyerror("Identifier not found");
									}
									else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 0){
										yyerror("Is not function name");
									}
									else{
										bool Same = true;
		       							if(symbol_table.symboltable[where[0]][where[1]].argument_type.size() == (yyvsp[-1].argument_list).size()){
		                							for(int i = 0;i < (yyvsp[-1].argument_list).size();i++){
		                    								if(symbol_table.symboltable[where[0]][where[1]].argument_type[i] != (yyvsp[-1].argument_list)[i]){
		                    	    								Same=false;
		                        								break;
		                    								}
		                							}
		            							}
		            							else{
		                							Same=false;
		            							}
		            							if(Same){
		                							expr_term temp;
		                							temp.type = symbol_table.symboltable[where[0]][where[1]].type;
		                							temp.isNotVariable = false;
		               							(yyval.expr_result) = temp;
		            							}
		            							else{
		                							yyerror("argument type didn't match");
		            							}
									}									
									}
#line 2915 "yacc.tab.c"
    break;

  case 77:
#line 1244 "yacc.y"
                                                        {
								vector<int> where;
								for(int i = 0;i < symbol_table.argument_place.size();i++){
									for(int j = 0;j < symbol_table.symboltable[i].size();j++){
										if(!symbol_table.ALL_lookup((yyvsp[-2].variable)).empty()){
											where = symbol_table.ALL_lookup((yyvsp[-2].variable));
											break;
										}
										else{
											
										}
									}
								}
								if(where.empty()){ 
		         				   		yyerror("Identifier not found");
		        					}
		        					else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 0){ 
		            						yyerror("Is not function name");
		        					}
		        					else{
		            						if(symbol_table.symboltable[where[0]][where[1]].argument_type.size() == 0){
		                						expr_term temp;
		                						temp.type = symbol_table.symboltable[where[0]][where[1]].type;
		                						temp.isNotVariable = false;
		                						(yyval.expr_result) = temp;
		            						}
		            						else{
		                						yyerror("The function had some arguemts");
		            						}
		        					}
								}
#line 2951 "yacc.tab.c"
    break;

  case 78:
#line 1277 "yacc.y"
                                                { // function invocation with argument
								vector<int> where;
								for(int i = 0;i < symbol_table.symboltable.size();i++){
									for(int j = 0;j < symbol_table.symboltable[i].size();j++){
										//cout << symbol_table.symboltable[i][j].name << endl;
										//cout << $1 << endl;
										if(!symbol_table.ALL_lookup((yyvsp[-3].variable)).empty()){
											where = symbol_table.ALL_lookup((yyvsp[-3].variable));
											break;
										}
										else{
											
										}
									}
								}
								if(where.empty()){
									yyerror("Identifier not found");
								}
								else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 0){
									//cout << symbol_table.symboltable[temp_index][where].name << endl;
									yyerror("Is not function name");
								}
								else{
									bool Same = true;
									cout << symbol_table.symboltable[where[0]][where[1]].argument_type.size() << " ||||| " << (yyvsp[-1].argument_list).size() << endl;
               							if(symbol_table.symboltable[where[0]][where[1]].argument_type.size() == (yyvsp[-1].argument_list).size()){
                        							for(int i = 0;i < (yyvsp[-1].argument_list).size();i++){
                            								if(symbol_table.symboltable[where[0]][where[1]].argument_type[i] != (yyvsp[-1].argument_list)[i]){
                            	    								Same=false;
                                								break;
                            								}
                        							}
                    							}
                    							else{	
                    								
                        							Same=false;
                    							}
                    							if(Same){
                        							expr_term temp;
                        							temp.type = symbol_table.symboltable[where[0]][where[1]].type;
                        							temp.isNotVariable = false;
                       							(yyval.expr_result) = temp;
                       							output << "invokestatic ";
										switch(symbol_table.symboltable[where[0]][where[1]].type){
											case 0:
											    output << "java.lang.String ";
											    break;
											case 1:
											    output << "int ";
											    break;
											case 2: 
											    output << "float ";
											    break;
											case 3: // bool
											    output << "int ";
											    break;
											default:
											    output << "ERROR ";
											    break;
										    }
										output << className << "." << symbol_table.symboltable[where[0]][where[1]].name;
										output << "(";
										vector<int> arg = symbol_table.symboltable[where[0]][where[1]].argument_type;
										
										for(int i=0;i<arg.size();i++){
										    switch(arg[i]){
											case 0:
											    output << "java.lang.String ";
											    break;
											case 1:
											    output << "int";
											    break;
											case 2: 
											    output << "float";
											    break;
											case 3: // bool
											    output << "int ";
											    break;
											default:
											    output << "ERROR";
											    break;
										    }
										    if(i!=arg.size() - 1){
											output<<", ";
										    }
										}
										output << ")" << endl;
                    							}
                    							else{
                        							yyerror("argument didn't match");
                    							}
								}
								}
#line 3049 "yacc.tab.c"
    break;

  case 79:
#line 1370 "yacc.y"
                                                { // function invocation
							vector<int> where;
							for(int i = 0;i < symbol_table.argument_place.size();i++){
								for(int j = 0;j < symbol_table.symboltable[i].size();j++){
									if(!symbol_table.ALL_lookup((yyvsp[-2].variable)).empty()){
										where = symbol_table.ALL_lookup((yyvsp[-2].variable));
										break;
									}
									else{
										
									}
								}
							}
							if(where.empty()){ 
                 				   		yyerror("Identifier not found");
                					}
                					else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 0){ 
                    						yyerror("Is not function name");
                					}
                					else{
                    						if(symbol_table.symboltable[where[0]][where[1]].argument_type.size() == 0){
                        						expr_term temp;
                        						temp.type = symbol_table.symboltable[where[0]][where[1]].type;
                        						temp.isNotVariable = false;
                        						(yyval.expr_result) = temp;
                    						}
                    						else{
                        						yyerror("The function had some arguemts");
                    						}
                					}
							}
#line 3085 "yacc.tab.c"
    break;

  case 80:
#line 1401 "yacc.y"
                                                        { // array
								vector<int> where;
								int index;
								for(int i = 0;i < symbol_table.symboltable.size();i++){
									for(int j = 0;j < symbol_table.symboltable[i].size();j++){
										if(!symbol_table.ALL_lookup((yyvsp[-3].variable)).empty()){
											where = symbol_table.ALL_lookup((yyvsp[-3].variable));
											break;
										}
										else{
											
										}
									}
								}
								if(where.empty()){
									yyerror("Identifier not found");
								}
								else if(symbol_table.symboltable[where[0]][where[1]].Symbol_type != 4){
									yyerror("Is not an arrry");
								}
								else{	
									for(int i = 0;i < range.size();i++){
										if(range[i].array_name == (yyvsp[-3].variable)){
											index = i;
											break;
										}
									}	
									if((yyvsp[-1].expr_result).isNotVariable){ 
                								if((yyvsp[-1].expr_result).type == 1){
                									if((stoi((yyvsp[-1].expr_result).content) < range[index].start) || (stoi((yyvsp[-1].expr_result).content) > range[index].end)){
                												yyerror("index out of array range");									
                									}
                									else{
		        									expr_term temp;
		            									temp.type = symbol_table.symboltable[where[0]][where[1]].type;
		            									temp.isNotVariable = false;
		            									(yyval.expr_result) = temp;
                									}
                								}
                								else{
                    									yyerror("Index need to be int");
                								}
            								}
            								else{ 
                								yyerror("Index can't not be variable");
            								}
								}
								}
#line 3138 "yacc.tab.c"
    break;

  case 81:
#line 1449 "yacc.y"
                                                {(yyval.expr_result) = (yyvsp[-1].expr_result);}
#line 3144 "yacc.tab.c"
    break;

  case 82:
#line 1450 "yacc.y"
                                { 
				expr_term temp;
				temp.type = 0;
				temp.isNotVariable = true;
				temp.content = (yyvsp[0].str_val);
				if(!hasValue){
					output << "ldc \"" << (yyvsp[0].str_val) << "\"" << endl;
				}            
				(yyval.expr_result) = temp;
				}
#line 3159 "yacc.tab.c"
    break;

  case 83:
#line 1460 "yacc.y"
                                {
				expr_term temp;
				temp.type = 1;
				temp.isNotVariable = true;
				temp.content = to_string((yyvsp[0].int_val));
				if(!hasValue){
					output << "sipush " << (yyvsp[0].int_val) << endl;
				}
				(yyval.expr_result) = temp;
				}
#line 3174 "yacc.tab.c"
    break;

  case 84:
#line 1470 "yacc.y"
                        {
				expr_term temp;
				temp.type = 2;
				temp.isNotVariable = true;
				temp.content = to_string((yyvsp[0].float_val));
				(yyval.expr_result) = temp;
				}
#line 3186 "yacc.tab.c"
    break;

  case 85:
#line 1477 "yacc.y"
                                {
				expr_term temp;
				temp.type = 3;
				temp.isNotVariable = true;
				if((yyvsp[0].bool_val) == true){
					temp.content = "true";
				}
				else{
					temp.content = "false";
				}
				string b;
				if(!hasValue){
					if((yyvsp[0].bool_val)){
						b = "1";
						output << "const_" << b << endl;
					}
					else{
						b = "0";
						output << "const_" << b << endl;
					}
				}
				(yyval.expr_result) = temp;
				}
#line 3214 "yacc.tab.c"
    break;

  case 86:
#line 1500 "yacc.y"
                                {
				expr_term temp;
				int where = symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[0].variable));
				if(where == 99999){
					if(symbol_table.scope_lookup(0, (yyvsp[0].variable)) != 99999){
						where = symbol_table.scope_lookup(0, (yyvsp[0].variable));
						temp.type = symbol_table.symboltable[0][where].type;
						if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
							temp.isNotVariable = false;
							if(!hasValue){
							    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
								    output << "getstatic ";
								    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
								    case 0:
									output << "java.lang.String ";
									break;
								    case 1:
									output << "int ";
									break;
								    case 2: 
									output << "float ";
									break;
								    case 3: // bool
									output << "int ";
									break;
								    default:
									output << "ERROR ";
									break;
								    }
							    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
							    }
							    else{
								output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
							    }
							}
						}
						else{
							temp.isNotVariable = true;
							temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
							if(temp.type == 1){
							   	if(!hasValue){
							    		output << "sipush " << temp.content << endl;
							   	}
							}
							else if(temp.type == 3){
							    	if(temp.content == "true"){
									if(!hasValue){
										output << "iconst_1" << endl;
									} 
							   	 }
								 else{
									if(!hasValue){
										output << "iconst_0" << endl;
									}
							   	 }
							}
							else if(temp.type == 0){
							 	if(!hasValue){
								    	output << "ldc \"" << temp.content << "\"" << endl;
							  	} 
							}
						}
					}
				}
				else{
					temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
					if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
						temp.isNotVariable = false;
						if(!hasValue){
						    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
							    output << "getstatic ";
							    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
							    case 0:
								output << "java.lang.String ";
								break;
							    case 1:
								output << "int ";
								break;
							    case 2: 
								output << "float ";
								break;
							    case 3: // bool
								output << "int ";
								break;
							    default:
								output << "ERROR ";
								break;
							    }
						    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
						    }
						    else{
							output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
						    }
						}
					}
					else{
						temp.isNotVariable = true;
						temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
						if(temp.type == 1){
						   	if(!hasValue){
						    		output << "sipush " << temp.content << endl;
						   	}
						}
						else if(temp.type == 3){
						    	if(temp.content == "true"){
								if(!hasValue){
									output << "iconst_1" << endl;
								} 
						   	 }
							 else{
								if(!hasValue){
									output << "iconst_0" << endl;
								}
						   	 }
						}
						else if(temp.type == 0){
						 	if(!hasValue){
							    	output << "ldc \"" << temp.content << "\"" << endl;
						  	} 
						}
					}
				}
				
				(yyval.expr_result) = temp;
				}
#line 3344 "yacc.tab.c"
    break;

  case 87:
#line 1627 "yacc.y"
                                {
					vector<int> temp;
					temp.push_back((yyvsp[0].expr_result).type);
					cout << (yyvsp[0].expr_result).type << endl;
					(yyval.argument_list) = temp;
					}
#line 3355 "yacc.tab.c"
    break;

  case 88:
#line 1633 "yacc.y"
                                                        {
									vector<int> temp;
									temp = (yyvsp[0].argument_list);
									temp.push_back((yyvsp[-2].expr_result).type);
									/*for(int i = 0;i < temp.size();i++){
										cout << temp[i] << " ";
									}
									cout << endl;*/
									(yyval.argument_list) = temp;
									}
#line 3370 "yacc.tab.c"
    break;

  case 89:
#line 1645 "yacc.y"
                                             {symbol_table.create();output << "ifeq L" << label.If() << endl;}
#line 3376 "yacc.tab.c"
    break;

  case 90:
#line 1645 "yacc.y"
                                                                                                                                                                                                {
								output << "goto Lexit" << label.If() << endl;
								output << "Lfalse" << label.If() << ":"<<endl; 
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);}
#line 3388 "yacc.tab.c"
    break;

  case 91:
#line 1652 "yacc.y"
                                                                     {symbol_table.create();}
#line 3394 "yacc.tab.c"
    break;

  case 92:
#line 1654 "yacc.y"
                                                                { 
								output << "Lexit" << label.If() << ":" <<endl;
                                                              label.If_add();
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								//cout << "number:::::: "<<symbol_table.table_index << endl;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);
								}
#line 3408 "yacc.tab.c"
    break;

  case 93:
#line 1663 "yacc.y"
                                            {symbol_table.create();output << "ifeq L" << label.If() << endl;}
#line 3414 "yacc.tab.c"
    break;

  case 94:
#line 1663 "yacc.y"
                                                                                                                          {output << "goto Lexit" << label.If() << endl;}
#line 3420 "yacc.tab.c"
    break;

  case 95:
#line 1664 "yacc.y"
                                                                                                       {
												output << "Lexit" << label.If() << ":" <<endl;
                                                              				label.If_add();
												vector<vector<symbol_node> >::iterator it;
												it = symbol_table.symboltable.begin() + symbol_table.table_index;
												symbol_table.dump(symbol_table.table_index);
												symbol_table.symboltable.erase(it);
												}
#line 3433 "yacc.tab.c"
    break;

  case 96:
#line 1674 "yacc.y"
                                                   {(yyval.expr_result) = (yyvsp[-1].expr_result);}
#line 3439 "yacc.tab.c"
    break;

  case 97:
#line 1675 "yacc.y"
                                                                   {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stoi((yyvsp[-2].expr_result).content) < stoi((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "iflt L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
										}							
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ // compare float or int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stof((yyvsp[-2].expr_result).content) < stof((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 3482 "yacc.tab.c"
    break;

  case 98:
#line 1713 "yacc.y"
                                                                    {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stoi((yyvsp[-2].expr_result).content) <= stoi((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifle L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
										}
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ //compare float or int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stof((yyvsp[-2].expr_result).content) <= stof((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 3525 "yacc.tab.c"
    break;

  case 99:
#line 1751 "yacc.y"
                                                                   {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stoi((yyvsp[-2].expr_result).content) == stoi((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifeq L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
										}
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ // compare float or int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stof((yyvsp[-2].expr_result).content) == stof((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else if((yyvsp[-2].expr_result).type == 3 && (yyvsp[0].expr_result).type == 3){ // compare boolean
										temp.type = 3;
										bool i1,i2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if((yyvsp[-2].expr_result).content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if((yyvsp[0].expr_result).content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 == i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifeq L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
										}
									}
									else if((yyvsp[-2].expr_result).type == 0 && (yyvsp[0].expr_result).type == 0){ // compare string
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if((yyvsp[-2].expr_result).content == (yyvsp[0].expr_result).content){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 3612 "yacc.tab.c"
    break;

  case 100:
#line 1833 "yacc.y"
                                                                     {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stoi((yyvsp[-2].expr_result).content) >= stoi((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifge L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
										}
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ //compare float or int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stof((yyvsp[-2].expr_result).content) >= stof((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 3655 "yacc.tab.c"
    break;

  case 101:
#line 1871 "yacc.y"
                                                                   {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stoi((yyvsp[-2].expr_result).content) > stoi((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifgt L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
										}
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ //compare float or int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stof((yyvsp[-2].expr_result).content) > stof((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;						
									}
#line 3698 "yacc.tab.c"
    break;

  case 102:
#line 1909 "yacc.y"
                                                                    {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){ // compare int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stoi((yyvsp[-2].expr_result).content) != stoi((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifne L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
										}
									}
									else if(((yyvsp[-2].expr_result).type == 1 || (yyvsp[-2].expr_result).type == 2) && ((yyvsp[0].expr_result).type == 1 || (yyvsp[0].expr_result).type == 2)){ // compare float or int
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if(stof((yyvsp[-2].expr_result).content) != stof((yyvsp[0].expr_result).content)){
												temp.content = "true";
											}
											else{
												temp.content = "flase";
											}
										}
									}
									else if((yyvsp[-2].expr_result).type == 3 && (yyvsp[0].expr_result).type == 3){ // compare boolean
										temp.type = 3;
										bool i1,i2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if((yyvsp[-2].expr_result).content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if((yyvsp[0].expr_result).content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 != i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										int boolexpr_number = label.Boolexpr();
										if(!hasValue){
											output << "isub" << endl;
											output << "ifne L" << boolexpr_number << endl; // goto true
											output << "iconst_0" << endl; // false
											output << "goto L" << boolexpr_number << endl;// goto false
											output << "iconst_1" << endl; // true
											output << "exit Lexit" << ":" << endl;
										}
									}
									else if((yyvsp[-2].expr_result).type == 0 && (yyvsp[0].expr_result).type == 0){ // compare string
										temp.type = 3;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if((yyvsp[-2].expr_result).content != (yyvsp[0].expr_result).content){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
									}
									else{
										yyerror("Content type didn't match");
									}
									(yyval.expr_result) = temp;
									}
#line 3785 "yacc.tab.c"
    break;

  case 103:
#line 1991 "yacc.y"
                                                                   {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 3 && (yyvsp[0].expr_result).type == 3){
										temp.type = 3;
										bool i1, i2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if((yyvsp[-2].expr_result).content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if((yyvsp[0].expr_result).content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 || i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										if(!hasValue) {
											output << "ior" << endl;
										}
									}
									else{
										yyerror("Boolean expression wrong type");
									}
									(yyval.expr_result) =  temp;
									}
#line 3824 "yacc.tab.c"
    break;

  case 104:
#line 2025 "yacc.y"
                                                                    {
									expr_term temp;
									if((yyvsp[-2].expr_result).type == 3 && (yyvsp[0].expr_result).type == 3){
										temp.type = 3;
										bool i1, i2;
										if((yyvsp[-2].expr_result).isNotVariable && (yyvsp[0].expr_result).isNotVariable){
											if((yyvsp[-2].expr_result).content == "true"){
												i1 = true;
											}
											else{
												i1 = false;
											}
											if((yyvsp[0].expr_result).content == "true"){
												i2 = true;
											}
											else{
												i2 = false;
											}
											if(i1 && i2){
												temp.content = "true";
											}
											else{
												temp.content = "false";
											}
										}
										if(!hasValue) {
											output << "iand" << endl;
										}
										
									}
									else{
										yyerror("Boolean expression wrong type");
									}
									(yyval.expr_result) =  temp;
									}
#line 3864 "yacc.tab.c"
    break;

  case 105:
#line 2060 "yacc.y"
                                                 {
							expr_term temp = (yyvsp[0].expr_result);
							if((yyvsp[0].expr_result).type == 3){
								temp.type = 3;
								if((yyvsp[0].expr_result).isNotVariable){
									if((yyvsp[0].expr_result).content == "true"){
										temp.content = "false";
									}		
									else{
										temp.content = "true";
									}
								}
							}
							else{
								yyerror("Boolean expression wrong type");
							}
							(yyval.expr_result) =  temp;
							}
#line 3887 "yacc.tab.c"
    break;

  case 106:
#line 2078 "yacc.y"
                                     {
					expr_term temp;
					int where = symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[0].variable));
					if(where == 99999){
						if(symbol_table.scope_lookup(0, (yyvsp[0].variable)) != 99999){
							where = symbol_table.scope_lookup(0, (yyvsp[0].variable));
							temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
							if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
								temp.isNotVariable = false;
								if(!hasValue){
								    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
									    output << "getstatic ";
									    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
									    case 0:
										output << "java.lang.String ";
										break;
									    case 1:
										output << "int ";
										break;
									    case 2: 
										output << "float ";
										break;
									    case 3: // bool
										output << "int ";
										break;
									    default:
										output << "ERROR ";
										break;
									    }
								    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
								    }
								    else{
									output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
								    }
								}
							}
							else{
								temp.isNotVariable = true;
								temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
								if(temp.type == 1){
								   	if(!hasValue){
								    		output << "sipush " << temp.content << endl;
								   	}
								}
								else if(temp.type == 3){
								    	if(temp.content == "true"){
										if(!hasValue){
											output << "iconst_1" << endl;
										} 
								   	 }
									 else{
										if(!hasValue){
											output << "iconst_0" << endl;
										}
								   	 }
								}
								else if(temp.type == 0){
								 	if(!hasValue){
									    	output << "ldc \"" << temp.content << "\"" << endl;
								  	} 
								}
							}
						}
					}
					else{
						temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
						if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
							temp.isNotVariable = false;
							if(!hasValue){
							    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
								    output << "getstatic ";
								    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
								    case 0:
									output << "java.lang.String ";
									break;
								    case 1:
									output << "int ";
									break;
								    case 2: 
									output << "float ";
									break;
								    case 3: // bool
									output << "int ";
									break;
								    default:
									output << "ERROR ";
									break;
								    }
							    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
							    }
							    else{
								output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
							    }
							}
						}
						else{
							temp.isNotVariable = true;
							temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
							if(temp.type == 1){
							   	if(!hasValue){
							    		output << "sipush " << temp.content << endl;
							   	}
							}
							else if(temp.type == 3){
							    	if(temp.content == "true"){
									if(!hasValue){
										output << "iconst_1" << endl;
									} 
							   	 }
								 else{
									if(!hasValue){
										output << "iconst_0" << endl;
									}
							   	 }
							}
							else if(temp.type == 0){
							 	if(!hasValue){
								    	output << "ldc \"" << temp.content << "\"" << endl;
							  	} 
							}
						}
					}
					(yyval.expr_result) = temp;
					}
#line 4016 "yacc.tab.c"
    break;

  case 107:
#line 2202 "yacc.y"
                                  {
					expr_term temp;
					temp.type = 3;
					temp.isNotVariable = true;
					if((yyvsp[0].bool_val) == true){
						temp.content = "true";
					}
					else{
						temp.content = "false";
					}
					if(!hasValue){
						output << "const_" << ((yyvsp[0].bool_val) ? "1" : "0") << endl;
					}
					(yyval.expr_result) = temp;
					}
#line 4036 "yacc.tab.c"
    break;

  case 112:
#line 2225 "yacc.y"
                {symbol_table.create(); output << "Lbegin" << label.Loop() << ":" << endl;}
#line 4042 "yacc.tab.c"
    break;

  case 113:
#line 2226 "yacc.y"
                                                                                {
								output << "goto Lbegin" << label.Loop() << ":" << endl;
								output << "Lexit" << label.Loop() << ":" << endl;
								label.Loop_add();
								vector<vector<symbol_node> >::iterator it;
								it = symbol_table.symboltable.begin() + symbol_table.table_index;
								symbol_table.dump(symbol_table.table_index);
								symbol_table.symboltable.erase(it);
								}
#line 4056 "yacc.tab.c"
    break;

  case 114:
#line 2235 "yacc.y"
                                                                                    {
							if(atoi((yyvsp[-3].expr_result).content.c_str()) < atoi((yyvsp[0].expr_result).content.c_str())){
								yyerror("For loop scope need to be decreasing sequence");
							}
							else{
								/*vector<int> where;
								for(int i = 0;i < symbol_table.argument_place.size();i++){
									for(int j = 0;j < symbol_table.symboltable[i].size();j++){
										if(!symbol_table.ALL_lookup($4).empty()){
											where = symbol_table.ALL_lookup($4);
											break;
										}
										else{
											
										}
									}
								}*/
								symbol_table.create();
								output << "Lbegin" << label.Loop() << ":" << endl;
								if((yyvsp[-3].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){
									symbol_node temp;
									temp.name = (yyvsp[-5].variable);
									temp.type = 1;
									temp.Symbol_type = 3;
									symbol_table.insert(temp);
								}
								else{
									yyerror("range type must be integer");
								}
								
							}
							}
#line 4093 "yacc.tab.c"
    break;

  case 115:
#line 2266 "yacc.y"
                                                                                {
										output << "goto Lbegin" << label.Loop() << ":" << endl;
										output << "Lexit" << label.Loop() << ":" << endl;
										vector<vector<symbol_node> >::iterator it;
										it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										symbol_table.symboltable.erase(it);
										}
#line 4106 "yacc.tab.c"
    break;

  case 116:
#line 2274 "yacc.y"
                                                                        {
							if((yyvsp[-3].expr_result).type == 1 && (yyvsp[0].expr_result).type == 1){
								//cout << $5.content << " ............. " << $8.content;
								if(atoi((yyvsp[-3].expr_result).content.c_str()) < atoi((yyvsp[0].expr_result).content.c_str())){
									//cout << $5.content << " ............. " << $8.content;
									symbol_table.create();
									output << "Lbegin" << label.Loop() << ":" << endl;
									symbol_node temp;
									temp.name = (yyvsp[-5].variable);
									temp.type = 1;
									temp.Symbol_type = 3;
									symbol_table.insert(temp);
								}
								else{
									yyerror("range cannot be decreasing");
								}
							}
							else{
								yyerror("range type must be integer");
							}
							}
#line 4132 "yacc.tab.c"
    break;

  case 117:
#line 2294 "yacc.y"
                                                                              {
										output << "goto Lbegin" << label.Loop() << ":" << endl;
										output << "Lexit" << label.Loop() << ":" << endl;
										vector<vector<symbol_node> >::iterator it;
										it = symbol_table.symboltable.begin() + symbol_table.table_index;
										symbol_table.dump(symbol_table.table_index);
										symbol_table.symboltable.erase(it);
										}
#line 4145 "yacc.tab.c"
    break;

  case 118:
#line 2304 "yacc.y"
                                        {
					expr_term temp;
					temp.type = 0;
					temp.isNotVariable = true;
					temp.content = (yyvsp[0].str_val);
					if(!hasValue){
						output << "ldc \"" << (yyvsp[0].str_val) << "\"" << endl;
					} 
					(yyval.expr_result) = temp;
					}
#line 4160 "yacc.tab.c"
    break;

  case 119:
#line 2314 "yacc.y"
                                        {
					expr_term temp;
					temp.type = 1;
					temp.isNotVariable = true;
					temp.content = to_string((yyvsp[0].int_val));
					if(!hasValue){
						output << "sipush " << (yyvsp[0].int_val) << endl;
					}
					(yyval.expr_result) = temp;
					}
#line 4175 "yacc.tab.c"
    break;

  case 120:
#line 2324 "yacc.y"
                                {
					expr_term temp;
					temp.type = 2;
					temp.isNotVariable = true;
					temp.content = to_string((yyvsp[0].float_val));
					(yyval.expr_result) = temp;
					}
#line 4187 "yacc.tab.c"
    break;

  case 121:
#line 2331 "yacc.y"
                                        {
					expr_term temp;
					temp.type = 3;
					temp.isNotVariable = true;
					if((yyvsp[0].bool_val) == true){
						temp.content = "true";
					}
					else{
						temp.content = "false";
					}
					string b;
					if(!hasValue){
						if((yyvsp[0].bool_val)){
							b = "1";
							output << "const_" << b << endl;
						}
						else{
							b = "0";
							output << "const_" << b << endl;
						}
					}
					(yyval.expr_result) = temp;
					}
#line 4215 "yacc.tab.c"
    break;

  case 122:
#line 2354 "yacc.y"
                                        {
					expr_term temp;
					int where = symbol_table.scope_lookup(symbol_table.table_index, (yyvsp[0].variable));
					if(where == 99999){
						if(symbol_table.scope_lookup(0, (yyvsp[0].variable)) != 99999){
							where = symbol_table.scope_lookup(0, (yyvsp[0].variable));
							temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
							if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
								temp.isNotVariable = false;
								if(!hasValue){
								    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
									    output << "getstatic ";
									    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
									    case 0:
										output << "java.lang.String ";
										break;
									    case 1:
										output << "int ";
										break;
									    case 2: 
										output << "float ";
										break;
									    case 3: // bool
										output << "int ";
										break;
									    default:
										output << "ERROR ";
										break;
									    }
								    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
								    }
								    else{
									output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
								    }
								}
							}
							else{
								temp.isNotVariable = true;
								temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
								if(temp.type == 1){
								   	if(!hasValue){
								    		output << "sipush " << temp.content << endl;
								   	}
								}
								else if(temp.type == 3){
								    	if(temp.content == "true"){
										if(!hasValue){
											output << "iconst_1" << endl;
										} 
								   	 }
									 else{
										if(!hasValue){
											output << "iconst_0" << endl;
										}
								   	 }
								}
								else if(temp.type == 0){
								 	if(!hasValue){
									    	output << "ldc \"" << temp.content << "\"" << endl;
								  	} 
								}
							}
						}
					}
					else{
						temp.type = symbol_table.symboltable[symbol_table.table_index][where].type;
						if(symbol_table.symboltable[symbol_table.table_index][where].Symbol_type == 3){
							temp.isNotVariable = false;
							if(!hasValue){
							    if(symbol_table.symboltable[symbol_table.table_index][where].var_index == -1){
								    output << "getstatic ";
								    switch(symbol_table.symboltable[symbol_table.table_index][where].type){
								    case 0:
									output << "java.lang.String ";
									break;
								    case 1:
									output << "int ";
									break;
								    case 2: 
									output << "float ";
									break;
								    case 3: // bool
									output << "int ";
									break;
								    default:
									output << "ERROR ";
									break;
								    }
							    output << className << "." << symbol_table.symboltable[symbol_table.table_index][where].name << endl;
							    }
							    else{
								output << "iload " << symbol_table.symboltable[symbol_table.table_index][where].var_index << endl;
							    }
							}
						}
						else{
							temp.isNotVariable = true;
							temp.content = symbol_table.symboltable[symbol_table.table_index][where].content;
							if(temp.type == 1){
							   	if(!hasValue){
							    		output << "sipush " << temp.content << endl;
							   	}
							}
							else if(temp.type == 3){
							    	if(temp.content == "true"){
									if(!hasValue){
										output << "iconst_1" << endl;
									} 
							   	 }
								 else{
									if(!hasValue){
										output << "iconst_0" << endl;
									}
							   	 }
							}
							else if(temp.type == 0){
							 	if(!hasValue){
								    	output << "ldc \"" << temp.content << "\"" << endl;
							  	} 
							}
						}
					}
					(yyval.expr_result) = temp;
					}
#line 4344 "yacc.tab.c"
    break;


#line 4348 "yacc.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 2479 "yacc.y"

void yyerror(string s){
    cout<< "Line number: " << linenum << endl;
    fprintf(stderr, "%s\n", s.c_str());
    error++;
    //exit(0);
}

int main( int argc, char **argv ){
	symbol_table.create();
	FILE* input;
	extern FILE* yyin;
	++argv, --argc;
	//--- File input ---//
	if ( argc > 0 ){
		input = fopen(argv[0],"r");
		
        	if(input==NULL){
          		printf("cannot open file\n");
            		return -1;
		}
		yyin = input;
		if(argc>1){
			output.open(argv[1], ios::out | ios::trunc);
        	}
        	else{
            		output.open("output.jasm", ios::out | ios::trunc);
        	}
	}
	//--- Stdin ---//
	else{
		//cout << "!!!!!!!fsdgragre" << endl;
	}
    	yyparse();
  
    	if ( argc > 0 ){
        	fclose(input);
    	}
    	output.close();
	return 0;
}
