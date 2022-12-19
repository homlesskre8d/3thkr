#include "InitialMatrixFileOutput.h"

using namespace std;


void InitialMatrixFileOutput(vector<vector<int>> matrix)
{
	const int this_file = 1;
	string name;
	ofstream  FileRecorder;
	FileRecorder.exceptions(ofstream::badbit | ofstream::failbit);
	ifstream CheckFileExist;
	CheckFileExist.exceptions(ifstream::badbit | ifstream::failbit);

	while (true)
	{
		cout << "Enter file name or full way." << endl << "ENTER:";
		getline(cin, name);
		if (name.find(".txt") >= string::npos) {
			cout << "Wrong data type\n" << endl;
			continue;
		}
		try
		{
			CheckFileExist.open(name);
			cout << "A file with the same name already exists. " << endl
				<< "1 - Save in this file " << endl
				<< "2 - Chose another name " << endl;
			int var = InputCheck::CheckMenu(2);
			if (var == this_file)
			{
				FileRecorder.open(name);
				CheckFileExist.close();
			}
			else
			{
				CheckFileExist.close();
				continue;
			}
		}
		catch (const exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const exception&)
			{
				cout << "Access error" << endl;
				continue;
			}

		}
		break;


	}

	int numberOfLines = static_cast<int> (matrix.size());
	int numberOfColums = static_cast<int>(matrix[0].size());


	FileRecorder << numberOfLines << endl;
	FileRecorder << numberOfColums << endl;
	for (int i = 0; i < numberOfLines; i++)
	{
		for (int j = 0; j < numberOfColums; j++)
		{
			FileRecorder << matrix[i][j] << endl;
		}
	}
	FileRecorder.close();
}

