#pragma once
#include <vector>
#include<memory>
#include"ISort.h"
#include"SortedMatrix.h"
using namespace std;

void SaveData(vector<shared_ptr<ISort>>& sorts_case, vector < shared_ptr<SortedMatrix>> sortsMatrices);


