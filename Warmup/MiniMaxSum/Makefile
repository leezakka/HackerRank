CXX = g++
CXXLINK = $(CXX) -o $@

PGM = MiniMaxSum
all:$(PGM)

MiniMaxSum.o : MiniMaxSum.cpp
	$(CXX) -c -g MiniMaxSum.cpp
MiniMaxSum : MiniMaxSum.o
	$(CXXLINK) MiniMaxSum.o 

clean :
	rm -rf *.o $(PROGRAM)
