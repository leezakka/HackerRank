CXX = g++-4.9 -std=c++11
CXXLINK = $(CXX) -o $@
INC = -I/mnt/d/Dropbox/Workspace/

PGM = ArrayManipulation
all:$(PGM)

ArrayManipulation.o : ArrayManipulation.cpp
	$(CXX) -c -g $(INC) ArrayManipulation.cpp
ArrayManipulation : ArrayManipulation.o
	$(CXXLINK) ArrayManipulation.o 

clean :
	rm -rf *.o $(PGM)
