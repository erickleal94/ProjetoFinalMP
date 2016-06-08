GTEST_DIR=../googletest

CXX=g++
IDIR=../include
C_FLAGS= -lm -g -Wall -O2 -I$(IDIR) -isystem $(GTEST_DIR)/include -pthread -lgtest

ODIR=../obj
LDIR=../lib

_DEPS= grafo.h
DEPS= $(patsubst %,$(IDIR)/%, $(_DEPS))

_OBJ= grafo.o teste_grafo.o
OBJ= $(patsubst %,$(ODIR)/%, $(_OBJ)) 

all: teste_grafo

$(ODIR)/%.o: %.c $(DEPS)
	$(CXX) $(C_FLAGS) -c -o $@ $<

teste_grafo: $(OBJ)
	$(CXX) $(C_FLAGS) -o $@ $^
#	g++ -std=gnu++14 -Wall -isystem ${GTEST_DIR}/include -pthread ${GTEST_DIR}/googlemock/libgmock.so ${GTEST_DIR}/googlemock/gtest/libgtest.so -pthread -o teste_grafo teste_grafo.c

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ teste_grafo
