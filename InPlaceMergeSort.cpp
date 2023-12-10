#include "InPlaceMergeSort.hpp"

int inPlaceMergeSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	auto middle = nums.begin() + nums.size() / 2;
	MergeSort(nums, nums.begin(), middle);				 // left
	MergeSort(nums, middle + 1, (nums.end() - 1)); // right

	std::inplace_merge(nums.begin(), middle + 1, nums.end());

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

// helper function for MergeSort
int MergeSort(std::vector<int> &nums, std::vector<int>::iterator l, std::vector<int>::iterator r)
{
	// base case where there is only one element left
	if (std::distance(l, r) <= 0)
	{
		return *l;
	}

	auto middle = l + std::distance(l, r) / 2;
	MergeSort(nums, l, middle);			// spilts into left of middle
	MergeSort(nums, middle + 1, r); // rspilts into ight of middle

	std::inplace_merge(l, middle + 1, r + 1);
}