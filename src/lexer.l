

%{

    #include <stdio.h>
    #include "parser.h"

    void yyerror(char *str);
    char *istrndup(char *str,size_t len);


%}

/* Sections from http://www.quut.com/c/ANSI-C-grammar-l-2011.html */
O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%option noyywrap


%%
"char"		{return CHAR;}
"short"		{return SHORT;}
"int"		{return INT;}
"long"		{return LONG;}
"float"		{return FLOAT;}
"double"	{return DOUBLE;}
"_Bool"		{return BOOL;}
"void"		{return VOID;}
"struct"	{return STRUCT;}
"typedef"	{return TYPEDEF;}
"union"		{return UNION;}

"unsigned"	{return UNSIGNED;}
"signed"	{return SIGNED;}
"static"	{return STATIC;}
"auto"		{return AUTO;}
"volatile"	{return VOLATILE;}
"_Atomic"	{return ATOMIC;}
"extern"	{return EXTERN;}
"const"		{return CONST;}
"restrict"	{return RESTRICT;}
"register"	{return REGISTER;}

"if"		{return IF;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"do"		{return DO;}
"for"		{return FOR;}
"switch"	{return SWITCH;}
"case"		{return CASE;}
"default"	{return DEFAULT;}

"goto"		{return GOTO;}
"break"		{return BREAK;}
"contineu"	{return CONTINUE;}
"return"	{return RETURN;}

"sizeof"	{return SIZEOF;}

{HP}{H}+{IS}?					|
{NZ}{D}*{IS}?					|
"0"{O}*{IS}?					|
{CP}?"'"([^'\\\n]|{ES})+"'"     {yylval.str=istrndup(yytext,16);return ICONSTANT;}

{D}+{E}{FS}?				|
{D}*"."{D}+{E}?{FS}?		|
{D}+"."{E}?{FS}?			|
{HP}{H}+{P}{FS}?			|
{HP}{H}*"."{H}+{P}{FS}?		|
{HP}{H}+"."{P}{FS}?			{yylval.str=istrndup(yytext,32);return FCONSTANT;}

[_a-zA-Z][_a-zA-Z0-9]*  {yylval.str=istrndup(yytext,32);return ID;}

\"(\\.|[^\\"\n])*\"		{yylval.str=istrndup(yytext,128);return STRING;}

"?"			|
":"			|
","			|
"."
"["			|
"]"			|
"="			|
"("         |
")"         |
"~"			|
"!"			|
"+"         |
"-"         |
"*"         |
"/"         |
"%"			|
">"			|
"<"			|
"&"			|
"|"			|
"^"			|
";"         |
"{"         |
"}"         {return yytext[0];}

"&&"		{return LAND;}
"||"		{return LOR;}
"=="		{return EQ;}
"!="		{return NE;}
">="		{return GE;}
"<="		{return LE;}
">>"		{return SHR;}
"<<"		{return SHL;}
"->"		{return INDIRECT;}
"++"		{return INC;}	
"--"		{return DEC;}
"*="		{return MUL_EQ;}
"/="		{return DIV_EQ;}
"%="		{return MOD_EQ;}
"+="		{return ADD_EQ;}
"-="		{return SUB_EQ;}
"<<="		{return SHL_EQ;}
">>="		{return SHR_EQ;}
"&="		{return AND_EQ;}
"^="		{return XOR_EQ;}
"|="		{return OR_EQ;}
"..."		{return DOTDOTDOT;}

"\n"        {   }
[ \t]       {   }
.           {yyerror("Error: unknown character");}
%%
