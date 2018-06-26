CXX = g++
CXXLINK = $(CXX) -o $@

PGM = ExtraLongFactorials
all:$(PGM)

ExtraLongFactorials.o : ExtraLongFactorials.cpp
	$(CXX) -c -g ExtraLongFactorials.cpp
ExtraLongFactorials : ExtraLongFactorials.o
	$(CXXLINK) ExtraLongFactorials.o 

clean :
	rm -rf *.o $(PGM)
