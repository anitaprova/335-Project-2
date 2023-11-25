#include "QuickSelect.hpp"

int quickSelect(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	quickSelect(nums, nums.begin(), nums.end());

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

	return nums[nums.size() / 2]; // median
}

int quickSelect(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	if (std::distance(low, high) <= 10)
	{
		std::sort(nums.begin(), nums.begin() + 10);
		return *(low + (std::distance(low, high)) / 2);
	}

	// kth smallest element which is the median or middle element
	auto k = nums.begin() + nums.size() / 2;
	auto pivot = hoarePartition(nums, low, high);
	if (k == pivot)
	{
		return *k;
	}
	else if (k < pivot)
	{
		quickSelect(nums, pivot + 1, high);
	}
	else
	{
		quickSelect(nums, low, pivot - 1);
	}
}

std::vector<int>::iterator hoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	int pivot = median3(nums, low, high);
	auto i = low - 1;
	auto j = high - 1; // not the last element because its the pivot

	while (true)
	{
		do
		{
			++i;
		} while (*i < pivot);

		do
		{
			--j;
		} while (*j > pivot);

		if (i >= j)
		{
			iter_swap(i, high - 1); // move pivot in proper location
			return i; // returns iterator to pivot 
		}

		iter_swap(i, j);
	}
}

// swap last element with pivot and return pivot
int median3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	int right = *low;
	int left = *(high - 1);
	int center = *(low + nums.size() / 2);

	if (left < center)
	{
		if (center < right)
		{
			iter_swap(low + nums.size() / 2, high - 1);
			return center;
		}
		else if (left < right)
		{
			iter_swap(low, high - 1);
			return right;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (left < right)
		{
			return left;
		}
		else if (center < right)
		{
			iter_swap(low, high - 1);
			return right;
		}
		else
		{
			iter_swap(low + nums.size() / 2, high - 1);
			return center;
		}
	}
}
