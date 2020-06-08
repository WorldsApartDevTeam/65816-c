IDIR =./headers
CC=gcc.exe
YY=bison.exe
LX=flex.exe
CFLAGS=-I$(IDIR) -I$(ADIR) -std=gnu99 -Wall -Wno-unused-function -Wno-unused-variable

ODIR=./obj
ADIR=./autogen
DIR =./src


_DEPS = ast.h eval.h free.h typelist.h cpp.h ll.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = parser.o lexer.o main.o ast.o evalfunc.o evalstmt.o evalexpr.o free.o typelist.o cpp.o ll.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_ADEPS = parser.o
ADEPS = $(patsubst %,$(ADIR)/%,$(_ADEPS))

$(ADIR)/%.c: $(DIR)/%.y 
	$(YY) --defines -o $@ $<
	
$(ADIR)/%.c: $(DIR)/%.l
	$(LX) -o $@ $<

$(ODIR)/%.o: $(ADIR)/%.c $(DEPS) $(ADEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(DIR)/%.c $(DEPS) $(ADEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compiler: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
