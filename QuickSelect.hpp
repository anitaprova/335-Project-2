#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int quickSelect(std::vector<int> &nums, int &duration);
void quickSelect(std::vector<int> &nums, std::vector<int>::iterator left, std::vector<int>::iterator right, std::vector<int>::iterator k);
std::vector<int>::iterator hoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
std::vector<int>::iterator median3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);