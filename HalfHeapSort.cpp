#include "HalfHeapSort.hpp"

int halfHeapSort(std::vector<int> &nums, int &duration)
{
   auto start_time = std::chrono::high_resolution_clock::now();
   
   nums.push_back(std::move(nums[0]));
   buildHeap(nums);

   // delete min
   // moving first element to back so theres a 'hole'
   int size = nums.size();
   for (int j = nums.size() - 1; j > size / 2; --j)
   {
      std::swap(nums[1], nums[j]);
      nums.pop_back();
      percDown(nums, 1);
   }

   auto end_time = std::chrono::high_resolution_clock::now();
   duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

   return nums[1];
}

void percDown(std::vector<int> &heap, std::vector<int>::size_type hole)
{
   int temp = heap[hole];
   int child;

   for (; hole * 2 <= heap.size(); hole = child)
   {
      child = hole * 2;
      if (child + 1 < heap.size() && heap[child + 1] < heap[child])
      {
         ++child;
      }

      if (heap[child] < temp)
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
      percDown(heap, i);
   }
}