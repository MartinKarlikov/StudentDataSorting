#include <iostream>
#include <fstream>
#include "StudentData.h"
#include "DynamicArray.h"
#include "SortingAlgorithms.h"
#include "CommandExecution.h"
using namespace std;

int main()
{
	while (true)
	{
		char pathToFileBuff[1024] , columnNameBuff[1024], ascOrDescBuff[1024];

		cin.getline(pathToFileBuff, 1024,' ');

		cin.getline(columnNameBuff, 1024, ' ');

		cin.getline(ascOrDescBuff, 1024);

		size_t columnNum = getColumnNum(columnNameBuff);

		ifstream file(pathToFileBuff);

		if (columnNum % 2 !=0)
		{
			ExecuteChar(file, columnNameBuff, ascOrDescBuff);
		}
		else
		{
			ExecuteInt(file, columnNameBuff, ascOrDescBuff);
		}
		
	}
	return 0;
}