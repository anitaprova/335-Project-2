#include "QuickSelect.hpp"

int quickSelect(std::vector<int> &nums, int &duration)
{
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<int>::iterator left = nums.begin();
    std::vector<int>::iterator right = nums.end() - 1;
    std::vector<int>::iterator middle = nums.begin() + (std::distance(left, right) / 2);

    quickSelect(nums, left, right, middle);

    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    //return *(middle);
    if (nums.size() % 2 == 1) // odd
	{
		return *(middle); // median
	}
	else
	{
		return *(middle - 1);
	}
}

void quickSelect(std::vector<int> &nums, std::vector<int>::iterator left, std::vector<int>::iterator right, std::vector<int>::iterator k)
{
    if (left + 10 <= right)
    {
        std::vector<int>::iterator pivot = median3(nums, left, right); //get median

        std::cout << "PIVOT: " << *pivot << "    INDEX: " << std::distance(nums.begin(),pivot) << "\n";

        std::iter_swap(pivot, right - 1); //swap pivot with last element

        std::vector<int>::iterator i = hoarePartition(nums, left, right-1); //returns where the pivot is
        std::iter_swap(i, right-1); //restores pivot


        if (k <= i)
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

std::vector<int>::iterator hoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    std::vector<int>::iterator pivot = high; // should be in the back of the vector
    std::vector<int>::iterator i = low;
    std::vector<int>::iterator j = high; // need the -1 because the pivot is already in the back

    for (; ;)
    {
        while (*(++i) < *pivot)
        {   
        }
        while (*pivot < *(--j))
        {
        }
        if (std::distance(i, j) <= 0)
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

std::vector<int>::iterator median3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
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

    return mid;
}