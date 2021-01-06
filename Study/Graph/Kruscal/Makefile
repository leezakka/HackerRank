CXX = g++
CXXLINK = $(CXX) -o $@

PGM = kruscal
all:$(PGM)

kruscal.o : kruscal.cpp
	$(CXX) -c -g kruscal.cpp
kruscal : kruscal.o
	$(CXXLINK) kruscal.o 

clean :
	rm -rf *.o $(PROGRAM)
