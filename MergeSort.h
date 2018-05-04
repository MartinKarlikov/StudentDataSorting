#pragma once
#include "DynamicArray.h"
#include "StudentData.h"

//Straightforward iterative mergeSort

template <typename T>
void mergeSort(DynamicArray<StudentData<T>>& toSort, size_t size);

template<typename T>
void merge(DynamicArray<StudentData<T>>& first, DynamicArray<StudentData<T>>& second, size_t right, size_t left, size_t end);

size_t min(int first, int second);

template <typename T>
inline void mergeSort(DynamicArray<StudentData<T>>& toSort, size_t size)
{
	DynamicArray<StudentData<T>> second = toSort;

	for (int step = 1; step < size; step *= 2)
	{
		for (int i = 0; i < size; i = i + 2 * step)
		{
			merge(toSort, second, i, min(i + step, size), min(i + 2 * step, size));
		}

		toSort = second;
	}
}

template <typename T>
inline void merge(DynamicArray<StudentData<T>>& first, DynamicArray<StudentData<T>>& second, size_t left, size_t right, size_t end)
{
	size_t leftBoundry = left, rightBoundry = right;
	for (size_t i = left; i < end; ++i)
	{
		if (leftBoundry < right 
			&& 
			(rightBoundry >= end || first.getAt(leftBoundry) <= first.getAt(rightBoundry)))
		{
			second.setAt(i, first.getAt(leftBoundry));
			leftBoundry++;

		}
		else
		{
			second.setAt(i, first.getAt(rightBoundry));
			rightBoundry++;

		}
	}
}

