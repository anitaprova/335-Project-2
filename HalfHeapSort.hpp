#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

int halfHeapSort (std::vector<int>& nums, int& duration);
void percDown(std::vector<int> &heap, std::vector<int>::size_type hole);
void buildHeap(std::vector<int> &heap);

/**
 * sorts the vector halfway using heapsort algorithm through in order to obtain median
 * @param nums: reference to the vector to be sorted
 * @param duration: reference to the time taken to complete the sorting process
 * @return: element 1 of the heap
 */
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

	return nums[1];
}

/**
 * moves the hole into the correct place so heap order property is maintained
 * @param heap: reference to the heap to be sorted
 * @param hole: location of where to start percolating from
 */
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

/**
 * creates a min heap given a vector
 * @param heap: reference to the heap
 */
void buildHeap(std::vector<int> &heap)
{
	for (int i = (heap.size() - 1) / 2; i > 0; --i)
	{
		heap[0] = heap[i];
		percDown(heap, i);
	}
}