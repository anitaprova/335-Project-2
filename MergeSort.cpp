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
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

	return nums[nums.size() / 2]; // median
}
