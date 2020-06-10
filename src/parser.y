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


%token ASM ATTRIBUTE INLINE NORETURN
%token INT LONG SHORT CHAR FLOAT DOUBLE BOOL VOID STRUCT TYPEDEF UNION ENUM
%token SIGNED UNSIGNED STATIC AUTO VOLATILE ATOMIC EXTERN CONST RESTRICT REGISTER
%token IF ELSE WHILE DO FOR SWITCH CASE DEFAULT LABEL
%token RETURN GOTO BREAK CONTINUE
%token SHL SHR LE GE NE EQ LOR LAND SIZEOF
%token INC DEC INDIRECT DOTDOTDOT
%token MUL_EQ DIV_EQ MOD_EQ ADD_EQ SUB_EQ SHL_EQ SHR_EQ AND_EQ XOR_EQ OR_EQ

%token STATEMENT COMPOUND FUNCTION IFELSE STRUCT_UNION TYPEDEF_ID
%token BLOCKLIST DECLARATION DECLARATOR DECLARATOR_LIST INIT_EXPRESSION
%token NEGATE ARRAY FUNCCALL POSTINC POSTDEC PREINC PREDEC
%token ARGLIST CAST 
%token STRUCT_DECLARATION_LIST STRUCT_DECLARATION SPECIFIER_QUALIFIER_LIST STRUCT_DECLARATOR_LIST STRUCT_DECLARATOR
%token ENUMERATOR_LIST ENUMERATOR ATOMIC2
%token POINTER TYPE_QUALIFIER_LIST PARAMETER_LIST PARAMETER_DECLARATION IDENTIFIER_LIST
%token TYPE_NAME ABSTRACT_DECLARATOR DECLERATION_LIST
%token INITIALIZER_LIST DESIGNATION DESIGNATION_INITIALIZER DESIGNATOR_LIST
%token ASM_QUALIFER ASM_QUALIFER_LIST ASM_OPERAND ASM_OPERAND_LIST ASM_OPERAND_LIST_2

%token <str>    ID STRING FCONSTANT ICONSTANT ENUM_CONSTANT TYPEDEF_NAME

%type <node> function_definition 
%type <node> direct_declarator declarator init_declarator declaration block_item_list block_item
%type <node> declaration_specifiers_opt enum_specifier struct_union_specifier atomic_type_specifier
%type <node> struct_declariation_list struct_declariation specifier_qualifier_list struct_declarator_list struct_declarator specifier_qualifier_list_opt
%type <node> enumerator_list enumerator assembly_statement
%type <node> init_declarator_list initializer parameter_type_list parameter_declaration
%type <node> compound_statement  statement jump_statement labeled_statement selection_statement iteration_statement
%type <node> expression assignment_expression conditional_expression constant_expression expression_opt
%type <node> logical_or_expression logical_and_expression inclusive_or_expression 
%type <node> exclusive_or_expression and_expression equality_expression relational_expression 
%type <node> shift_expression additive_expression multiplicative_expression 
%type <node> cast_expression unary_expression postfix_expression argument_expression_list primary_expression
%type <node> declaration_specifiers pointer type_qualifier_list parameter_list identifier_list 
%type <node> type_name abstract_declarator direct_abstract_declarator attribute_specifier
%type <node> initializer_list designation designator_list designator designation_initializer declaration_list 
%type <node> asm_qualifier_list asm_operand_list  asm_operand asm_operand_list_2

%type <d> type_qualifier assignment_operator storage_class_specifier struct_or_union type_specifier asm_qualifier





%start translation_unit

%%

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition	
	| declaration			{global_eval($1);}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement		
							{func_eval($1,$2,$3,$4);}
	| declaration_specifiers declarator compound_statement		
							{func_eval($1,$2,NULL,$3);}
	;
	
declaration_list
	: declaration					{$$=newast(DECLERATION_LIST,$1,NULL);}
	| declaration_list declaration 	{$$=newast(DECLERATION_LIST,$2,$1);}
	
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
	: storage_class_specifier declaration_specifiers_opt	{$$=newast($1,$2,NULL);}
	| type_specifier declaration_specifiers_opt				{$$=newast($1,$2,NULL);}
	| atomic_type_specifier declaration_specifiers_opt		{$$=newast(ATOMIC,$2,$1);}
	| struct_union_specifier declaration_specifiers_opt		{$$=newast(STRUCT_UNION,$2,$1);}
	| enum_specifier declaration_specifiers_opt				{$$=newast(ENUM,$2,$1);}
	| TYPEDEF_NAME declaration_specifiers_opt				{$$=newast(TYPEDEF_ID,$2,$1);}
	| attribute_specifier declaration_specifiers_opt		{$$=newast(ATTRIBUTE,$2,$1);}
	| type_qualifier declaration_specifiers_opt				{$$=newast($1,$2,NULL);}
	;
	
