CXX = g++
CXXLINK = $(CXX) -o $@

PGM = DiagonalDifference
all:$(PGM)

DiagonalDifference.o : DiagonalDifference.cpp
	$(CXX) -c -g DiagonalDifference.cpp
DiagonalDifference : DiagonalDifference.o
	$(CXXLINK) DiagonalDifference.o 

clean :
	rm -rf *.o $(PROGRAM)
