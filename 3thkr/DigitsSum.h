#pragma once
#include <iostream>
#include <string>

using namespace std;

class DigitsSum
{
private:
	int indexX;
	int indexY;
	int sum = 0;
	int digit;
public:
	DigitsSum(int indexXValue,int indexYValue , int sumValue)
		:indexX(indexXValue),indexY(indexYValue),digit(sumValue)
	{
		while(abs(sumValue) > 0)
		{
			if (abs(sumValue) > 10)
			{

				sum += abs(sumValue) % 10;

			}
			else
			{
				sum += sumValue % 10;
			}
			sumValue /= 10;
		}

	}

	int GetIndexX();

	int GetIndexY();

	int GetValue();

	int GetDigit();
};

