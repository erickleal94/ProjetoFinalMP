CXX = g++
IDIR = ../include
CXXFLAGS = -I$(IDIR)

ODIR = ../obj
LDIR = ../lib

LIBS = -lm -lgtest -lpthread -lgtest_main -lncurses

_DEPS = estruturas.h
DEPS = $(patsubst%,$(IDIR)/%,$(_DEPS))

_OBJ = main.o logica.o grafo.o lista.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default_target: grafo

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
grafo: $(OBJ)
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS)
	
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
