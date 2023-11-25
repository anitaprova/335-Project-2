#include <iostream>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"

int main()
{
	std::vector<int> unsorted_list = {64, 25, 12, 22, 11};
	int duration;
	int median;

	// HALF SELECTION SORT
	// std::cout << "HALF SELECTION SORT" << std::endl;
	// unsorted_list = {64, 25, 12, 22, 11};
	// std::cout << "Unsorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// median = halfSelectionSort(unsorted_list, duration);
	// std::cout << "Sorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	// // STANDARD SORT
	// std::cout << "STANDARD SORT" << std::endl;
	// unsorted_list = {64, 25, 12, 22, 11};
	// std::cout << "Unsorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// median = halfSelectionSort(unsorted_list, duration);
	// std::cout << "Sorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	// MERGE SORT
	// std::cout << "MERGE SORT" << std::endl;
	// unsorted_list = {64, 25, 12, 22, 11};
	// std::cout << "Unsorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// median = mergeSort(unsorted_list, duration);
	// std::cout << "Sorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	// // MERGE SORT INPLACE
	// std::cout << "MERGE SORT" << std::endl;
	// unsorted_list = {64, 25, 12, 22, 11};
	// std::cout << "Unsorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// median = inPlaceMergeSort(unsorted_list, duration);
	// std::cout << "Sorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	// HEAPSORT
	// std::cout << "HEAPSORT" << std::endl;
	// unsorted_list = {25, 5, 32, 11, 10, 9};
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// // TESTING percDown
	// percDown(unsorted_list, 0);
	// std::cout << "Perc Down: \n";
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// TESTING BUILDHEAP
	// buildHeap(unsorted_list);
	// std::cout << "Building Heap: \n";
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// std::cout << "HEAP SORT\nUnsorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// median = halfHeapSort(unsorted_list, duration);
	// std::cout << "Sorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	// QUICK SELECT
	std::cout << "QUICK SELECT" << std::endl;
	unsorted_list = {64, 25, 12, 22, 11};
	std::cout << "Unsorted List:" << std::endl;
	for (const auto &element : unsorted_list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;

	hoarePartition(unsorted_list, unsorted_list.begin(), unsorted_list.end());
	std::cout << "hoarePartition: \n";
	for (const auto &element : unsorted_list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;

	// median = quickSelect(unsorted_list, duration);
	// std::cout << "Sorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	return 0;
}