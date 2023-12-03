#include "WorstCaseQuickSelect.hpp"
#include "QuickSelect.hpp"

std::vector<int> &worstCaseQuickSelect(void)
{
	std::vector<int> v;

	for (int i = 0; i < 20000; i++)
	{
		v.push_back(i);
	}

	int duration;
	quickSelect(v, duration);

	return v;
}

int worstCaseQuickSelect(std::vector<int> &nums, int &duration)
{
	auto start_time = std::chrono::high_resolution_clock::now();

	std::vector<int>::iterator middle = nums.begin() + std::distance(nums.begin(), nums.end() - 1) / 2;
	worstCaseQuickSelect(nums, nums.begin(), nums.end() - 1, middle);

	auto end_time = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

	return *(middle);
}

void worstCaseQuickSelect(std::vector<int> &nums, std::vector<int>::iterator left, std::vector<int>::iterator right, std::vector<int>::iterator k)
{
	if (left + 10 <= right)
	{
		std::vector<int>::iterator pivot = worstCaseQuickSelectMedian3(nums, left, right);
		std::iter_swap(pivot, right - 1);
		std::vector<int>::iterator i = worstCaseHoarePartition(nums, left, right);
		std::iter_swap(i, right);

		if (k < i)
		{
			quickSelect(nums, left, i - 1, k);
		}
		else if (k > i + 1)
		{
			quickSelect(nums, i + 1, right, k);
		}
	}
	else
	{
		std::sort(left, right);
	}
}

std::vector<int>::iterator worstCaseHoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	std::vector<int>::iterator pivot = high; // should be in the back of the vector
	std::vector<int>::iterator i = low;
	std::vector<int>::iterator j = high - 1; // need the -1 because the pivot is already in the back

	for (;;)
	{
		while (*i <= *pivot)
		{
			++i;
		}
		while (*pivot <= *j)
		{
			--j;
		}
		if (i < j)
		{
			std::iter_swap(i, j);
		}
		else
		{
			break;
		}
	}
	return i;
}

// will modify the following so that it will pick the worst pivot out of the three
std::vector<int>::iterator worstCaseQuickSelectMedian3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	std::vector<int>::iterator mid = low + (high - low) / 2;

	if (*low > *mid)
	{
		std::iter_swap(low, mid);
	}

	if (*low > *high)
	{
		std::iter_swap(low, high);
	}

	if (*mid > *high)
	{
		std::iter_swap(mid, high);
	}

	//we want the worst pivot so either low or high 
	return high;
}