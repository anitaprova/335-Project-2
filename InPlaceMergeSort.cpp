#include "InPlaceMergeSort.hpp"

int inPlaceMergeSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();
	if (nums.size() <= 1)
	{
		return nums[0];
	}

	int middle = nums.size() / 2;

	inPlaceMergeSort(, duration); //left
	//inPlaceMergeSort(, duration); //right

	std::inplace_merge(nums.begin(), nums.begin() + middle, nums.end());

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

	return nums[nums.size() / 2]; // median
}
