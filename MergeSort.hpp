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
 * implements merge sort recursively using std::merge
 * @param nums: reference to the vector to be sorted
 * @param duration: reference to the time taken to complete the sorting process
 * @return: median of vector
 */
int mergeSort(std::vector<int> &nums, int &duration);

/**
 * implements merge sort recursively using std::merge
 * @param nums: reference to the vector to be sorted
 * @param duration: reference to the time taken to complete the sorting process
 * @return: median of vector
 */
int mergeSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	if (nums.size() <= 1)
	{
		return nums[0];
	}

	int middle = nums.size() / 2;

	// created new vector for merging because it's not in-place
	std::vector<int> left(nums.begin(), nums.begin() + middle);
	std::vector<int> right(nums.begin() + middle, nums.end());

	mergeSort(left, duration);
	mergeSort(right, duration);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());

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
