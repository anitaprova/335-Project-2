#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> worstCaseQuickSelect(void);
int worstCaseQuickSelect(std::vector<int> &nums);
void worstCaseQuickSelect(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator k);
std::vector<int>::iterator worstCaseHoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
std::vector<int>::iterator worstCaseMedian3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);

/**
 * generates vector for worstcase of quickselect
 * @return: vector of size 20,000
 */
std::vector<int> worstCaseQuickSelect(void)
{
	std::vector<int> v;
	for (int i = 20000; i >= 1; i--)
	{
		v.push_back(i);
	}

	return v;
}

/**
 * implements worstCaseQuickSelect algorithm
 * @param nums: reference to the vector to be sorted
 * @param duration: reference to the time taken to complete the sorting process
 * @return: median of vector
 */
int worstCaseQuickSelect(std::vector<int> &nums)
{
	std::vector<int>::iterator middle = nums.begin() + (nums.size() - 1) / 2;

	worstCaseQuickSelect(nums, nums.begin(), nums.end() - 1, middle);

	return *middle;
}

/**
 * helper function for worstCaseQuickSelect
 * @param low: iterator to beginning of vector to be sorted
 * @param high: iterator to end of vector to be sorted
 */
void worstCaseQuickSelect(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator k)
{
	// base case
	if (high < low + 10)
	{
		std::sort(low, high + 1);
	}
	else
	{
		std::vector<int>::iterator i = worstCaseHoarePartition(nums, low, high);
		if (i <= k)
		{
			worstCaseQuickSelect(nums, i + 1, high, k);
		}
		else
		{
			worstCaseQuickSelect(nums, low, i - 1, k);
		}
	}
}

/**
 * partitions the subarray using Hoare's partition algorithm
 * @param nums: reference to the vector to be sorted.
 * @param low: iterator pointing to the first element in the subarray
 * @param high: iterator pointing to the last element in the subarray
 * @return: iterator to pivot
 */
std::vector<int>::iterator worstCaseHoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	std::vector<int>::iterator pivot = worstCaseMedian3(nums, low, high);
	std::vector<int>::iterator i = low;
	std::vector<int>::iterator j = pivot - 1; // need the -1 because the pivot is already in the back

	for (;;)
	{
		while (i < pivot && *i < *pivot)
		{
			++i;
		}
		while (j > low && *j > *pivot)
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
	std::iter_swap(i, pivot); // put pivot back in proper place

	return i;
}

/**
 * gets worst median using modified median-of-three algorithm
 * @param nums: reference to the vector to be sorted.
 * @param low: iterator pointing to the first element in the subarray
 * @param high: iterator pointing to the last element in the subarray
 * @return: iterator to pivot
 */
std::vector<int>::iterator worstCaseMedian3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	std::vector<int>::iterator mid = low + ((high - low) / 2);

	if (*low == *mid && *low == *high) // all three are the same
	{
		std::iter_swap(low, high);
	}
	else if (*low == *mid || *low == *high) // low and middle are the same or low and high are the same
	{
		std::iter_swap(low, high);
	}
	else if (*mid == *high) // if middle and high share the same value
	{
		std::iter_swap(mid, high);
	}
	else // all the values are different now
	{
		// descending order
		if (*high < *mid && *mid < *low)
		{
			std::iter_swap(low, high);
		}

		// ascending order
		if (*low < *mid && *mid < *high)
		{
			std::iter_swap(low, mid);
		}

		if (*low<*mid && * mid> * high)
		{
			std::iter_swap(mid, high);
		}
	}

	// we need to pick the worst pivot
	// after swapping high should hold the worst pivot which is the largest number
	return high;
}