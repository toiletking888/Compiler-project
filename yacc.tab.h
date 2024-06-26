/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
