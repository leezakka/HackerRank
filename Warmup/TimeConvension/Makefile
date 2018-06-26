CXX = g++
CXXLINK = $(CXX) -o $@

PGM = TimeConvension
all:$(PGM)

TimeConvension.o : TimeConvension.cpp
	$(CXX) -c -g TimeConvension.cpp
TimeConvension : TimeConvension.o
	$(CXXLINK) TimeConvension.o 

clean :
	rm -rf *.o $(PROGRAM)
