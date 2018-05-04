#include "StudentData.h"


void copyString(char*& destination, char* source)
{

	size_t size = strlen(source) + 1;

	destination = new char[size];

	strcpy_s(destination, size, source);

}
