OBJECTS = HalfSelectionSort.o StandardSort.o
CXXFLAGS = -g -c -o
LDFLAGS =
CXX = g++

main: main.o $(OBJECTS)
	g++ -g -o main main.o $(OBJECTS)

main.o: main.cpp

HalfSelectionSort.o: HalfSelectionSort.cpp HalfSelectionSort.hpp

StandardSort.o: StandardSort.cpp StandardSort.hpp

MergeSort.o: MergeSort.cpp MergeSort.hpp

clean: 
	rm main main.o $(OBJECTS)