declaration_specifiers_opt
	: declaration_specifiers							{$$=$1;}
	| 													{$$=NULL;}
	;

init_declarator_list
	: init_declarator							{$$=newast(DECLARATOR_LIST,NULL,$1);}
	| init_declarator_list ',' init_declarator	{$$=newast(DECLARATOR_LIST,$1,$3);}
	;

init_declarator
	: declarator							{$$=newast(DECLARATOR,$1,NULL);}
	| declarator '=' initializer			{$$=newast(DECLARATOR,$1,$3);}
	;
	


storage_class_specifier
	: TYPEDEF		{$$=TYPEDEF;}
	| EXTERN		{$$=EXTERN;}
	| STATIC		{$$=STATIC;}
	| AUTO			{$$=AUTO;}
	| REGISTER		{$$=REGISTER;}
	;

type_specifier
	: INT 										{$$=INT;}
	| VOID										{$$=VOID;}
	| CHAR										{$$=CHAR;}
	| SHORT										{$$=SHORT;}
	| LONG										{$$=LONG;}
	| FLOAT										{$$=FLOAT;}
	| DOUBLE									{$$=DOUBLE;}
	| SIGNED									{$$=SIGNED;}
	| UNSIGNED									{$$=UNSIGNED;}
	| BOOL										{$$=BOOL;}
	;
	
atomic_type_specifier
	: ATOMIC '(' type_name	')'				{$$=newast(ATOMIC,$3,NULL);}
	; // INCOMPLETE




struct_union_specifier	
	: struct_or_union ID '{' struct_declariation_list '}'	{$$=newast($1,$2,$4);}
	| struct_or_union  '{' struct_declariation_list '}'		{$$=newast($1,NULL,$3);}
	| struct_or_union ID									{$$=newast($1,$2,NULL);}
	;
	
struct_or_union
	:	STRUCT		{$$=STRUCT;}
	|	UNION		{$$=UNION;}
	;
	
struct_declariation_list
	: struct_declariation									{$$=newast(STRUCT_DECLARATION_LIST,$1,NULL);}
	| struct_declariation_list struct_declariation			{$$=newast(STRUCT_DECLARATION_LIST,$2,$1);}
	;
	
struct_declariation
	: specifier_qualifier_list struct_declarator_list ';'	{$$=newast(STRUCT_DECLARATION,$1,$2);}
	| specifier_qualifier_list ';'							{$$=newast(STRUCT_DECLARATION,$1,NULL);}
	;
	
specifier_qualifier_list 
	: type_specifier specifier_qualifier_list_opt			{$$=newast($1,$2,NULL);}
	| atomic_type_specifier specifier_qualifier_list_opt	{$$=newast(ATOMIC,$2,$1);}
	| struct_union_specifier specifier_qualifier_list_opt	{$$=newast(STRUCT_UNION,$2,$1);}
	| enum_specifier specifier_qualifier_list_opt			{$$=newast(ENUM,$2,$1);}
	| TYPEDEF_NAME specifier_qualifier_list_opt				{$$=newast(TYPEDEF_ID,$2,$1);}
	| type_qualifier specifier_qualifier_list_opt			{$$=newast($1,$2,NULL);}
	;
	
specifier_qualifier_list_opt
	: specifier_qualifier_list	{$$=$1;}
	|							{$$=NULL;}
	;
	
struct_declarator_list
	: struct_declarator										{$$=newast(STRUCT_DECLARATOR_LIST,$1,NULL);}
	| struct_declarator_list ',' struct_declarator			{$$=newast(STRUCT_DECLARATOR_LIST,$3,$1);}
	;
	
struct_declarator
	: declarator											{$$=newast(STRUCT_DECLARATOR,$1,NULL);}		
	| declarator ':' constant_expression					{$$=newast(STRUCT_DECLARATOR,$1,$3);}
	| ':' constant_expression								{$$=newast(STRUCT_DECLARATOR,NULL,$2);}
	;



	
