#include <stdio.h>
#include "ast.h"

void *smalloc(size_t len);

struct astnode *newast(int type,void *left,void* right)
{
	
	struct astnode *ptr;
	
	ptr=smalloc(sizeof(struct astnode));
	ptr->type=type;
	ptr->left=left;
	ptr->right=right;
	
	return ptr;
	
}

struct numbernode *newnumber(int type,int number)
{
	
	struct numbernode *ptr;
	
	ptr=smalloc(sizeof(struct astnode));
	ptr->type=type;
	ptr->number=number;
	
	return ptr;
	
}