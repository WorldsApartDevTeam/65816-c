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
    long long d;
	long double f;
	char c;
    char *str;
	struct astnode *node;
	struct tlink *link;
}

%token INT LONG SHORT CHAR FLOAT DOUBLE BOOL VOID STRUCT TYPEDEF UNION
%token SIGNED UNSIGNED STATIC AUTO VOLATILE ATOMIC EXTERN CONST RESTRICT REGISTER
%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT LABEL
%token RETURN GOTO BREAK CONTINUE
%token SHL SHR LE GE NE EQ LOR LAND SIZEOF
%token INC DEC INDIRECT DOTDOTDOT
%token MUL_EQ DIV_EQ MOD_EQ ADD_EQ SUB_EQ SHL_EQ SHR_EQ AND_EQ XOR_EQ OR_EQ

%token STATEMENT COMPOUND FUNCTION IFELSE
%token BLOCKLIST DECLARATION DECLARATOR DECLARATOR_LIST INIT_EXPRESSION
%token NEGATE ARRAY FUNCCALL POSTINC POSTDEC PREINC PREDEC
%token ARGLIST

%token <d>      ICONSTANT 
%token <f>		FCONSTANT
%token <str>    ID STRING

%type <node> function_definition 
%type <node> direct_declarator declarator init_declarator declaration block_item_list block_item
%type <node> init_declarator_list initializer
%type <node> compound_statement  statement jump_statement labeled_statement selection_statement iteration_statement
%type <node> expression assignment_expression conditional_expression constant_expression expression_opt
%type <node> logical_or_expression logical_and_expression inclusive_or_expression 
%type <node> exclusive_or_expression and_expression equality_expression relational_expression 
%type <node> shift_expression additive_expression multiplicative_expression 
%type <node> cast_expression unary_expression postfix_expression argument_expression_list
primary_expression

%type <node> declaration_specifiers

%type <d> type_qualifier assignment_operator



%start translation_unit

%%

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition	{func_eval($1);}
	//| declaration			{yyerror("Error: global declaration not implemented\n");}
	;

function_definition
	: INT ID '(' ')' compound_statement		{$$=newast(FUNCTION,(void*)$2,$5);}
	;
	
compound_statement
	: '{' '}'									{$$=newast(COMPOUND,NULL,NULL);}
	| '{' block_item_list '}'					{$$=newast(COMPOUND,$2,NULL);}
	;

block_item_list
	: block_item								{$$=newast(BLOCKLIST,NULL,$1);}
	| block_item_list block_item				{$$=newast(BLOCKLIST,$1,$2);}
	;

block_item
	: declaration								{$$=$1;}
	| statement									{$$=$1;}
	;
	
declaration
	: declaration_specifiers init_declarator_list ';'	{$$=newast(DECLARATION,$1,$2);}
	;
	
declaration_specifiers
	: type_qualifier							{$$=newast($1,NULL,NULL);}
	;
	
type_qualifier
	: INT 										{$$=INT;}
	;

init_declarator_list
	: init_declarator							{$$=newast(DECLARATOR_LIST,NULL,$1);}
	| init_declarator_list ',' init_declarator	{$$=newast(DECLARATOR_LIST,$1,$3);}

init_declarator
	: declarator							{$$=newast(DECLARATOR,$1,NULL);}
	| declarator '=' initializer			{$$=newast(DECLARATOR,$1,$3);}
	;
	
declarator
	: direct_declarator						{$$=$1;}
	;

direct_declarator
	: ID									{$$=newast(ID,$1,NULL);}
	| '(' declarator ')'					{$$=$2;}
	;
	
initializer
	: assignment_expression					{$$=newast(INIT_EXPRESSION,$1,NULL);}
	;
		

statement
	: jump_statement						{$$=$1;}
	| compound_statement					{$$=$1;}
	| labeled_statement						{$$=$1;}
	| selection_statement					{$$=$1;}
	| iteration_statement					{$$=$1;}
	;

labeled_statement
	: ID ':' statement							{$$=newast(LABEL,$1,$3);}
	| CASE  constant_expression':' statement	{$$=newast(CASE,$2,$4);}
	| DEFAULT ':' statement						{$$=newast(DEFAULT,NULL,$3);}
	;

