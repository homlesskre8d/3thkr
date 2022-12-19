#include "MatrixInput.h"
#include <time.h>


using namespace std;

int  MatrixInput(vector<vector<int>>& matrix)
{

	cout << "1 - matrix byhand input " << endl
		<< "2 - matrix random input " << endl
		<< "3 - matrix file input" << endl;
	InputMode mode = static_cast<InputMode>(InputCheck::CheckMenu(3));
	switch (mode)
	{
	case InputMode::ConsoleByHand:
		matrix = ConsoleInput();
		break;

	case InputMode::ConsoleRandom:
		matrix = RandomInput();
		break;

	case InputMode::File:
		matrix = FileInput();
		break;

		
	}
	return static_cast<int>(mode);
}

vector<vector<int>> ConsoleInput()
{
	
		cout << "Enter lines ." << endl;;
		int lines = InputCheck::CheckIntValuePlus();
		cout << "Enter colums ." << endl;;
		int colums = InputCheck::CheckIntValuePlus();

		vector<vector<int>> matrix;

		for (int i = 0; i < lines; i++)
		{
			matrix.push_back(vector<int>{});
			for (int j = 0; j < colums; j++)
			{
				cout << "Enter [" << i + 1 << "] [" << j + 1 << "] ." << endl;
				matrix[i].push_back(InputCheck::CheckIntValue());
			}
		}
		return matrix;
}

vector<vector<int>> FileInput()
{
	string file_name = "";
	ifstream file;
	vector<vector<int>> matrix;
	file.exceptions(ifstream::badbit | ifstream::failbit);
	while (true)
	{
		cout << "Enter file name. " << endl << "ENTER : ";
		cin >> file_name;
		if (file_name.find(".txt") >= string::npos) {
			cout << "Wrong data type\n" << endl;
			continue;
		}
		try
		{
			file.open(file_name);
			cout << "Sucefull file open " << endl;
		}
		catch (const exception&)
		{
			cout << "Incorrect file name or way.Try again ." << endl;
			continue;

		}

		try
		{
			int lines = (InputCheck::CheckLineUnsInt(file));
			int colums = (InputCheck::CheckLineUnsInt(file));
		

			for (int i = 0; i < lines; i++)
			{
				matrix.push_back(vector<int>{});
				for (int j = 0; j < colums; j++)
				{
					matrix[i].push_back( InputCheck::CheckLineInt(file));
				}
			}
		}
		catch (exception&)
		{
			file.close();
			continue;
		}
		cin.clear();
		cin.ignore();
		file.close();
		return matrix;
	}
}

vector<vector<int>>  RandomInput() 
{
	srand(static_cast<unsigned>(time(nullptr)));
	cout << "Enter lines ." << endl;;
	int lines = InputCheck::CheckIntValuePlus();
	cout << "Enter colums ." << endl;;
	int colums = InputCheck::CheckIntValuePlus();

	vector<vector<int>>	matrix;

	for (int i = 0; i < lines; i++)
	{
		matrix.push_back(vector<int>{});
		for (int j = 0; j < colums; j++)
		{
			matrix[i].push_back(rand() % 101 - 50);
		}
	}
	return matrix;
}

