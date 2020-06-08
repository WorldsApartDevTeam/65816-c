#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "typelist.h"
#include "eval.h"
#include "parser.h"
#include "free.h"
void yyerror (char const *s);

extern FILE *file; 

void func_eval(struct astnode *ptr)
{
	
	if(ptr->type!=FUNCTION)
	{
		
		yyerror("Warning: Invalid function");
		
	}
	
	//Start function code left side is name of function
	
	stmt_eval(ptr->right);
	
	freenode(ptr->right);
	free(ptr->left);
	free(ptr);
	
	return;
	
}