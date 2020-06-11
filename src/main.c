#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>

#include <cpp.h>

int yyparse();
extern FILE *yyin;

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

char *istrndup(const char *str,size_t len)
{

    char *newStr;

    len=strlen(str)>len?len:strlen(str);
    newStr=smalloc(len);
    strncpy(newStr,str,len);

    return newStr;

}

#include "ll.h"

struct asm_ast_absolute {
    uint16_t addr;
};

struct asm_ast_long {
    uint32_t addr;
};

struct asm_ast_label { // Can be used as either a node or a param
    char *label;
};

struct asm_ast_param {
    int type;
    void *param;
};

struct asm_ast_instruction {
    uint8_t opcode;
    struct asm_ast_param **params;
};

struct asm_ast_directive {
    char *directive;
    char **params;
};

struct asm_ast_node_generic {
    int type;
    void *node;
};

struct asm_ast {
    struct ptr_ll *nodes;
};

struct ptr_ll* cpp_readAndLineBreak(FILE *file); // I don't want to bother rewriting this...

struct asm_ast cur_ast;

struct asm_ast_param* asm_parse_long(char **line) { // ** so we can advance the pointer
    while(**line == ' ' || **line == '\t') *line++;
    if(**line == '$' && !(*(*line+1) == ' ' || *(*line+1) == '\t')) { // Address
        *line++;
        char *start = *line;
        while(
            (**line >= 'A' && **line <= 'F') ||
            (**line >= 'a' && **line <= 'f') ||
            (**line >= '0' && **line <= '9')
        ) *line++;
        uint32_t value = 0;
        while(*start != 0) {
            value <<= 4;
            if(*start >= 'a')      value += *start - 'a' + 0xa;
            else if(*start >= 'A') value += *start - 'A' + 0xA;
            else                   value += *start - '0' + 0x0;
        }
        struct asm_ast_param *param = malloc(sizeof(struct asm_ast_param));
        param->type = 14;
        struct asm_ast_long *longAddr = malloc(sizeof(struct asm_ast_long));
        longAddr->addr = value;
        return param;
    } else { // Assume it's a label for now
        char *labelStart = *line;
        while(
            (**line >= 'A' && **line <= 'Z') ||
            (**line >= 'a' && **line <= 'z') ||
            (**line >= '0' && **line <= '9') ||
            **line == '$' ||
            **line == '_' ||
            **line == '.' ||
            **line == '+' ||
            **line == '-'
        ) *line++;
        **line = 0; // Null terminate
        struct asm_ast_param *param = malloc(sizeof(struct asm_ast_param));
        param->type = 19;
        struct asm_ast_label *label = malloc(sizeof(struct asm_ast_label));
        label->label = labelStart;
        return param;
    }
}

struct asm_ast_param* asm_parse_rel(char **line) { // ** so we can advance the pointer
    while(**line == ' ' || **line == '\t') *line++;
    if(**line == '$' && !(*(*line+1) == ' ' || *(*line+1) == '\t')) { // Address
        *line++;
        char *start = *line;
        while(
            (**line >= 'A' && **line <= 'F') ||
            (**line >= 'a' && **line <= 'f') ||
            (**line >= '0' && **line <= '9')
        ) *line++;
        uint32_t value = 0;
        while(*start != 0) {
            value <<= 4;
            if(*start >= 'a')      value += *start - 'a' + 0xa;
            else if(*start >= 'A') value += *start - 'A' + 0xA;
            else                   value += *start - '0' + 0x0;
        }
        struct asm_ast_param *param = malloc(sizeof(struct asm_ast_param));
        if((*line-start) > 4) {
            param->type = 14;
            struct asm_ast_long *longAddr = malloc(sizeof(struct asm_ast_long));
            longAddr->addr = value;
        } else {
            param->type = 11;
            struct asm_ast_absolute *absAddr = malloc(sizeof(struct asm_ast_absolute));
            absAddr->addr = value;
        }
        return param;
    } else { // Assume it's a label for now
        char *labelStart = *line;
        while(
            (**line >= 'A' && **line <= 'Z') ||
            (**line >= 'a' && **line <= 'z') ||
            (**line >= '0' && **line <= '9') ||
            **line == '$' ||
            **line == '_' ||
            **line == '.' ||
            **line == '+' ||
            **line == '-'
        ) *line++;
        **line = 0; // Null terminate
        struct asm_ast_param *param = malloc(sizeof(struct asm_ast_param));
        param->type = 19;
        struct asm_ast_label *label = malloc(sizeof(struct asm_ast_label));
        label->label = labelStart;
        return param;
    }
}

