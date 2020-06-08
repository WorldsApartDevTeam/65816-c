#include <stdio.h>
#include <stdlib.h>
#include <ast.h>
#include <parser.h>
void yyerror (char const *s);

void freenode(struct astnode *ptr)
{
	
	if(ptr==NULL)
	{
		
		return;
		
	}
	
	switch(ptr->type)
	{
		case STATEMENT:
		
		case LOR:
		case LAND:
		case '|':
		case '^':
		case '&':
		case EQ:
		case NE:	
		case '>':
		case '<':
		case GE:	
		case LE:
		case SHL:
		case SHR:
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			freenode(ptr->right);
			
		case COMPOUND:
		case RETURN: 
			
		case NEGATE:
		case '~':
		case '!':
			freenode(ptr->left);
			
		case ICONSTANT:
			free(ptr);
			break;
			
		default:
			yyerror("Warning: Unknown expression type in free");
			break;
		
	}
	
	return;
	
}