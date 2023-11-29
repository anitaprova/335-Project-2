#include <iostream>
#include <fstream>
#include <string>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
//#include "WorstCaseQuickSelect.hpp"

int main()
{
	std::vector<int> unsorted_list;
	int duration;
	int median;

	std::ifstream input1_file("inputs_and_outputs/input1.txt");
	int num;
	while (input1_file >> num)
	{
		unsorted_list.push_back(num);
	}

	std::vector<int> sorted_list;
	std::ifstream selectionsort1_file("inputs_and_outputs/heapsort1.txt");
	int num2;
	while (selectionsort1_file >> num2)
	{
		sorted_list.push_back(num2);
	}

	// HALF SELECTION SORT
	// std::cout << "HALF SELECTION SORT" << std::endl;
	// median = halfSelectionSort(unsorted_list, duration);
	// for (int i = 0; i < unsorted_list.size(); i++)
	// {
	// 	if (unsorted_list[i] != sorted_list[i])
	// 	{
	// 		std::cout << "DOES NOT WORK";
	// 		break;
	// 	}
	// }
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;
	// std::cout << "Correct Median: " << sorted_list[sorted_list.size() / 2] << std::endl;

	// // STANDARD SORT
	// std::cout << "STANDARD SORT" << std::endl;
	// median = halfSelectionSort(unsorted_list, duration);
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	// MERGE SORT
	// std::cout << "MERGE SORT" << std::endl;
	// std::vector<int> vect2;
	// std::copy(unsorted_list.begin(), unsorted_list.end(), back_inserter(vect2));
	// median = mergeSort(unsorted_list, duration);
	// std::sort(vect2.begin(), vect2.end());
	// for (int i = 0; i < unsorted_list.size(); i++)
	// {
	// 	if (unsorted_list[i] != vect2[i])
	// 	{
	// 		std::cout << "DOES NOT WORK";
	// 		break;
	// 	}
	// }

	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;
	// std::cout << "Correct Median: " << vect2[(vect2.size() - 1) / 2] << std::endl;

	// MERGE SORT INPLACE
	// std::cout << "MERGE SORT INPLACE" << std::endl;
	// std::vector<int> vect2;
	// std::copy(unsorted_list.begin(), unsorted_list.end(), back_inserter(vect2));
	// median = inPlaceMergeSort(unsorted_list, duration);
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	// std::sort(vect2.begin(), vect2.end());
	// for (int i = 0; i < unsorted_list.size(); i++)
	// {
	// 	if (unsorted_list[i] != vect2[i])
	// 	{
	// 		std::cout << "DOES NOT WORK";
	// 		break;
	// 	}
	// }

	// HEAPSORT
	std::cout << "HEAPSORT" << std::endl;
	//unsorted_list = {54, 58, 79, 70, 54, 63, 89, 69, 55, 84, 74, 75, 87};
	median = halfHeapSort(unsorted_list, duration);
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;
	
	for (int i = 0; i < unsorted_list.size(); i++)
	{
		if (unsorted_list[i] != sorted_list[i])
		{
			std::cout << "DOES NOT WORK " << i << " " << unsorted_list[i] << " " << sorted_list[i] << "\n";
			break;
		}
	}
	std::cout << "Sorting Duration: " << duration << " microseconds"
						<< " Median: " << median << std::endl;
	std::cout << "Correct Median: " << sorted_list[0] << std::endl;

	// TESTING percDown
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
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	// QUICK SELECT
	// std::cout << "QUICK SELECT" << std::endl;
	//unsorted_list = {64, 25, 12, 22, 11, 52, 5, 9, 99, 75, 13, 2, 0};
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// //Hoares Partition
	// std::cout << "hoarePartition: " << *hoarePartition(unsorted_list, unsorted_list.begin(), unsorted_list.end()-1) << " \n";
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	// median = quickSelect(unsorted_list, duration);
	// std::cout << "Sorted List:" << std::endl;
	// for (const auto &element : unsorted_list)
	// {
	// 	std::cout << element << " ";
	// }

	// for (int i = 0; i < unsorted_list.size(); i++)
	// {
	// 	if (unsorted_list[i] != sorted_list[i])
	// 	{
	// 		std::cout << "DOES NOT WORK " << i << " " << unsorted_list[i] << " " << sorted_list[i] << "\n";
	// 		break;
	// 	}
	// }

	// std::cout << std::endl;
	// std::cout << "Sorting Duration: " << duration << " microseconds"
	// 					<< " Median: " << median << std::endl;

	return 0;
}