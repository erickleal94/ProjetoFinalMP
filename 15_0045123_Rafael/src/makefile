CXX = g++
IDIR = ../include
CXXFLAGS = -I$(IDIR)

ODIR = ../obj
LDIR = ../lib

LIBS = -lm -lgtest -lpthread -lgtest_main

_DEPS = grafo.h
DEPS = $(patsubst%,$(IDIR)/%,$(_DEPS))

_OBJ = grafo.o teste_grafo.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default_target: grafo

$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
grafo: $(OBJ)
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
