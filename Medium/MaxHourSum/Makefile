CXX = g++-4.9
CXXLINK = $(CXX) -o $@

PGM = MaxHourSum
all:$(PGM)

MaxHourSum.o : MaxHourSum.cpp
	$(CXX) -c -g MaxHourSum.cpp
MaxHourSum : MaxHourSum.o
	$(CXXLINK) MaxHourSum.o 

clean :
	rm -rf *.o $(PGM)
