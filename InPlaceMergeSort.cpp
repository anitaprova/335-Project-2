#include "InPlaceMergeSort.hpp"

int inPlaceMergeSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();
	if (nums.size() <= 1)
	{
		return nums[0];
	}

	auto middle = nums.begin() + nums.size() / 2;

	// std::cout << "Begin: " << *nums.begin() << "\n";
	// std::cout << "Middle: " << *middle << "\n";
	// std::cout << "End: " << *(nums.end() - 1) << "\n";

	MergeSort(nums, nums.begin(), middle);	 // left
	MergeSort(nums, middle + 1, (nums.end() - 1)); // right

	std::inplace_merge(nums.begin(), middle, nums.end());

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

	return nums[nums.size() / 2]; // median
}

// helper function
int MergeSort(std::vector<int> &nums, std::vector<int>::iterator l, std::vector<int>::iterator r)
{
	if (std::distance(l, r) <= 1) //only one element left 
	{
		return *l;
	}

	auto middle = l + (std::distance(l, r) + 1) / 2;
	std::cout << "Distance: " << std::distance(l, r) << "\n";
	std::cout << "Left: " << *l << " Middle: " << *middle << " Right: " << *r << "\n";
	MergeSort(nums, l, middle);	// left
	MergeSort(nums, middle, r); // right

	std::inplace_merge(l, middle, r);

	std::cout << std::endl;
}