jump_statement
	: RETURN expression_opt					{$$=newast(RETURN,$2,NULL);}
	| GOTO ID ';'							{$$=newast(GOTO,$2,NULL);}
	| CONTINUE ';'							{$$=newast(CONTINUE,NULL,NULL);}
	| BREAK ';'								{$$=newast(CONTINUE,NULL,NULL);}
	;
	
selection_statement
	: IF '(' expression ')' statement		{$$=newast(IF,$3,$5);}
	| IF '(' expression ')' statement ELSE statement
											{$$=newast(IFELSE,newast(IF,$3,$5),$7);}
	| SWITCH '(' expression ')' statement	{$$=newast(SWITCH,$3,$5);}
	;

iteration_statement
	: WHILE '(' expression ')' statement 	{$$=newast(WHILE,$3,$5);}
	| DO statement WHILE '(' expression ')'	{$$=newast(DO,$5,$2);}
	| FOR '(' expression_opt expression_opt expression_opt ')' statement
											{$$=(void*)newfor(FOR,$3,$4,$5,$7);}
	| FOR '(' declaration expression_opt expression_opt ')' statement
											{$$=(void*)newfor(FOR,$3,$4,$5,$7);}
	;
	
expression_opt
	: 	';'				{$$=NULL;}
	|	expression ';'		{$$=$1;}
	;

expression
	: assignment_expression					{$$=$1;}
	| expression ',' assignment_expression	{$$=newast(',',$1,$3);}
	;
	
constant_expression
	: conditional_expression
	;
	
assignment_expression
	: conditional_expression								{$$=$1;}
	| unary_expression assignment_operator assignment_expression {$$=newast($2,$1,$3);}
	;
assignment_operator
	: '='		{$$='=';}
	| MUL_EQ	{$$=MUL_EQ;}
	| DIV_EQ	{$$=DIV_EQ;}
	| MOD_EQ	{$$=MOD_EQ;}
	| ADD_EQ	{$$=ADD_EQ;}
	| SUB_EQ	{$$=SUB_EQ;}
	| SHL_EQ	{$$=SHL_EQ;}
	| SHR_EQ	{$$=SHR_EQ;}
	| AND_EQ	{$$=AND_EQ;}
	| XOR_EQ	{$$=XOR_EQ;}
	| OR_EQ		{$$=OR_EQ;}
	;
	
conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression 
											{$$=newast('?',$1,newast(':',$3,$5));}
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

cast_expression
	: unary_expression						{$$=$1;}
	;

unary_expression
	: postfix_expression					{$$=$1;}
	| INC unary_expression					{$$=newast(PREINC,$2,NULL);}
	| DEC unary_expression					{$$=newast(PREDEC,$2,NULL);}
	| '+' cast_expression 					{$$=$2;}
	| '-' cast_expression					{$$=newast(NEGATE,$2,NULL);}
	| '~' cast_expression					{$$=newast('~',$2,NULL);}
	| '!' cast_expression					{$$=newast('!',$2,NULL);}
	| SIZEOF unary_expression				{$$=newast(SIZEOF,$2,NULL);}
	;

postfix_expression
	: primary_expression					{$$=$1;}
	| postfix_expression '[' expression ']'	{$$=newast(ARRAY,$1,$3);}
	| postfix_expression '(' ')' 			{$$=newast(FUNCCALL,$1,NULL);}
	| postfix_expression '(' argument_expression_list ')' 
											{$$=newast(FUNCCALL,$1,NULL);}
	| postfix_expression '.' ID				{$$=newast('.',$1,$3);}
	| postfix_expression INDIRECT ID		{$$=newast(INDIRECT,$1,$3);}
	| postfix_expression INC				{$$=newast(POSTINC,$1,NULL);}
	| postfix_expression DEC				{$$=newast(POSTDEC,$1,NULL);}
											
argument_expression_list
	: assignment_expression					{$$=newast(ARGLIST,$1,NULL);}
	| argument_expression_list ',' assignment_expression
											{$$=newast(ARGLIST,$3,$1);}

primary_expression
	: ICONSTANT				{$$=(void*)newnumber(ICONSTANT,$1);}
	| FCONSTANT				{$$=(void*)newfloat(FCONSTANT,$1);}
	| '(' expression ')'	{$$=$2;}
	| ID					{$$=newast(ID,$1,NULL);}
	| STRING				{$$=newast(STRING,$1,NULL);}
	;

%%


