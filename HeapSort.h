#pragma once
#include "DynamicArray.h"
#include "StudentData.h"

//Basic heapsort , nothing special
//uses the siftDown technique 

template <typename T>
void ArrSwap(DynamicArray<StudentData<T>>& array, size_t firstIndex, size_t secondIndex)
{

	StudentData<T> temp = array[firstIndex];

	array[firstIndex] = array[secondIndex];

	array[secondIndex] = temp;

}

size_t findParent(size_t index);

size_t findLeftChild(size_t index);

size_t findRightChild(size_t index);


template <typename T>
void heapsort(DynamicArray<StudentData<T>>& toSort, size_t size);

template <typename T>
void heapify(DynamicArray<StudentData<T>>& toheapify, size_t size);

template <typename T>
void siftDown(DynamicArray<StudentData<T>>& toFix, size_t start, size_t end);

template<typename T>
inline void heapsort(DynamicArray<StudentData<T>>& toSort, size_t size)
{
	heapify(toSort, size);

	size_t end = size - 1;

	while (end > 0)
	{

		ArrSwap(toSort, end, 0);

		end--;

		siftDown(toSort, 0, end);

	}
}

template<typename T>
inline void heapify(DynamicArray<StudentData<T>>& toheapify, size_t size)
{
	int start = findParent(size - 1);

	while (start >= 0)
	{

		siftDown(toheapify, start, size - 1);

		start--;

	}
}

template<typename T>
inline void siftDown(DynamicArray<StudentData<T>>& toFix, size_t start, size_t end)
{
	size_t root = start;
	size_t swap, child;

	while (findLeftChild(root) <= end)
	{

		child = findLeftChild(root);

		swap = root;

		if (toFix[swap] < toFix[child])
		{
			swap = child;
		}

		if (child + 1 <= end && toFix[swap] < toFix[child + 1])
		{
			swap = child + 1;
		}

		if (swap == root)
		{
			return;
		}

		else
		{

			ArrSwap(toFix, root, swap);

			root = swap;

		}
	}
}
