#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

int halfHeapSort (std::vector<int>& nums, int& duration);
void percDown (std::vector<int>& heap, std::vector<int>::size_type hole);
void buildHeap (std::vector<int>& heap);