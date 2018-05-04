#include "CountingSort.h"

#define UPPERBOUND 100

size_t min(int first, int second)
{

	return (first - second < 0) ? first : second;

}

size_t findParent(size_t index)
{

	return (index - 1) / 2;

}

size_t findLeftChild(size_t index)
{

	return 2 * index + 1;

}

size_t findRightChild(size_t index)
{

	return 2 * index + 2;

}


void countingSort(DynamicArray<StudentData<int>>& toSort, size_t size)
{

	int arr[UPPERBOUND]{ 0 };

	DynamicArray<StudentData<int>> newOne = toSort;

	for (size_t i = 0; i < size; ++i)
	{

		int temp = newOne.getAt(i).getSortBy();

		arr[temp - 1] ++;

	}

	int lastCount = 0;

	for (size_t i = 0; i < UPPERBOUND; ++i)
	{

		if (arr[i] != 0 && lastCount != 0)
		{

			arr[i] += lastCount;

			lastCount = arr[i];

		}

		if (arr[i] != 0 && lastCount == 0)
		{

			lastCount += arr[i];

		}

	}

	for (size_t i = 0; i < size; ++i)
	{
		int numTemp = newOne.getAt(i).getSortBy() - 1;

		if (arr[numTemp] != 0)
		{

			toSort.setAt(--arr[numTemp], newOne.getAt(i));

		}

	}

}
