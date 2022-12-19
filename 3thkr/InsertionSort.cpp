#include "InsertionSort.h"

using namespace std;


void InsertionSort::PrintCounters()
{
	cout << "Insertionsort" << endl;
	ISort::PrintCounters();
}

void InsertionSort::Sort(vector<DigitsSum>& arr, int size)
{
    for (int k = 1; k < size; k++)
    {
       
        DigitsSum temp = arr[k];
        int j = k - 1;
        comparisonCounter++;
        while (j >= 0 && temp.GetValue() > arr[j].GetValue())
        {
            comparisonCounter++;
            swapCounter++;
            arr[j + 1] = arr[j];
            j --;
            if(j==0)
                comparisonCounter--;

        }
       arr[j + 1] = temp;
    }
}
