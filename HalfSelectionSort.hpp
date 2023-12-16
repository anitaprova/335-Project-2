/*
CSCI335 Fall 2023
Assignment 2
Name Anita Prova
Date 12/15/23
*/

#include <iostream>
#include <vector>
#include <chrono>

/**
 * sorts the vector halfway using modified selectionsort algorithm in order to obtain median
 * @param nums: reference to the vector to be sorted
 * @param duration: reference to the time taken to complete the sorting process
 * @return: median of vector
 */
int halfSelectionSort ( std::vector<int>& nums, int& duration);

/**
 * sorts the vector halfway using modified selectionsort algorithm in order to obtain median
 * @param nums: reference to the vector to be sorted
 * @param duration: reference to the time taken to complete the sorting process
 * @return: median of vector
 */
int halfSelectionSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	if (nums.size() < 50000)
	{
		for (auto i = nums.begin(); i != nums.end() - nums.size() / 2; ++i)
		{
			auto curr_min = i;
			for (auto j = i + 1; j != nums.end(); ++j)
			{
				if (*j < *curr_min)
				{
					curr_min = j;
				}
			}
			std::swap(*i, *curr_min);
		}
	}
	else
	{
		std::cout << "Size too big" << std::endl;
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

	// gives median depending on whether list is even or odd
	if (nums.size() % 2 == 1)
	{
		return nums[nums.size() / 2];
	}
	else
	{
		return nums[(nums.size() - 1) / 2];
	}
}
