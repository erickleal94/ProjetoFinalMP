CXX = g++
IDIR = ../include
CXXFLAGS = -I$(IDIR)

ODIR = ../obj
LDIR = ../lib

GTEST_DIR = ../../../MP_trab3/googletest
LIBS = -Wall -g -lm -lgtest -pthread -lgtest_main -lncurses -isystem $(GTEST_DIR)/include

_DEPS = grafo.h grafo_priv.h
DEPS = $(patsubst%,$(IDIR)/%,$(_DEPS))

_OBJ = grafo.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

default_target: interface teste_grafo

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(LIBS)
	
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
