#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpp.h"
#include "ll.h"

struct cpp_line {
   char *line;
   int number;
};

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
    while(curLine != NULL) {
        ptr_ll_add(lines, curLine);
        curLine = strtok(NULL, "\n"); // Keep "tokenizing" the same string
    }
    return lines;
}

void cpp_prints(void *output) {
    char *out = (char*)output;
    printf("%s\n", out);
}

char* cpp(FILE *file) {
    struct ptr_ll* lines = cpp_readAndLineBreak(file);
    ptr_ll_iter(lines, cpp_prints);
    return "";
}
