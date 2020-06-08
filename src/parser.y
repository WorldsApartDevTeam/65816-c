%{

    #include <stdio.h>
    #include "parser.h"
	#include "ast.h"
	#include "eval.h"
	#include "typelist.h"
    void yyerror(const char *s);
    int yylex(void);

%}


%union
{
    int d;
	char c;
    char *str;
	struct astnode *node;
	struct tlink *link;
}

%token INT 
%token RETURN
%token SHL SHR LE GE NE EQ LOR LAND

%token STATEMENT COMPOUND FUNCTION DECLLIST DECLARATION DECLARATOR
%token NEGATE

%token <d>      ICONSTANT 
%token <str>    ID

%type <node> function_definition 
%type <node> direct_declarator declarator init_declarator declaration declaration_list
%type <node> compound_statement statement_list statement jump_statement
%type <node> expression logical_or_expression logical_and_expression inclusive_or_expression 
%type <node> exclusive_or_expression and_expression equality_expression relational_expression 
%type <node> shift_expression additive_expression multiplicative_expression 
%type <node> unary_expression primary_expression

%type <d> type_qualifier

%type <link> declaration_specifiers

%start translation_unit

%%

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition	{func_eval($1);}
	| declaration			{yyerror("Error: declaration not implemented\n");}
	;

function_definition
	: INT ID '(' ')' compound_statement		{$$=newast(FUNCTION,(void*)$2,$5);}
	;
	
compound_statement
	: '{' '}'									{$$=newast(COMPOUND,NULL,NULL);}
	| '{' statement_list '}'					{$$=newast(COMPOUND,$2,NULL);}
	| '{' declaration_list '}'					{$$=newast(COMPOUND,NULL,$2);}
	| '{' declaration_list statement_list '}'	{$$=newast(COMPOUND,$3,$2);}
	;

declaration_list
	: declaration								{$$=$1;}
	| declaration_list declaration				{$$=newast(DECLLIST,$1,$2);}
	;
	
declaration
	: declaration_specifiers init_declarator ';'	{$$=newast(DECLARATION,$1,$2);}
	;
	
declaration_specifiers
	: type_qualifier		{$$=newtype($1,NULL);}
	;
	
type_qualifier
	: INT 		{$$=INT;}
	;
	

init_declarator
	: declarator							{$$=newast(DECLARATOR,$1,NULL);}
	| declarator '=' expression				{$$=newast(DECLARATOR,$1,$3);}
	;
	
declarator
	: direct_declarator						{$$=$1;}
	;

direct_declarator
	: ID									{$$=newast(ID,$1,NULL);}
	| '(' declarator ')'					{$$=$2;}
	;
		

statement_list
    : statement								{$$=$1;}
    |  statement statement_list				{$$=newast(STATEMENT,$1,$2);}
    ;

statement
	: jump_statement						{$$=$1;}
	| compound_statement					{$$=$1;}
	;

jump_statement
	: RETURN expression ';'					{$$=newast(RETURN,$2,NULL);}
	;

expression
	: logical_or_expression									{$$=$1;}
	;

logical_or_expression
	: logical_and_expression								{$$=$1;}
	| logical_or_expression LOR logical_and_expression		{$$=newast(LOR,$1,$3);}
	;
	
logical_and_expression 
	: inclusive_or_expression								{$$=$1;}
	| logical_and_expression LAND inclusive_or_expression	{$$=newast(LAND,$1,$3);}
	;

inclusive_or_expression
	: exclusive_or_expression								{$$=$1;}
	| inclusive_or_expression '|' exclusive_or_expression	{$$=newast('|',$1,$3);}
	;
	
exclusive_or_expression
	: and_expression										{$$=$1;}
	| exclusive_or_expression '^' and_expression			{$$=newast('^',$1,$3);}
	;
	
and_expression
	: equality_expression									{$$=$1;}
	| and_expression '&' equality_expression				{$$=newast('&',$1,$3);}
	;

equality_expression
	: relational_expression									{$$=$1;}
	| equality_expression EQ relational_expression			{$$=newast(EQ,$1,$3);}
	| equality_expression NE relational_expression			{$$=newast(NE,$1,$3);}
	;
	
relational_expression
	: shift_expression										{$$=$1;}
	| relational_expression '<' shift_expression			{$$=newast('<',$1,$3);}
	| relational_expression '>' shift_expression			{$$=newast('>',$1,$3);}
	| relational_expression LE shift_expression				{$$=newast(LE,$1,$3);}
	| relational_expression GE shift_expression				{$$=newast(GE,$1,$3);}
	;

shift_expression	
	: additive_expression									{$$=$1;}
	| shift_expression SHL additive_expression				{$$=newast(SHL,$1,$3);}
	| shift_expression SHR additive_expression				{$$=newast(SHL,$1,$3);}
	;

additive_expression
    : multiplicative_expression								{$$=$1;}
    | additive_expression '+' multiplicative_expression		{$$=newast('+',$1,$3);}
    | additive_expression '-' multiplicative_expression		{$$=newast('-',$1,$3);}
    ;

multiplicative_expression
	: unary_expression										{$$=$1;}
	| multiplicative_expression '*' unary_expression		{$$=newast('*',$1,$3);}
	| multiplicative_expression '/' unary_expression		{$$=newast('/',$1,$3);}
	| multiplicative_expression '%' unary_expression		{$$=newast('%',$1,$3);}
	;
	
unary_expression
	: primary_expression					{$$=$1;}
	| '+' unary_expression 					{$$=$2;}
	| '-' unary_expression					{$$=newast(NEGATE,$2,NULL);}
	| '~' unary_expression					{$$=newast('~',$2,NULL);}
	| '!' unary_expression					{$$=newast('!',$2,NULL);}
	;

primary_expression
	: ICONSTANT				{$$=(void*)newnumber(ICONSTANT,$1);}
	| '(' expression ')'	{$$=$2;}
	;

%%


