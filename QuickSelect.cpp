#include "QuickSelect.hpp"

int quickSelect(std::vector<int> &nums, int &duration)
{
    auto start = std::chrono::steady_clock::now();

    std::vector<int>::iterator middle = nums.begin() + (nums.size() - 1) / 2;

    quickSelect(nums, nums.begin(), nums.end() - 1, middle);

    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return *middle; // returning the middle element as the pivot
}

void quickSelect(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator k)
{
    // base case
    if (high < low + 10)
    {
        std::sort(low, high + 1);
    }
    else
    {
        std::vector<int>::iterator i = hoarePartition(nums, low, high);
        if (i <= k)
        {
            quickSelect(nums, i + 1, high, k);
        }
        else
        {
            quickSelect(nums, low, i - 1, k);
        }
    }
}

std::vector<int>::iterator hoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high)
{
    std::vector<int>::iterator pivot = median3(nums, low, high); // return the pivot iterator, which is at high - 1
    std::vector<int>::iterator i = low;
    std::vector<int>::iterator j = pivot - 1; // high is the position of pivot, and high - 1 will be the right start of our partitioning

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

        // pivot in low
        if ((*mid < *low && *low < *high) || (*high < *low && *low < *mid))
        {
            std::iter_swap(low, high);
        }
    }

    return high;
}