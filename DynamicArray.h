#pragma once
#include <iostream>

using namespace std;

#define STARTSIZE 8

//Dynamic array written for the purposes of the task
//Standard array that resizes itself 
//Made template for a more wide use


template<typename T>
class DynamicProxy;

template <typename T>
class DynamicArray
{
public:

	//Default constructor
	DynamicArray();

	//copy constructor
	DynamicArray(const DynamicArray& other);

	//destructor
	~DynamicArray();

	//redefined assignment operator
	DynamicArray<T>& operator=(const DynamicArray& other);

	//add function
	void add(T toAdd);

	//prints the array assuming the elements given has a getData function
	void print() const;

	//returns an element for the given index
	T& getAt(size_t index) const;

	//sets the element for a given index to a given value
	void setAt(size_t index,const T& toSet);

	//returns the used size of the array
	size_t getSize() const;

	//reverses the array,i.e. for when the array is sorted in asc order and we want it in desc
	void reverseArray();

	DynamicProxy<T> operator[](size_t);

	const DynamicProxy<T> operator[](size_t) const;

private:

	void resize();

	T* items;

	size_t size;

	size_t used;

};


template<typename T>
class DynamicProxy
{

private:

	DynamicArray<T>* arrTemp;

	size_t  arrIndex;

public:

	DynamicProxy(DynamicArray<T>* arr, size_t index);

	DynamicProxy(const DynamicProxy<T>& other);

	DynamicProxy<T>& operator=(const DynamicProxy<T>& other);

	operator T() const;

	DynamicProxy<T>& operator=(T other);

};

template <typename T>
bool operator<(const DynamicProxy<T>& lhs, const DynamicProxy<T>& rhs);

template <typename T>
bool operator<=(const DynamicProxy<T>& lhs, const DynamicProxy<T>& rhs);

template<typename T>
inline DynamicArray<T>::DynamicArray()
{

	size = STARTSIZE;

	used = 0;

	items = new T[STARTSIZE];

}

template<typename T>
inline DynamicArray<T>::DynamicArray(const DynamicArray<T> & other)
{
	size = other.size;

	used = other.used;

	items = new T[size];

	for (size_t i = 0; i < used; ++i)
	{

		items[i] = other.items[i];

	}

}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{

	delete[] items;

	items = nullptr;

	size = 0;

	used = 0;
}

template<typename T>
inline DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> & other)
{

	if (this != &other)
	{

		delete[] items;

		items = new T[other.size];

		size = other.size;

		used = other.used;

		for (size_t i = 0; i < used; ++i)
		{
			items[i] = other.items[i];
		}
		
	}

	return *this;

}

template<typename T>
inline void DynamicArray<T>::add(T toAdd)
{

	if (used + 1 > size)
	{
		resize();
	}

	items[used] = toAdd;

	used++;

}

template<typename T>
inline void DynamicArray<T>::print() const
{

	for (size_t i = 0; i < used; ++i)
	{
		cout << items[i].getData() << endl;
	}

	cout << endl;

}

template<typename T>
inline T& DynamicArray<T>::getAt(size_t index) const
{

	if (index>size)
	{
		throw out_of_range("Index was out of range.");
	}

	return items[index];

}

template<typename T>
inline void DynamicArray<T>::setAt(size_t index,const T& toSet)
{

	if (index>size)
	{
		throw out_of_range("Index was out of range.");
	}

	items[index] = toSet;

}

template<typename T>
inline size_t DynamicArray<T>::getSize() const
{

	return used;

}

template<typename T>
inline void DynamicArray<T>::reverseArray()
{

	for (size_t i = 0; i < used/2; ++i)
	{

		swap(items[i], items[used - i - 1]);

	}

}

template<typename T>
inline DynamicProxy<T> DynamicArray<T>::operator[](size_t index)
{

	return DynamicProxy<T>(this, index);

}

template<typename T>
inline const DynamicProxy<T> DynamicArray<T>::operator[](size_t index) const
{

	return DynamicProxy<T>(const_cast<DynamicArray*>(this), index);

}

template<typename T>
inline void DynamicArray<T>::resize()
{

	T* temp = new T[size * 2];

	for (size_t i = 0; i < used; ++i)
	{
		temp[i] = items[i];
	}

	size *= 2;

	delete[] items;

	items = temp;

}

template<typename T>
inline DynamicProxy<T>::DynamicProxy(DynamicArray<T>* arr, size_t index)
{
	arrTemp = arr;

	arrIndex = index;

}

template<typename T>
inline DynamicProxy<T>::DynamicProxy(const DynamicProxy & other)
{

	arrTemp = other.arrTemp;

	arrIndex = other.arrIndex;

}

template<typename T>
inline DynamicProxy<T>& DynamicProxy<T>::operator=(const DynamicProxy & other)
{

	arrTemp->setAt(arrIndex, T(other));

	return *this;

}

template<typename T>
inline DynamicProxy<T>::operator T() const
{

	return arrTemp->getAt(arrIndex);

}

template<typename T>
inline DynamicProxy<T> & DynamicProxy<T>::operator=(T other)
{
	
	arrTemp->setAt(arrIndex,other);

	return *this;

}

template<typename T>
inline bool operator<(const DynamicProxy<T>& lhs, const DynamicProxy<T>& rhs)
{

	return T(lhs)<T(rhs);

}

template<typename T>
inline bool operator<=(const DynamicProxy<T>& lhs, const DynamicProxy<T>& rhs)
{

	return T(lhs)<=T(rhs);

}
