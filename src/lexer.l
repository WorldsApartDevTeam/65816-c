%{

    #include <stdio.h>
    #include "parser.h"

    void yyerror(char *str);
    char *strndup(char *str,size_t len);


%}

%option noyywrap
D   [0-9]
C   [a-zA-Z]

%%
"int"		{return INT;}
"return"	{return RETURN;}

[0-9]+                  {yylval.d=atoi(yytext);return ICONSTANT;}
[_a-zA-Z][_a-zA-Z0-9]*    {yylval.str=strndup(yytext,32);return ID;}

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

"\n"        {   }
[ \t]       {   }
.           {yyerror("Error: unknown character");}
%%
