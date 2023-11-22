#include <iostream>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"

int main()
{
	// HALF SELECTION SORT
	std::cout << "HALF SELECTION SORT" << std::endl;
	std::vector<int> unsorted_list = {64, 25, 12, 22, 11};
	std::cout << "Unsorted List:" << std::endl;
	for (const auto &element : unsorted_list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;

	int duration;
	int median = halfSelectionSort(unsorted_list, duration);
	std::cout << "Sorted List:" << std::endl;
	for (const auto &element : unsorted_list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
	std::cout << "Sorting Duration: " << duration << " microseconds"
						<< " Median: " << median << std::endl;

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
	std::cout << "MERGE SORT" << std::endl;
	unsorted_list = {64, 25, 12, 22, 11};
	std::cout << "Unsorted List:" << std::endl;
	for (const auto &element : unsorted_list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;

	median = mergeSort(unsorted_list, duration);
	std::cout << "Sorted List:" << std::endl;
	for (const auto &element : unsorted_list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
	std::cout << "Sorting Duration: " << duration << " microseconds"
						<< " Median: " << median << std::endl;

	// MERGE SORT INPLACE
	std::cout << "MERGE SORT INPLACE" << std::endl;
	unsorted_list = {64, 25, 12, 22, 11};
	std::cout << "Unsorted List:" << std::endl;
	for (const auto &element : unsorted_list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;

	median = inPlaceMergeSort(unsorted_list, duration);
	std::cout << "Sorted List:" << std::endl;
	for (const auto &element : unsorted_list)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
	std::cout << "Sorting Duration: " << duration << " microseconds"
						<< " Median: " << median << std::endl;

	// Testing


	
	std::vector<int> nums {25, 64, 12};
	std::cout << "Distance: " << std::distance(nums.begin(), nums.end()) << "\n";
  std::inplace_merge(nums.begin(), nums.begin()+2, nums.end());
  for(auto n: nums) {
    std::cout<< n << ' ';
  }
  std::cout << '\n';

	return 0;
}