#include <stdio.h>
#include <ast.h>

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

struct numbernode *newnumber(int type,long long number)
{
	
	struct numbernode *ptr;
	
	ptr=smalloc(sizeof(struct numbernode));
	ptr->type=type;
	ptr->number=number;
	
	return ptr;
	
}

struct floatnode *newfloat(int type,long double number)
{
	
	struct floatnode *ptr;
	
	ptr=smalloc(sizeof(struct floatnode));
	ptr->type=type;
	ptr->number=number;
	
	return ptr;
	
}

struct fornode *newfor(int type,void *a,void *b,void *c,void *statement)
{
	
	struct fornode *ptr;
	
	ptr=smalloc(sizeof(struct fornode));
	ptr->type=type;
	ptr->a=a;
	ptr->b=b;
	ptr->c=c;
	ptr->statement=statement;
	
	return ptr;
	
}