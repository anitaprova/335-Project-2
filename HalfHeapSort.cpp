#include "HalfHeapSort.hpp"

int halfHeapSort(std::vector<int> &nums, int &duration)
{
   builHeap(nums);
   
}

void percDown(std::vector<int> &heap, std::vector<int>::size_type hole)
{
}

// parameter "hole" is the index of the hole.
// percDown precondition: value to be inserted into hole is stored in heap at index 0. The hole itself may be in an unspecified state - i.e. it doesn't matter what's in it since you'll be overwriting it anyway.
// percDown postcondition: hole has been moved into correct place and value has been inserted into hole.
void builHeap(std::vector<int> &heap)
{
   for (int i = heap.size() / 2 - 1; i >= 0; --i)
   {
      percDown(heap, i);
   }
}