void asm_make_ast(void *_line) {
    char *line = (char*)_line;
    while(*line == ' ' || *line == '\t') line++;
    if(*line == 0) return;
    char *opStart = line;
    while(
        (*line >= 'A' && *line <= 'Z') ||
        (*line >= 'a' && *line <= 'z') ||
        (*line >= '0' && *line <= '9') ||
        *line == '$' ||
        *line == '_' ||
        *line == '.' ||
        *line == '+' ||
        *line == '-'
    ) line++;

    while(*line == ':') {
        // Label
        struct asm_ast_node_generic *node = malloc(sizeof(struct asm_ast_node_generic));
        node->type = 0;
        struct asm_ast_label *label = malloc(sizeof(struct asm_ast_label));
        *line = 0; // Nice null terminator ;)
        label->label = opStart;
        ptr_ll_add(cur_ast.nodes, node);

        // Right, now we need to reset in case there's a label or another instruction after this. Right.
        line++;
        opStart = line;
        while(
            (*line >= 'A' && *line <= 'Z') ||
            (*line >= 'a' && *line <= 'z') ||
            (*line >= '0' && *line <= '9') ||
            *line == '$' ||
            *line == '_' ||
            *line == '.' ||
            *line == '+' ||
            *line == '-'
        ) line++;
    }
    if(*opStart == '.') {
        opStart++; // Directive
        struct asm_ast_node_generic *node = malloc(sizeof(struct asm_ast_node_generic));
        node->type = 2;
        struct asm_ast_directive *directive = malloc(sizeof(struct asm_ast_directive));
        node->node = directive;
        *line = 0; // Null terminate, as always
        directive->directive = opStart;
        while(*opStart != 0) { // And now, to capitalize
            if(*opStart >= 'a') *opStart -= 'a' - 'A';
            opStart++;
        }
        // I know that plenty of directives have parameters.
        // I'm going to ignore that for now, because I don't know what they are.
        ptr_ll_add(cur_ast.nodes, node);
    } else { // Instruction
        *line = 0; // Null terminate. Of course.
        char *trueOpStart = opStart;
        while(*opStart != 0) { // And now, to capitalize. Early.
            if(*opStart >= 'a') *opStart -= 'a' - 'A';
            opStart++;
        }
        opStart = trueOpStart;
        struct asm_ast_node_generic *node = malloc(sizeof(struct asm_ast_node_generic));
        node->type = 1;
        struct asm_ast_instruction *instruction = malloc(sizeof(struct asm_ast_instruction));
        if(!strcmp("BRK", opStart)) { // Fun fact, !strcmp means they're equal.
            instruction->opcode = 0;
        } else if(!strcmp("ORA", opStart)) { // Opcodes $01, $03, $05, $07, $09, $0D, $0F, $11, $12, $13, $15, $17, $19, $1D, $1F
            
        } else if(!strcmp("COP", opStart)) {
            instruction->opcode = 2;
        } else if(!strcmp("TSB", opStart)) { // Opcodes $04, $0C
            
        } else if(!strcmp("ASL", opStart)) { // Opcodes $06, $0A, $0E, $16, $1E
            
        } else if(!strcmp("PHP", opStart)) {
            instruction->opcode = 8;
        } else if(!strcmp("PHD", opStart)) {
            instruction->opcode = 0xB;
        } else if(!strcmp("BPL", opStart)) {
            instruction->opcode = 0x10;
            struct asm_ast_param **params = malloc(1*sizeof(struct asm_ast_param)); // 1 operand
            params[0] = asm_parse_rel(&line);
            instruction->params = params;
        } else if(!strcmp("TRB", opStart)) { // Opcodes $14, $1C
            
        } else if(!strcmp("CLC", opStart)) {
            instruction->opcode = 0x18;
        } else if(!strcmp("INC", opStart)) { // Opcodes $1A, $E6, $EE, $F6, $FE
            
        } else if(!strcmp("TCS", opStart)) {
            instruction->opcode = 0x1B;
        } else if(!strcmp("JSR", opStart)) { // Opcodes $20, $FC
            
        } else if(!strcmp("AND", opStart)) { // Opcodes $21, $23, $25, $27, $29, $2D, $2F, $31, $32, $33, $35, $37, $39, $3D, $3F
            
        } else if(!strcmp("JSL", opStart)) {
            instruction->opcode = 0x22;
            struct asm_ast_param **params = malloc(1*sizeof(struct asm_ast_param)); // 1 operand
            params[0] = asm_parse_long(&line);
            instruction->params = params;
        } else if(!strcmp("BIT", opStart)) { // Opcodes $24, $2C, $34, $3C, $89
            
        } else {
            fprintf(stderr, "Error: unrecognized instruction \"%s\"!\n", opStart);
            exit(1);
        }
    }
}

char* assemble(char *filename) {
    FILE *input = fopen(filename, "r");
    struct asm_ast ast;

    struct ptr_ll *lines = cpp_readAndLineBreak(input);

    cur_ast = ast; // Excuse my horrible code; this is meant to work well enough
    ptr_ll_iter(lines, asm_make_ast);

    char *tmpname = tmpnam(NULL);
    size_t tmpnamelen = strlen(tmpname);
    char *resname = malloc(tmpnamelen+3); // +2 for .o, +1 for \0
    resname[0] = 0;
    strcpy(resname, tmpname);
    resname[tmpnamelen] = '.';
    resname[tmpnamelen+1] = 'o';
    resname[tmpnamelen+2] = 0;
    FILE *result = fopen(resname, "wb");

    printf("%s", resname);

    fclose(result);

    return resname;
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
            output[strlen(inputs.top->name)-1] = 'o'; // Replace ".c"/".s" with ".o"
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

    curNode = inputs.top;
    while(curNode != NULL) {
        if(curNode->name[strlen(curNode->name)-1] == 's') {
            curNode->name = assemble(curNode->name);
        }
        curNode = curNode->next;
    }
}
