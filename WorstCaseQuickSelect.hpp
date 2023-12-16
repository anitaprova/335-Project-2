/*
CSCI335 Fall 2023
Assignment 2
Name Anita Prova
Date 12/15/23
*/

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * generates vector for worstcase of quickselect
 * @return: vector of size 20,000
 */
std::vector<int> worstCaseQuickSelect(void);

/**
 * generates vector for worstcase of quickselect
 * @return: vector of size 20,000
 */
std::vector<int> worstCaseQuickSelect(void)
{
	std::vector<int> v;
	for (int i = 20000; i >= 1; i--)
	{
		v.push_back(i);
	}

	return v;
}