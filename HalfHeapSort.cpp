#include "HalfHeapSort.hpp"

int halfHeapSort(std::vector<int> &nums, int &duration)
{
   auto start_time = std::chrono::high_resolution_clock::now();
   nums.push_back(nums[0]);
   buildHeap(nums);

   // delete min
   // moving first element to back so theres a 'hole'
   int middle = (nums.size() - 2) / 2;
   for (int j = 0; j < middle; ++j)
   {
      nums[0] = nums[nums.size() - 1];
      nums.pop_back();
      percDown(nums, 1);
   }

   auto end_time = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

   return nums[0];
}

void percDown(std::vector<int> &heap, std::vector<int>::size_type hole)
{
   int temp = heap[0];
   int child;

   for (; hole * 2 < heap.size(); hole = child)
   {
      child = hole * 2;
      if (child + 1 < heap.size() && heap[child + 1] < heap[child])
      {
         ++child;
      }

      if (temp > heap[child])
      {
         heap[hole] = heap[child];
      }
      else
      {
         break;
      }
   }
   heap[hole] = temp;
}

void buildHeap(std::vector<int> &heap)
{
   for (int i = (heap.size() - 1) / 2; i > 0; --i)
   {
      heap[0] = heap[i];
      percDown(heap, i);
   }
}