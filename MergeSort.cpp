#include "MergeSort.hpp"

int mergeSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	if (nums.size() <= 1)
	{
		return nums[0];
	}

	int middle = nums.size() / 2;
	std::vector<int> left(nums.begin(), nums.begin() + middle);
	std::vector<int> right(nums.begin() + middle, nums.end());

	mergeSort(left, duration);
	mergeSort(right, duration);

	std::merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

	if (nums.size() % 2 == 1) // odd
	{
		return nums[nums.size() / 2]; // median
	}
	else 
	{
		return nums[(nums.size()-1) / 2];
	}
}
