/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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

#ifndef YY_YY_AUTOGEN_PARSER_H_INCLUDED
# define YY_YY_AUTOGEN_PARSER_H_INCLUDED
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
/* Line 2058 of yacc.c  */
#line 15 "src/parser.y"

    int d;
	char c;
    char *str;
	struct astnode *node;
	struct tlink *link;


/* Line 2058 of yacc.c  */
#line 136 "autogen/parser.h"
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

#endif /* !YY_YY_AUTOGEN_PARSER_H_INCLUDED  */
