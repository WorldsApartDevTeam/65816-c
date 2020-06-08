#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>

#include "cpp.h"

int yyparse();
FILE *yyin;

struct input_ll_node {
    struct input_ll_node *next;
    char *name;
};

struct input_ll {
    unsigned len;
    struct input_ll_node *top;
    struct input_ll_node *bottom;
};

const static char *usage = "\
Usage:\n\
    %s [options] file...\n\
\n\
Options:\n\
  -c         Compile and assemble, but do not link.\n\
  -o <file>  Place the output into <file>.\n";

noreturn void help(const char *progname) {
    fprintf(stderr, usage, progname);
    exit(1);
}

char* compile(char *filename) {
    FILE *file = fopen(filename, "r");
    if(!file) { fprintf(stderr, "Error: could not open file `%s`: %s\n", filename, strerror(errno)); exit(1); }

    char *preprocessed = cpp(file);

    printf("%s", preprocessed);

    fclose(file);
	file = fopen(filename, "r");
	yyin=file;
	yyparse();
    return filename; // Haven't finished processing
}

void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

void *smalloc(size_t len)
{

    void* ptr;

    ptr=calloc(len,1);
    if(ptr==NULL)
    {

        fprintf(stderr,"Error: Out of Memory\n");
        exit(-1);

    }

    return ptr;

}

char *strndup(char *str,size_t len)
{

    char *new;

    len=strlen(str)>len?len:strlen(str);
    new=smalloc(len);
    strncpy(new,str,len);

    return new;

} 

int main(int argc, const char **argv) {
    bool object = 0;

    if(argc <= 1) help(argv[0]);
    const char **arg = &argv[1];
    char *output = NULL;
    struct input_ll inputs;
    inputs.len = 0;
    inputs.top = NULL;
    inputs.bottom = NULL;

    while(*arg != NULL) {
        if((*arg)[0] == '-') {
            const char *opt = &(*arg)[1];
            while(*opt != 0) {
                switch(*opt) {
                case 'c':
                    object = 1;
                    opt++;
                    break;
                case 'o':
                    if(output) {
                        fprintf(stderr, "Error: too many outputs\n");
                    }
                    opt++;
                    if(*opt == 0) {
                        opt = &(*(++arg))[0];
                    }
                    output = malloc(strlen(opt)+1);
                    char *realOutp = output;
                    while(*opt != 0) {
                        *(output++) = *(opt++);
                    }
                    output = realOutp;
                    break;
                default:
                    fprintf(stderr, "Error: unrecognized option '-%c'\n", *opt);
                    exit(1);
                }
            }
        } else {
            inputs.len++;
            struct input_ll_node *curInput = malloc(sizeof(struct input_ll_node));
            curInput->next = NULL;
            curInput->name = malloc(strlen(*arg)+1);
            char *realName = curInput->name;
            while(**arg != 0) {
                *(curInput->name++) = *((*arg)++);
            }
            curInput->name = realName;
            if(inputs.bottom) inputs.bottom->next = curInput;
            inputs.bottom = curInput;
            if(!inputs.top) inputs.top = curInput; // First input
        }
        arg++;
    }

    if(object && (inputs.len > 1)) {
        fprintf(stderr, "Error: too many input files!\n");
        return 1;
    }

    if(!inputs.len) {
        fprintf(stderr, "Error: no input files!\n");
        return 1;
    }

    if(!output) {
        if(object) {
            output = malloc(strlen(inputs.top->name)+1);
            strcpy(output, inputs.top->name);
            output[strlen(inputs.top->name)] = 0;
            output[strlen(inputs.top->name)-1] = 'o'; // Replace ".c" with ".o"
        } else {
            output = "a.out";
        }
    }

    struct input_ll_node *curNode = inputs.top;
    while(curNode != NULL) {
        if(curNode->name[strlen(curNode->name)-1] == 'c') {
            curNode->name = compile(curNode->name);
        }
        curNode = curNode->next;
    }
	
	
	
}
