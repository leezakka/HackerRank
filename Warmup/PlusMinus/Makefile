CXX = g++
CXXLINK = $(CXX) -o $@

PGM = PlusMinus
all:$(PGM)

PlusMinus.o : PlusMinus.cpp
	$(CXX) -c -g PlusMinus.cpp
PlusMinus : PlusMinus.o
	$(CXXLINK) PlusMinus.o 

clean :
	rm -rf *.o $(PROGRAM)
