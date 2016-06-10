CXX = gcc
IDIR = ../include
CXXFLAGS = -I$(IDIR)

ODIR = ../obj
LDIR = ../lib

LIBS = -lm -lgtest -lpthread -lgtest_main -lncurses

_DEPS = grafo.h
DEPS = $(patsubst%,$(IDIR)/%,$(_DEPS))

_OBJ = teste.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default_target: teste

$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
teste: $(OBJ)
	gcc -o $@ $^ $(CXXFLAGS) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
