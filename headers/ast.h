
struct astnode 
{
	int type;
	void *left;
	void *right;
};

struct numbernode
{
	int type;
	int number;
};

struct astnode *newast(int type,void *left,void* right);
struct numbernode *newnumber(int type,int number);