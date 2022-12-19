#pragma once
#include <iostream>
#include <vector>
#include "ISort.h"
#include "DigitsSum.h"
using namespace std;



class SortedMatrix
{
private:
	int numberOfLines;
	int numberOfColums;
	vector<vector<int>> matrix;
	vector<vector<int>> matrixLines;
	vector<vector<int>> SortEvenColums(vector<vector<int>> matrix, shared_ptr<ISort> sort);
	vector<vector<DigitsSum>> digitSums;

	vector<vector<DigitsSum>> GetDigitSum(vector<vector<int>> matrix);
	
	
public:
	SortedMatrix( vector<vector <int>> matrixValue,shared_ptr<ISort> sort)
	{
		numberOfLines = static_cast<int>(matrixValue.size());
		numberOfColums =static_cast<int>(matrixValue[0].size());
		digitSums = GetDigitSum(matrixValue);
		matrix = SortEvenColums(matrixValue, sort);
		
	}
	int GetNumberOflines();
	int GEtNumberOfColums();
	vector<vector<int>> GetMatrix();


	void Show();
};

