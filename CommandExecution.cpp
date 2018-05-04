#include "CommandExecution.h"

char * extractString(char * data, size_t secondCommaNum)
{
	char* runner;

	size_t firstCommaIndex = findCommaIndex(data,strlen(data),secondCommaNum-1);
	size_t secondCommaIndex =(secondCommaNum==5)?strlen(data)-1: findCommaIndex(data, strlen(data), secondCommaNum);
	
	size_t newSize = secondCommaIndex - firstCommaIndex;
	runner = new char[newSize+1];
	size_t t = 0;

	for (size_t i =(firstCommaIndex==0)?0: firstCommaIndex+1; i < secondCommaIndex; ++i)
	{
		
		runner[t] = data[i];
		t++;
	}
	runner[t] = '\0';
	
	return runner;
}

size_t getColumnNum(char * columnName) 
{
	if (!strcmp(columnName, "name"))
	{
		return 1;
	}
	if (!strcmp(columnName, "age"))
	{
		return 2;
	}
	if (!strcmp(columnName, "subject"))
	{
		return 3;
	}
	if (!strcmp(columnName, "grade"))
	{
		return 4;
	}
	if (!strcmp(columnName, "date"))
	{
		return 5;
	}
	throw exception("Column doesn't exist");
}

size_t findCommaIndex(char * data, size_t stringSize, size_t commaNum)
{
	size_t commaCounter= 0;
	for (size_t i = 0; i < stringSize; ++i)
	{
		if (data[i] == ',')
		{
			commaCounter++;
		}
		if (commaCounter == commaNum)
		{
			return i;
		}
	}
	throw exception("Invalid comma number");
}

void ExecuteInt( ifstream& file, char * columnName, char * ascOrDesc)
{
	DynamicArray<StudentData<int>> array = readFile<int>(file, columnName);

	size_t columnNum = getColumnNum(columnName);


	countingSort(array, array.getSize());

	if (!strcmp(ascOrDesc, "desc"))
	{
		array.reverseArray();
	}
	array.print();
}

void ExecuteChar(ifstream& file, char * columnName, char * ascOrDesc) 
{
	DynamicArray<StudentData<char*>> array = readFile<char*>(file, columnName);

	size_t columnNum = getColumnNum(columnName);

	if (columnNum == 1 || columnNum == 3)
	{
		mergeSort<char*>(array, array.getSize());
	}

	if (columnNum == 5)
	{
		heapsort<char*>(array, array.getSize());
	}

	if (!strcmp(ascOrDesc, "desc"))
	{
		array.reverseArray();
	}
	array.print();
}

