%{

    #include <stdio.h>
    #include "parser.h"

    void yyerror(char *str);
    char *istrndup(char *str,size_t len);


%}

%option noyywrap
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			([Ee][+-]?{D}+)
P           ([Pp][+-]?{D}+)
FS			(f|F|l|L)
IS          ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

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

[0-9]+                  {yylval.d=atol(yytext);return ICONSTANT;}
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
