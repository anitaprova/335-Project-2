OBJECTS = HalfSelectionSort.hpp StandardSort.hpp MergeSort.hpp InPlaceMergeSort.hpp HalfHeapSort.hpp QuickSelect.hpp WorstCaseQuickSelect.hpp
CXXFLAGS = -g -c -o
LDFLAGS =
CXX = g++

main: main.o $(OBJECTS)
	g++ -g -o main main.o $(OBJECTS)

main.o: main.cpp HalfSelectionSort.hpp StandardSort.hpp MergeSort.hpp InPlaceMergeSort.hpp HalfHeapSort.hpp QuickSelect.hpp WorstCaseQuickSelect.hpp

clean: 
	rm main main.o