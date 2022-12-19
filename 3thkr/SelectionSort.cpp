#include "SelectionSort.h"

using namespace std;

void SelectionSort::PrintCounters()
{
	cout << "Selectionsort" << endl;
	ISort::PrintCounters();
}

void SelectionSort::Sort(vector<DigitsSum>& arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		DigitsSum tmp = arr[i];
		int tmpid = i;
		for (int j = i + 1; j < size; j++)
		{
			comparisonCounter++;
			if (arr[tmpid].GetValue() <  arr[j].GetValue())
			{
				tmp = arr[j];
				tmpid = j;
			}
		}
		if (tmpid != i)
		{
			swapCounter++;
			swap(arr[i], arr[tmpid]);
		}
	}
}
