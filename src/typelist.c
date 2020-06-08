#include <stdio.h>
#include <typelist.h>

void *smalloc(size_t len);

struct tlink *newtype(int type,void *next)
{
	
	struct tlink *ptr;
	
	ptr=smalloc(sizeof(struct tlink));
	ptr->type=type;
	ptr->next=next;
	
	return ptr;
	
}
