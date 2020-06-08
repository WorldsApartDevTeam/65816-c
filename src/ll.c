  
#include <stdlib.h>

#include "ll.h"

void ptr_ll_add(struct ptr_ll *ll, void *ptr) {
    struct ptr_ll_node *newNode = malloc(sizeof(struct ptr_ll_node));
    newNode->ptr = ptr;
    newNode->next = NULL;
    if(ll->bottom) ll->bottom->next = newNode;
    ll->bottom = newNode;
    if(!ll->top) ll->top = newNode;
}

void ptr_ll_iter(struct ptr_ll *ll, void (*fn)(void*)) {
    struct ptr_ll_node *curNode = ll->top;
    while(curNode != NULL) {
        fn(curNode->ptr);
        curNode = curNode->next;
    }
}