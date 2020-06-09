
struct astnode 
{
	int type;
	void *left;
	void *right;
};

struct numbernode
{
	int type;
	long long number;
};

struct floatnode
{
	int type;
	long double number;
};

struct fornode
{
	int type;
	void *a;
	void *b;
	void *c;
	void *statement;
};

struct astnode *newast(int type,void *left,void* right);
struct numbernode *newnumber(int type,long long number);
struct floatnode *newfloat(int type, long double number);
struct fornode *newfor(int type,void *a,void *b,void *c,void *statement);