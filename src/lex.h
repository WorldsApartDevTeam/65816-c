#ifndef CC_LEX
#define CC_LEX

#include <stdio.h>

struct token {
    char *token;
    unsigned line;
    unsigned column;
    char *filename;
};

struct token* lex(char *file);

#endif
