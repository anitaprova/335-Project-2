#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cmath>

int inPlaceMergeSort (std::vector<int>& nums, int& duration);
int MergeSort(std::vector<int> &nums, std::vector<int>::iterator l, std::vector<int>::iterator r);