enum_specifier
	: ENUM '{'enumerator_list '}'			{$$=newast(ENUM,NULL,$3);}
	| ENUM ID '{'enumerator_list  '}'		{$$=newast(ENUM,$2,$4);}
	| ENUM '{'enumerator_list ',' '}'		{$$=newast(ENUM,NULL,$3);}
	| ENUM ID '{'enumerator_list ',' '}'	{$$=newast(ENUM,$2,$4);}
	| ENUM ID 								{$$=newast(ENUM,$2,NULL);}
	;
	
enumerator_list
	: enumerator 							{$$=newast(ENUMERATOR_LIST,$1,NULL);}
	| enumerator_list ',' enumerator		{$$=newast(ENUMERATOR_LIST,$3,$1);}
	
enumerator
	: ID									{$$=newast(ENUMERATOR,$1,NULL);}
	| ID '=' constant_expression			{$$=newast(ENUMERATOR,$1,$3);}
	;
	
type_qualifier
	: CONST									{$$=CONST;}
	| RESTRICT								{$$=RESTRICT;}
	| VOLATILE								{$$=VOLATILE;}
	| ATOMIC								{$$=ATOMIC2;}
	| NORETURN								{$$=NORETURN;}
	| INLINE								{$$=INLINE;}
	; 
	
attribute_specifier
	: ATTRIBUTE '(' '(' ID  ')' ')'			{$$=newast(ATTRIBUTE,$4,NULL);}
	| ATTRIBUTE '(' '(' ID '(' argument_expression_list ')'  ')' ')'
											{$$=newast(ATTRIBUTE,$4,$6);}
	;


declarator
	: direct_declarator						{$$=newast(DECLARATOR,$1,NULL);}
	| pointer direct_declarator				{$$=newast(DECLARATOR,$2,$1);}
	;

direct_declarator
	: ID									{$$=newast(ID,$1,NULL);}
	| '(' declarator ')'					{$$=$2;}
	| direct_declarator '[' assignment_expression ']'
											{$$=newast(ARRAY,$1,$3);}
	| direct_declarator '(' parameter_type_list ')'
											{$$=newast(FUNCTION,$1,$3);}
	| direct_declarator '(' identifier_list ')'
											{$$=newast(FUNCTION,$1,$3);}
	| direct_declarator '('  ')'			{$$=newast(FUNCTION,$1,NULL);}										
	;
	
pointer 
	: '*' type_qualifier_list			{$$=newast(POINTER,$2,NULL);}
	| '*'								{$$=newast(POINTER,NULL,NULL);}
	| '*' type_qualifier_list pointer	{$$=newast(POINTER,$2,$3);}
	| '*'  pointer						{$$=newast(POINTER,NULL,$2);}
	;
	
type_qualifier_list
	: type_qualifier						{$$=newast($1,NULL,NULL);}
	| type_qualifier_list type_qualifier	{$$=newast($2,$1,NULL);}
	;
	
parameter_type_list 
	: parameter_list						{$$=$1;}
	| parameter_list ',' DOTDOTDOT			{$$=newast(DOTDOTDOT,$1,NULL);}
	;
	
parameter_list
	: parameter_declaration						{$$=newast(PARAMETER_LIST,$1,NULL);}
	| parameter_list ',' parameter_declaration	{$$=newast(PARAMETER_LIST,$3,$1);}
	;
	
parameter_declaration
	: declaration_specifiers declarator			{$$=newast(PARAMETER_DECLARATION,$1,$2);}
	| declaration_specifiers					{$$=newast(PARAMETER_DECLARATION,$1,NULL);}
	| declaration_specifiers abstract_declarator{$$=newast(PARAMETER_DECLARATION,$1,$2);}
	;

identifier_list
	: ID 									{$$=newast(IDENTIFIER_LIST,$1,NULL);}
	| identifier_list ',' ID				{$$=newast(IDENTIFIER_LIST,$3,$1);}
	;

 
	
type_name
	: specifier_qualifier_list abstract_declarator	{$$=newast(TYPE_NAME,$1,$2);}
	| specifier_qualifier_list						{$$=newast(TYPE_NAME,$1,NULL);}
	;
	
abstract_declarator
	: pointer								{$$=newast(ABSTRACT_DECLARATOR,$1,NULL);}
	| direct_abstract_declarator			{$$=newast(ABSTRACT_DECLARATOR,NULL,$1);}
	| pointer direct_abstract_declarator	{$$=newast(ABSTRACT_DECLARATOR,$1,$2);}
	;
	
