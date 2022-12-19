#include "BubbleSort.h"

using namespace std;


void BubbleSort::PrintCounters()
{
	cout << "Bubblesort" << endl;
	ISort::PrintCounters();
}

void BubbleSort::Sort(vector<DigitsSum>& arr, int size)
{
	bool end = true;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			comparisonCounter++;
			if (arr[j].GetValue() < arr[j + 1].GetValue())
			{
				swapCounter++;
				swap(arr[j], arr[j + 1]);
				end = false;
			}

		}
		if (end)return;
	}
}
