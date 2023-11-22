#include "HalfHeapSort.hpp"

int halfHeapSort(std::vector<int> &nums, int &duration)
{
   auto start_time = std::chrono::high_resolution_clock::now();

   buildHeap(nums);
   int size = nums.size();
   for (int j = nums.size() - 1; j > size / 2; --j)
   {
      std::swap(nums[0], nums[j]);
      nums.pop_back();
      percDown(nums, 0);
   }

   auto end_time = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

   return nums[0];
}

void percDown(std::vector<int> &heap, std::vector<int>::size_type hole)
{
   auto temp = std::move(heap[hole]);
   int child;

   for (; hole * 2 + 1 < heap.size() - 1; hole = child)
   {
      child = 2 * hole + 1;
      if (child != heap.size() && heap[child] < heap[child + 1])
      {
         ++child;
      }
      if (temp < heap[child])
      {
         heap[hole] = std::move(heap[child]);
      }
      else
      {
         break;
      }
   }
   heap[hole] = std::move(temp);
}

void buildHeap(std::vector<int> &heap)
{
   for (int i = heap.size() / 2 - 1; i >= 0; --i)
   {
      percDown(heap, i);
   }
}