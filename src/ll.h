#ifndef CC_LL_H
#define CC_LL_H

struct ptr_ll_node {
    struct ptr_ll_node *next;
    void *ptr;
};

struct ptr_ll {
    unsigned len;
    struct ptr_ll_node *top;
    struct ptr_ll_node *bottom;
};

void ptr_ll_add(struct ptr_ll*, void*);
void ptr_ll_iter(struct ptr_ll*, void(*)(void*));

#endif
