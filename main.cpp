#include <iostream>
#include <fstream>
#include <string>
#include "HalfSelectionSort.hpp"
#include "StandardSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"

int main()
{
	int duration;
	int median;
	int num;

	std::vector<int> input1;
	std::ifstream input1_file("inputs_and_outputs/input1.txt");
	while (input1_file >> num)
	{
		input1.push_back(num);
	}

	std::vector<int> input2;
	std::ifstream input2_file("inputs_and_outputs/input2.txt");
	while (input2_file >> num)
	{
		input2.push_back(num);
	}

	std::vector<int> input3;
	std::ifstream input3_file("inputs_and_outputs/input3.txt");
	while (input3_file >> num)
	{
		input3.push_back(num);
	}

	std::vector<int> input4;
	std::ifstream input4_file("inputs_and_outputs/input4.txt");
	while (input4_file >> num)
	{
		input4.push_back(num);
	}

	std::vector<int> input5;
	std::ifstream input5_file("inputs_and_outputs/input5.txt");
	while (input5_file >> num)
	{
		input5.push_back(num);
	}

	std::vector<int> input6;
	std::ifstream input6_file("inputs_and_outputs/input6.txt");
	while (input6_file >> num)
	{
		input6.push_back(num);
	}

	std::vector<int> input7;
	std::ifstream input7_file("inputs_and_outputs/input7.txt");
	while (input7_file >> num)
	{
		input7.push_back(num);
	}

	std::vector<int> input8;
	std::ifstream input8_file("inputs_and_outputs/input8.txt");
	while (input8_file >> num)
	{
		input8.push_back(num);
	}

	std::vector<int> input9;
	std::ifstream input9_file("inputs_and_outputs/input9.txt");
	while (input9_file >> num)
	{
		input9.push_back(num);
	}

	std::vector<int> sorted_list;
	std::ifstream selectionsort1_file("inputs_and_outputs/quickselect1.txt");
	while (selectionsort1_file >> num)
	{
		sorted_list.push_back(num);
	}

	//The following was used for testing for the report

	// HALF SELECTION SORT
	// std::cout << "HALF SELECTION SORT" << std::endl;
	// median = halfSelectionSort(input7, duration);
	// std::cout << "Sorting Duration: " << duration << " milliseconds"
	// 					<< " Median: " << median << std::endl;

	// // STANDARD SORT
	// std::cout << "STANDARD SORT" << std::endl;
	// median = standardSort(input9, duration);
	// std::cout << "Sorting Duration: " << duration << " milliseconds"
	// 					<< " Median: " << median << std::endl;

	// MERGE SORT
	// std::cout << "MERGE SORT" << std::endl;
	// median = mergeSort(input1, duration);
	// std::cout << "Sorting Duration: " << duration << " milliseconds"
	//  					<< " Median: " << median << std::endl;

	// MERGE SORT INPLACE
	// std::cout << "MERGE SORT INPLACE" << std::endl;
	// median = inPlaceMergeSort(input1, duration);
	// std::cout << "Sorting Duration: " << duration << " milliseconds"
	// 					<< " Median: " << median << std::endl;

	// HEAPSORT
	// std::cout << "HEAPSORT" << std::endl;
	// median = halfHeapSort(input1, duration);
	// std::cout << "Sorting Duration: " << duration << " milliseconds"
	// 					<< " Median: " << median << std::endl;

	// QUICK SELECT
	// std::cout << "QUICK SELECT" << std::endl;
	// median = quickSelect(input9, duration);
	// std::cout << std::endl;
	// std::cout << "Sorting Duration: " << duration << " milliseconds"
	// 					<< " Median: " << median << std::endl;

	//WORST CASE QUICKSELECT
	// std::cout << "WORST CASE QUICK SELECT" << std::endl;
	// auto start_time = std::chrono::high_resolution_clock::now();

	// std::vector<int> worstCase = worstCaseQuickSelect();
	// worstCaseQuickSelect(worstCase);

	// auto end_time = std::chrono::high_resolution_clock::now();
  // duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

	// std::cout << "Sorting Duration: " << duration << " milliseconds" << std::endl;

	return 0;
}