#pragma once
#include <iostream>


//The main strucure used to hold the student's data
//it holds one line with all the info about the student
//and a string for the item that determines the sorting comparison


void copyString(char*& destination, char* source);

template<typename T>
class StudentData
{
public:

	StudentData();

	StudentData(char* input, T sortSubject);

	StudentData(const StudentData& other);

	StudentData<T>& operator=(const StudentData& other);

	~StudentData();

	bool operator<(const StudentData& other) const;

	bool operator<=(const StudentData& other) const;

	char* getData() const;

	T getSortBy() const;

private:
	
	T sortBy;
	char* data;
};


template<typename T>
inline StudentData<T>::StudentData()
{

	sortBy = 0;

	data = nullptr;

}

template<typename T>
inline StudentData<T>::StudentData(char * input, T sortSubject)
{
}

inline  StudentData<int>::StudentData(char * input, int sortSubject)
{

	copyString(data, input);

	sortBy = sortSubject;

}


inline  StudentData<char*>::StudentData(char* input, char* sortSubject)
{

	copyString(data, input);

	copyString(sortBy, sortSubject);

}

template<typename T>
inline  StudentData<T>::StudentData(const StudentData & other)
{
}

template<typename T>
inline StudentData<T>& StudentData<T>::operator=(const StudentData & other)
{

	return *this;

}

inline StudentData<int>& StudentData<int>::operator=(const StudentData & other)
{

	if (this != &other)
	{

		delete[] data;

		copyString(data, other.data);

		sortBy = other.sortBy;

	}

	return *this;
}

inline StudentData<char*>& StudentData<char*>::operator=(const StudentData & other)
{

	if (this != &other)
	{

		delete[] data;

		delete[] sortBy;

		copyString(data, other.data);

		copyString(sortBy, other.sortBy);

	}

	return *this;

}

inline StudentData<int>::StudentData(const StudentData & other)
{

	copyString(data, other.data);

	sortBy = other.sortBy;

}

inline StudentData<char*>::StudentData(const StudentData & other)
{

	copyString(data, other.data);

	copyString(sortBy, other.sortBy);

}

template<typename T>
inline StudentData<T>::~StudentData()
{

	delete[] data;

}

inline StudentData<int>::~StudentData()
{

	delete[] data;

}

inline StudentData<char*>::~StudentData()
{

	delete[] data;

	delete[] sortBy;

}

inline bool StudentData<int>::operator<(const StudentData& other) const
{

	return sortBy < other.sortBy;

}

inline  bool StudentData<char*>::operator<(const  StudentData& other) const
{

	int temp = strcmp(sortBy, other.sortBy);

	return temp < 0 ;

}


template<typename T>
inline bool StudentData<T>::operator<=(const StudentData & other) const
{
}

template<typename T>
inline char * StudentData<T>::getData() const
{

	char* temp;

	copyString(temp, data);

	return temp;

}

template<typename T>
inline T StudentData<T>::getSortBy() const
{

	return sortBy;

}

inline bool StudentData<int>::operator<=(const StudentData& other) const
{

	return sortBy <= other.sortBy;

}

inline  bool StudentData<char*>::operator<=(const  StudentData& other) const
{

	int temp = strcmp(sortBy, other.sortBy);

	return temp < 0 || temp == 0;

}




