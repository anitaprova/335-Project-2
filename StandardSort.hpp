/*
CSCI335 Fall 2023
Assignment 2
Name Anita Prova
Date 12/15/23
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

/**
 * uses c++ standard sort to sort the vector
 * @param nums: reference to the vector to be sorted.
 * @param duration: reference to the time taken to complete the sorting process
 * @return: median of vector
 */
int standardSort (std::vector<int>& nums, int& duration);

/**
 * uses c++ standard sort to sort the vector
 * @param nums: reference to the vector to be sorted.
 * @param duration: reference to the time taken to complete the sorting process
 * @return: median of vector
 */
int standardSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	std::sort(nums.begin(), nums.end());

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
