#include "SortedMatrix.h"

using namespace std;

vector<vector<int>> SortedMatrix::SortEvenColums(vector<vector<int>> matrixValue, shared_ptr<ISort> sort)
{
	for (int i = 0;  i < digitSums.size();  i++)
	{
		sort->Sort(digitSums[i], static_cast<int>(digitSums[i].size()));
	}
	int counter = 0;
	for (int  j = 0; j < numberOfLines; j++)
	{
		
			for (int i = 0; i < numberOfColums; i++)
			{

				matrixValue[j][i] = digitSums[counter][i].GetDigit();
			}
			counter++;
	
	}
	return matrixValue;
}

vector<vector<DigitsSum>> SortedMatrix::GetDigitSum(vector<vector<int>> matrixValue)
{
	int counter = 0;
	vector<vector<DigitsSum>> tmp;
	for (int i = 0; i < numberOfLines; i++)
	{
		
		tmp.push_back(vector<DigitsSum>{});
		for (int j = 0; j < numberOfColums; j++)
		{
			tmp[counter].emplace_back(DigitsSum(i, j, matrixValue[i][j]));
		}
		counter++;
	}
	return tmp;
}


int SortedMatrix::GetNumberOflines()
{
	return numberOfLines;
}

int SortedMatrix::GEtNumberOfColums()
{
	return numberOfColums;
}

vector<vector<int>> SortedMatrix::GetMatrix()
{
	return matrix;
}

void SortedMatrix::Show()
{
	
	cout <<  endl;
	for (int i = 0; i < numberOfLines; i++)
	{
		for (int j = 0; j < numberOfColums; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
	
	cout << "\n\n" << endl;
}
