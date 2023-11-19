#include "HalfSelectionSort.hpp"

int halfSelectionSort(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	if (nums.size() < 50000)
	{
		for (auto i = nums.begin(); i != nums.end() - nums.size() / 2; ++i)
		{
			auto curr_min = i;
			for (auto j = i + 1; j != nums.end(); ++j)
			{
				if(*j < *curr_min)
				{
					curr_min = j;
				}
			}
			std::swap(*i, *curr_min);
		}
	}
	else
	{
		std::cout << "Size too big" << std::endl;
	}

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

	return nums[nums.size() / 2]; //median
}
