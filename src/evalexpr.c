#include <stdio.h>
#include "ast.h"
#include "eval.h"
#include "parser.h"
void yyerror (char const *s);
extern FILE *file;

int labelcounter=0;

void expr_eval(struct astnode *ptr)
{
	
	if(ptr==NULL)
	{
		
		return;
		
	}
	
	switch(ptr->type)
	{
		case LOR:
		{
			int local=labelcounter++;
			expr_eval(ptr->left);
			//logic or evaluation, only evaluate right side if necessary
			expr_eval(ptr->right);
			break;
		}
		case LAND:
		{
			int local=labelcounter++;
			expr_eval(ptr->left);
			//logic and evaluation, only evaluate right side if necessary
			expr_eval(ptr->right);
			break;
		}
		case '|':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//OR expression
			break;
			
		case '^':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//XOR expression
			break;
			
		case '&':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//AND expression
			break;
			
		case EQ:
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Equality expression
			break;
			
		case NE:
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Non-equality expression
			break;
			
		case '>':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Larger then
			break;
			
		case '<':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Smaller then
			break;
			
		case GE:
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Greater then or equal to.
			break;
			
		case LE:
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Less then or equal to.
			break;
			
		case SHL:
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Shift left
			break;
			
		case SHR:
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Shift Right
			break;
			
		case '+':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Add
			break;
			
		case '-':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Subtract
			break;
			
		case '*':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Multiply
			break;
			
		case '/':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Divide
			break;
			
		case '%':
			expr_eval(ptr->right);
			expr_eval(ptr->left);
			//Modulo
			break;	
			
		case NEGATE:
			expr_eval(ptr->left);
			//Negate
			break;
			
		case '~':
			expr_eval(ptr->left);
			//Not
			break;
		
		case '!':
			expr_eval(ptr->left);
			//Logical not
			break;
			
		case ICONSTANT:
		{
			struct numbernode *num=(struct numbernode *)ptr;
			//Get number 
			break;
		}
		default:
			yyerror("Warning: Unknown expression type");
			break;
		
	}
	
	return;
	
}