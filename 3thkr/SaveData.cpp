#include "SaveData.h"
#include <fstream>
#include"InputCheck.h"
#include"SaveData.h"
#include "SortedMatrix.h"

using namespace std;

void SaveData(vector<shared_ptr<ISort>>& sortsCase, vector < shared_ptr<SortedMatrix>> sortsMatrices)
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
	vector<vector<int>> matrixColums = sortsMatrices[0]->GetMatrix();

	FileRecorder<< string(15,' ') << "Comparison" << "\t" << "Swap" << endl;
	for (int i = 0; i < sortsCase.size(); i++)
	{
		string temp_name = typeid(*sortsCase[i]).name();
		temp_name.erase(0, 6);
		FileRecorder << temp_name << string(15 - temp_name.size(),' ') << sortsCase[i]->GetComprasionCounter() << "\t\t\t" << sortsCase[i]->GetSwapCountrt() << endl;;
	}
	FileRecorder << "\nSorted even colums" << endl;
	for (int i = 0; i < sortsMatrices[0]->GetNumberOflines(); i++)
	{
		for (int j = 0; j < sortsMatrices[0]->GEtNumberOfColums(); j++)
		{
			FileRecorder << matrixColums[i][j] << "\t";
		}
		FileRecorder << endl;
	}

		
	FileRecorder.close();
}
