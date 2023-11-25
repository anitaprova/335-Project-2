#include "StandardSort.hpp"

int standardSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	std::sort(nums.begin(), nums.end());
	
	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
	
	return nums[nums.size() / 2];
}
