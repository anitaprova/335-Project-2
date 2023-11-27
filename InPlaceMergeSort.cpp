#include "InPlaceMergeSort.hpp"

int inPlaceMergeSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	auto middle = nums.begin() + nums.size() / 2;
	MergeSort(nums, nums.begin(), middle);				 // left
	MergeSort(nums, middle + 1, (nums.end() - 1)); // right

	std::inplace_merge(nums.begin(), middle + 1, nums.end());

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

	if (nums.size() % 2 == 1) // odd
	{
		return nums[nums.size() / 2]; // median
	}
	else
	{
		return nums[(nums.size() - 1) / 2];
	}
}

// helper function
int MergeSort(std::vector<int> &nums, std::vector<int>::iterator l, std::vector<int>::iterator r)
{
	if (std::distance(l, r) <= 0) // only one element left
	{
		return *l;
	}

	auto middle = l + std::distance(l, r) / 2;
	MergeSort(nums, l, middle);			// left
	MergeSort(nums, middle + 1, r); // right

	std::inplace_merge(l, middle + 1, r + 1);
}