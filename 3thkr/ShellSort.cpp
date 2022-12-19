#include "ShellSort.h"

using namespace std;

void ShellSort::PrintCounters()
{
    cout << "Shellsort" << endl;
    ISort::PrintCounters();
}

void ShellSort::Sort(vector<DigitsSum>& arr, int size)
{
    for (int gap = size/2; gap > 0; gap/=2)
        for (int i = gap; i < size; i++)
        {
            DigitsSum temp = arr[i];
            int j;
            comparisonCounter++;
            for (j = i; j >= gap && arr[j - gap].GetValue() < temp.GetValue(); j -= gap)
            {
                swapCounter++;
                arr[j] = arr[j - gap];
                if (j == gap && gap != 1)
                    comparisonCounter--;
            }

            arr[j] = temp;
        } 
}
