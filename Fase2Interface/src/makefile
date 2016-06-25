CXX = g++
IDIR = ../include
CXXFLAGS = -I$(IDIR)

ODIR = ../obj
LDIR = ../lib

LIBS = -lm -lgtest -lpthread -lgtest_main -lncurses

_DEPS = grafo.h grafo_priv.h
DEPS = $(patsubst%,$(IDIR)/%,$(_DEPS))

_OBJ = grafo.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default_target: interface teste_grafo

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
interface: $(OBJ) $(ODIR)/interface.o
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS)

	
teste_grafo: $(OBJ) $(ODIR)/teste_grafo.o
	g++ -o $@ $^ $(CXXFLAGS) $(LIBS)

.PHONY: clean doc

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

	
doc:
	# Target para Linux
	SRCDIR=$(shell pwd) doxygen ./doxygen_log.txt
	make -C latex
	cp latex/refman.pdf documentacao.pdf
