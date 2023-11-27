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
   int temp;
   int child;

   for (temp = std::move(heap[hole]); leftChild(hole) < heap.size(); hole = child)
   {
      child = leftChild(hole);
      if (child != heap.size() - 1 && heap[child] > heap[child + 1])
      {
         ++child;
      }

      // if (heap[child] == heap[child + 1]) // left and right child are the same
      // {
      //    std::swap(heap[child], heap[std::floor(child / 2)]); // swap left child and parent 
      // }

      if (temp > heap[child])
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

int leftChild(int i)
{
   return 2 * i + 1;
}

void buildHeap(std::vector<int> &heap)
{
   for (int i = heap.size() / 2 - 1; i > 0; --i)
   {
      percDown(heap, i);
   }
}