direct_abstract_declarator
	: '(' abstract_declarator ')'				{$$=$2;}
	| direct_abstract_declarator '[' ']'	{$$=newast(ARRAY,$1,NULL);}
	| direct_abstract_declarator '[' assignment_expression ']'
												{$$=newast(ARRAY,$1,$3);}
	| direct_abstract_declarator '(' parameter_type_list ')'
												{$$=newast(FUNCTION,$1,$3);}
	| direct_abstract_declarator '(' ')'		{$$=newast(FUNCTION,$1,NULL);}
	| '[' ']'									{$$=newast(ARRAY,NULL,NULL);}
	| '[' assignment_expression ']'				{$$=newast(ARRAY,NULL,$2);}
	| '(' parameter_type_list ')'				{$$=newast(FUNCTION,NULL,$2);}
	| '(' ')'									{$$=newast(FUNCTION,NULL,NULL);}
	;
	

	
initializer
	: assignment_expression					{$$=newast(INIT_EXPRESSION,$1,NULL);}
	| '{' initializer_list '}'				{$$=$2;}
	| '{' initializer_list ',' '}'			{$$=$2;}
	;
		
initializer_list 
	: designation_initializer						{$$=newast(INITIALIZER_LIST,$1,NULL);}
	| initializer_list ',' designation_initializer	{$$=newast(INITIALIZER_LIST,$3,$1);}
	;
	
designation_initializer
	: initializer 							{$$=newast(DESIGNATION_INITIALIZER,$1,NULL);}
	| designation initializer				{$$=newast(DESIGNATION_INITIALIZER,$2,$1);}
	
designation
	: designator_list '='					{$$=$1;}
	
designator_list
	: designator							{$$=newast(DESIGNATOR_LIST,$1,NULL);}
	| designator_list designator			{$$=newast(DESIGNATOR_LIST,$2,$1);}
	;
	
designator
	: '[' constant_expression ']'			{$$=newast(ARRAY,$2,NULL);}
	| '.' ID 								{$$=newast('.',$2,NULL);}
	;




statement
	: jump_statement						{$$=$1;}
	| compound_statement					{$$=$1;}
	| labeled_statement						{$$=$1;}
	| selection_statement					{$$=$1;}
	| iteration_statement					{$$=$1;}
	| assembly_statement					{$$=$1;}
	| expression_opt						{$$=$1;}
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
	

	
assembly_statement
	: ASM asm_qualifier_list '(' STRING ':'  asm_operand_list ')'
									{$$=newast(ASM,$2,newast(0,$4,$6));}
	| ASM '(' STRING ':'  asm_operand_list ')' 
									{$$=newast(ASM,NULL,newast(0,$3,$5));}
	;								
	
asm_qualifier_list
	: asm_qualifier						{$$=newast($1,NULL,NULL);}
	| asm_qualifier_list asm_qualifier	{$$=newast($2,$1,NULL);}
	;

asm_qualifier
	: VOLATILE	{$$=VOLATILE;}
	| INLINE	{$$=INLINE;}
	| GOTO		{$$=GOTO;}
	;

asm_operand_list
	: asm_operand_list_2						{$$=newast(ASM_OPERAND_LIST,$1,NULL);}
	| asm_operand_list ':' asm_operand_list_2 	{$$=newast(ASM_OPERAND_LIST,$3,$1);}
	;
	
asm_operand_list_2
	: asm_operand							{$$=newast(ASM_OPERAND_LIST_2,$1,NULL);}
	| asm_operand_list_2 ',' asm_operand	{$$=newast(ASM_OPERAND_LIST_2,$3,$1);}
	;
	
asm_operand
	: STRING '(' unary_expression ')'			{$$=newast(ASM_OPERAND,$1,$3);}
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
	| '(' type_name ')'						{$$=newast(CAST,$2,NULL);}
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
	| SIZEOF '(' type_name ')'				{$$=newast(SIZEOF,NULL,$3);}
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
	: ICONSTANT				{$$=newast(ICONSTANT,$1,NULL);}
	| FCONSTANT				{$$=newast(FCONSTANT,$1,NULL);}
	| '(' expression ')'	{$$=$2;}
	| ID					{$$=newast(ID,$1,NULL);}
	| STRING				{$$=newast(STRING,$1,NULL);}
	;

%%


