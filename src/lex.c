#include <stdio.h>

#include "lex.h"

struct token_ll_node {
    struct token_ll_node *next;
    char *token;
    unsigned line;
    unsigned column;
};

struct token_ll {
    unsigned len;
    struct token_ll_node *top;
    struct token_ll_node *bottom;
};

struct token* lex(char *file) {
    return 0;
}
