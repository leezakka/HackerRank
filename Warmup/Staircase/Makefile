CXX = g++
CXXLINK = $(CXX) -o $@

PGM = Staircase
all:$(PGM)

Staircase.o : Staircase.cpp
	$(CXX) -c -g Staircase.cpp
Staircase : Staircase.o
	$(CXXLINK) Staircase.o 

clean :
	rm -rf *.o $(PROGRAM)
