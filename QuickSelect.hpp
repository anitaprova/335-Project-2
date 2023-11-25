#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int quickSelect(std::vector<int> &nums, int &duration);
void hoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
int median3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);