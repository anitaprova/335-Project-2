#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int quickSelect(std::vector<int> &nums, int &duration);
void quickSelect(std::vector<int> &nums, std::vector<int>::iterator high, std::vector<int>::iterator low, std::vector<int>::iterator k);
std::vector<int>::iterator hoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
std::vector<int>::iterator median3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);

/**
 * implements quickselect algorithm using the median-of-3 pivot selection
 * @param nums: reference to the vector to be sorted
 * @param duration: reference to the time taken to complete the sorting process
 * @return: median of vector
 */
int quickSelect(std::vector<int> &nums, int &duration)
{
	auto start = std::chrono::steady_clock::now();

	std::vector<int>::iterator middle = nums.begin() + (nums.size() - 1) / 2;
	quickSelect(nums, nums.begin(), nums.end() - 1, nums.begin() + (nums.size() - 1) / 2);

	auto end = std::chrono::steady_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

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

/**
 * helper function for quickselect
 * @param low: iterator to beginning of vector to be sorted
 * @param high: iterator to end of vector to be sorted
 */
void quickSelect(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator k)
{
	// base case
	if (high < low + 10)
	{
		std::sort(low, high + 1);
		
		return;
	}
	else
	{
		std::vector<int>::iterator i = hoarePartition(nums, low, high);
		if(i == k)
		{
			return;
		}
		else if (i < k)
		{
			quickSelect(nums, i + 1, high, k);
		}
		else
		{
			quickSelect(nums, low, i - 1, k);
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
std::vector<int>::iterator hoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	std::vector<int>::iterator pivot = median3(nums, low, high);
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

		if (i >= j)
		{
			break;
		}
		std::iter_swap(i, j);
		++i;
		--j;
	}
	std::iter_swap(i, pivot); // put pivot back in proper place

	return i;
}

/**
 * gets median using median-of-three algorithm
 * @param nums: reference to the vector to be sorted
 * @param low: iterator pointing to the first element in the subarray
 * @param high: iterator pointing to the last element in the subarray
 * @return: iterator to pivot
 */
std::vector<int>::iterator median3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
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
		// already in correct order
		if ((*low < *mid && *mid < *high))
		{
			// middle holds the pivot so we move to the back
			std::iter_swap(mid, high);
		}

		if (*high < *mid && *mid < *low)
		{
			std::iter_swap(low, high);
			std::iter_swap(mid, low);
		}

		// pivot is in low
		if ((*mid < *low && *low < *high) || (*high < *low && *low < *mid))
		{
			std::iter_swap(low, high);
		}
	}

	return high;
}