
void func_eval	( struct astnode *declaration_specifiers
				, struct astnode *declarator
				, struct astnode *declaration_list
				, struct astnode *compound_statement);
void global_eval (struct astnode *ptr);
void stmt_eval(struct astnode *ptr);
void expr_eval(struct astnode *ptr);
