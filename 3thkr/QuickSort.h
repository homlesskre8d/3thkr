#pragma once
#include "ISort.h"
#include <iostream>
using namespace std;

class QuickSort : public ISort
{
public:
	void PrintCounters() override;

	void Sort(vector<DigitsSum>& arr, int size) override;
	void Quicksort(vector<DigitsSum>& arr, int start, int end);

	int Partition(vector<DigitsSum>& arr, int start, int end);
};

