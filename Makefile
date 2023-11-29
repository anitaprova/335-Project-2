OBJECTS = HalfSelectionSort.o StandardSort.o MergeSort.o InPlaceMergeSort.o HalfHeapSort.o QuickSelect.o
CXXFLAGS = -g -c -o
LDFLAGS =
CXX = g++

main: main.o $(OBJECTS)
	g++ -g -o main main.o $(OBJECTS)

main.o: main.cpp

HalfSelectionSort.o: HalfSelectionSort.cpp HalfSelectionSort.hpp

StandardSort.o: StandardSort.cpp StandardSort.hpp

MergeSort.o: MergeSort.cpp MergeSort.hpp

InPlaceMergeSort.o: InPlaceMergeSort.cpp InPlaceMergeSort.hpp

HalfHeapSort.o: HalfHeapSort.cpp HalfHeapSort.hpp

QuickSelect.o: QuickSelect.cpp QuickSelect.hpp

clean: 
	rm main main.o $(OBJECTS)