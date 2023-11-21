#include "InPlaceMergeSort.hpp"

int inPlaceMergeSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();
	if (nums.size() <= 1)
	{
		return nums[0];
	}

	auto middle = nums.begin() + nums.size() / 2;
	MergeSort(nums, nums.begin(), middle);	 // left
	MergeSort(nums, middle + 1, nums.end()); // right

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

	return nums[nums.size() / 2]; // median
}

// helper function
int MergeSort(std::vector<int> &nums, std::vector<int>::iterator l, std::vector<int>::iterator r)
{
	if (std::distance(l, r) <= 1)
	{
		return *(l + std::distance(l, r));
	}

	auto middle = l + std::distance(l, r) / 2;

	// std::cout << "\nHERE1\n";
	// for (const auto &element : nums)
	// {
	// 	std::cout << element << " ";
	// }
	// std::cout << std::endl;

	MergeSort(nums, l, middle);			// left
	MergeSort(nums, middle + 1, r); // right

	std::inplace_merge(l, middle, r);
}