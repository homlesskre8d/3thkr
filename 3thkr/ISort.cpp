
#include "ISort.h"
#include "Names.h"

using namespace std;

int ISort::GetComprasionCounter()
{
	return comparisonCounter;
}

int ISort::GetSwapCountrt()
{
	return swapCounter;
}

void ISort::PrintCounters()
{
	cout << "Comparisions" << "\t\t" << "swaps" << endl;
	cout << "\t" << comparisonCounter << "\t\t" << swapCounter << endl;
}


