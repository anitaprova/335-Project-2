#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

std::vector<int> &worstCaseQuickSelect(void);
int worstCaseQuickSelect(std::vector<int> &nums);
void worstCaseQuickSelect(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high, std::vector<int>::iterator k);
std::vector<int>::iterator worstCaseHoarePartition(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);
std::vector<int>::iterator worstCaseMedian3(std::vector<int> &nums, std::vector<int>::iterator low, std::vector<int>::iterator high);