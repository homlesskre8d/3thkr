#include "QuickSort.h"

using namespace std;

void QuickSort::PrintCounters()
{
	cout << "Quicksort" << endl;
	ISort::PrintCounters();
}

void QuickSort::Sort(vector<DigitsSum>& arr, int size)
{
	Quicksort(arr, 0, size-1);
}

void QuickSort::Quicksort(vector<DigitsSum>& arr, int start, int end)
{
	if (start < end) {
		int p = Partition(arr, start, end);
		Quicksort(arr, start, p - 1);
		Quicksort(arr, p + 1, end);
	}
}

int QuickSort::Partition(vector<DigitsSum>& arr, int start, int end)
{
	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		comparisonCounter++;
		if (arr[i].GetValue()  > arr[pivot].GetValue()) {
			swapCounter++;
			swap(arr[i], arr[j]);
			++j;
		}
	}
	swap(arr[j], arr[pivot]);
	if(swapCounter > 0)
		swapCounter++;
	return j;

}

