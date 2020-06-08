#include <stdio.h>
#include "ast.h"
#include "eval.h"
#include "parser.h"
void yyerror (char const *s);
extern FILE *file;


void stmt_eval(struct astnode *ptr)
{
	
	if(ptr==NULL)
	{
		
		return;
		
	}
	
	switch(ptr->type)
	{
		
		case COMPOUND:
			//Enter frame
			stmt_eval(ptr->left);
			//Leave frame
			break;
			
		case STATEMENT:
			stmt_eval(ptr->left);
			stmt_eval(ptr->right);
			//Left is current statement
			//Right is next statement
			break;
			
		case RETURN:
			expr_eval(ptr->left);
			//Return assembly
			break;
		
		default:
			yyerror("Warning: Unknown statement type");
			break;
		
	}
	
	return;
	
}