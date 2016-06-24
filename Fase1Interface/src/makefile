CXX = gcc
IDIR = ../include
CXXFLAGS = -I$(IDIR)

ODIR = ../obj
LDIR = ../lib

LIBS = -lm -lgtest -lpthread -lgtest_main -lncurses

_DEPS = grafo.h grafo_priv.h
DEPS = $(patsubst%,$(IDIR)/%,$(_DEPS))

_OBJ = grafo.o interface.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default_target: interface

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
teste: $(OBJ)
	gcc -o $@ $^ $(CXXFLAGS) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
