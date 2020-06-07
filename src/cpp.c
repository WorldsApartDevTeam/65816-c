#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpp.h"
#include "ll.h"

struct ptr_ll* cpp_readAndLineBreak(FILE *file) {
    fseek(file, 0, SEEK_END);
    unsigned size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buf = malloc(size+1); // We may not need the +1, but it's there in case we do
    fread(buf, 1, size, file);
    fclose(file);
    buf[size] = 0; // Just in case.
    char *curLine = strtok(buf, "\n");
    struct ptr_ll *lines = calloc(1, sizeof(struct ptr_ll));
    while(curLine) {
        ptr_ll_add(lines, curLine);
        curLine = strtok(NULL, "\n"); // Keep "tokenizing" the same string
    }
    return lines;
}

void cpp_mergeLines(struct ptr_ll* lines) {
    struct ptr_ll_node *curNode = lines->top;
    while(curNode) {
        char *curLine = (char*) curNode->ptr;
        unsigned lineLen = strlen(curLine);
        if(curLine[lineLen-1] == '\\') {
            struct ptr_ll_node *nextNode = curNode->next;
            if(!nextNode) return; // RIP, let the parser catch the syntax error
            char *nextLine = (char*) nextNode->ptr;
            unsigned nextLineLen = strlen(nextLine);
            char *newLine = malloc(lineLen+nextLineLen);
            for(unsigned i = 0; i < lineLen-1; i++) {
                newLine[i] = curLine[i];
            }
            for(unsigned i = 0; i < nextLineLen; i++) {
                newLine[i+lineLen-1] = nextLine[i];
            }
            newLine[lineLen+nextLineLen-1] = 0; // Yes, this is correct.
            curNode->ptr = newLine;
            curNode->next = nextNode->next; // Skip over the other node.
            free(nextNode); // And now that node doesn't actually exist.
            lines->len--; // Reflect that in the length so that we don't segfault.
        } else curNode = curNode->next;
    }
}

void cpp_prints(void *output) {
    char *out = (char*)output;
    printf("%s\n", out);
}

char* cpp(FILE *file) {
    struct ptr_ll *lines = cpp_readAndLineBreak(file);
    cpp_mergeLines(lines);
    ptr_ll_iter(lines, cpp_prints);
    return "";
}
