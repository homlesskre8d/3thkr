#pragma once
#include "ISort.h"
using namespace std;

class InsertionSort : public  ISort
{
public:
	

	void PrintCounters() override;

	void Sort(vector<DigitsSum>& arr, int size) override;

};

