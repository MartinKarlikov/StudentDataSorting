#pragma once
#include "DynamicArray.h"
#include "StudentData.h"
#include "SortingAlgorithms.h"
#include <fstream>
#include <iostream>

//All of the logic the main function has to offer
//reads the file , finds what has to be sorted and in what order
//made the execute functions template because the holding structure
//varies on the column that serves as a comparison for the sorting algorithms

size_t findCommaIndex(char* data, size_t stringSize, size_t commaNum);

char* extractString(char* data, size_t secondCommaNum);

size_t getColumnNum(char* columnName);

template<typename T>
T extractSortBy(char* data, char* columnName);

template<typename T>
DynamicArray<StudentData<T>> readFile(ifstream& file, char* columnName);

void ExecuteInt(ifstream& file, char* columnName, char* ascOrDesc);

void ExecuteChar(ifstream& file, char* columnName, char* ascOrDesc);

template<typename T>
inline T extractSortBy(char * data, char * columnName)
{
}

template<>
inline char* extractSortBy(char * data, char * columnName)
{

	size_t columnNum = getColumnNum(columnName);

	char* sortBy = extractString(data, columnNum);

	return sortBy;

}

template<>
inline int extractSortBy(char * data, char * columnName)
{

	size_t columnNum = getColumnNum(columnName);

	char* sortBy = extractString(data, columnNum);

	int num =  atoi(sortBy);

	delete[] sortBy;

	return num;

}


template<typename T>
inline DynamicArray<StudentData<T>> readFile(ifstream & file, char* columnName)
{

	DynamicArray<StudentData<T>> arr;

	return arr;

}

template<>
inline DynamicArray<StudentData<int>> readFile(ifstream & file, char* columnName)
{

	DynamicArray<StudentData<int>> arr;

	char data[1024];

	file.getline(data, 1024);
	
	while (true)
	{
		
		file.getline(data, 1024);

		if (!file)
		{
			break;
		}

		int sortByBuff = extractSortBy<int>(data, columnName);

		arr.add(StudentData<int>(data, sortByBuff));

	}

	return arr;
}

template<>
inline DynamicArray<StudentData<char*>> readFile(ifstream & file, char* columnName)
{

	DynamicArray<StudentData<char*>> arr;

	char data[1024];

	file.getline(data, 1024);

	while (true)
	{
		
		file.getline(data, 1024);

		if (!file)
		{
			break;
		}

		char* sortByBuff = extractSortBy<char*>(data, columnName);

		arr.add(StudentData<char*>(data, sortByBuff));

		delete[] sortByBuff;


	}

	return arr;
}







