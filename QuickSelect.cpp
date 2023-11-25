#include "QuickSelect.hpp"

int quickSelect(std::vector<int> &nums, int &duration)
{

	hoarePartition(nums, nums.begin(), nums.end());
	
	return nums[nums.size() / 2]; //median
}

void hoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
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
			break;
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
