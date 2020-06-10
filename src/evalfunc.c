#include <stdio.h>
#include <stdlib.h>
#include <ast.h>
#include <typelist.h>
#include <eval.h>
#include <parser.h>
#include <free.h>
void yyerror (char const *s);

extern FILE *file; 

void func_eval	( struct astnode *declaration_specifiers
				, struct astnode *declarator
				, struct astnode *declaration_list
				, struct astnode *compound_statement)
{
	
	
	//Start function code left side is name of function
	printf("Evaluated function\n");
	
	//freenode(ptr->right);
	//free(ptr->left);
	//free(ptr);
	
	return;
	
}
void global_eval (struct astnode *ptr)
{
	printf("Evaluated global\n");
	return;
}
int check_typedef(char *identifier)
{
	//Add code to check if an identifier has been defined via typedef.
	//Otherwise there are a lot of ambiguities in the C grammar itself
	return ID;
}