#include "ISort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "MatrixInput.h"
#include "InitialMatrixFileOutput.h"
#include "SaveData.h"


enum class Answer
{
	Yes = 1,
	No

};


int main()
{
	int const sortsCount = 5;
	cout << "verbeckiy daniil 415gr var 6 kr 3 " << endl
		<< "Sort " << endl;
	while (true)
	{
		vector < shared_ptr<ISort>> sortsCase;
		vector < shared_ptr<SortedMatrix>> sortsMatrices;
		vector<vector<int>> matrix;

		sortsCase.emplace_back(make_shared<BubbleSort>());
		sortsCase.emplace_back(make_shared<QuickSort>());
		sortsCase.emplace_back(make_shared<SelectionSort>());
		sortsCase.emplace_back(make_shared<ShellSort>());
		sortsCase.emplace_back(make_shared<InsertionSort>());

		InputMode mode = static_cast<InputMode>(MatrixInput(matrix));

		for (size_t i = 0; i < matrix.size(); i++)
		{
			for (size_t j = 0; j < matrix[0].size(); j++)
			{
				cout << matrix[i][j] << "\t";
			}
			cout << endl;
		}
		for (int i = 0; i < sortsCount; i++)
		{
			sortsMatrices.emplace_back(make_shared<SortedMatrix>(matrix, sortsCase[i]));
			sortsCase[i]->PrintCounters();
			sortsMatrices[i]->Show();
		}

		if (mode == InputMode::ConsoleByHand || mode == InputMode::ConsoleRandom)
		{
			cout << "Do you want to save the original matrix data to a file ?" << endl;
			cout << "1 - yes\n2 - no" << endl;
			Answer initialChoice = static_cast<Answer>(InputCheck::CheckMenu(2));
			if (initialChoice == Answer::Yes)
				InitialMatrixFileOutput(matrix);
		}
		cout << "Do you want to save the sort comparison table to a file ?" << endl;
		cout << "1 - yes\n2 - no" << endl;
		Answer dataChoice = static_cast<Answer>(InputCheck::CheckMenu(2));
		if (dataChoice == Answer::Yes)
			SaveData(sortsCase, sortsMatrices);

		cout << "Continue?" << endl;
		cout << "1 - yes\n2 - no" << endl;
		Answer continueChoice = static_cast<Answer> (InputCheck::CheckMenu(2));
		if (continueChoice == Answer::No) return 0;
		sortsCase.clear();
	}

}
