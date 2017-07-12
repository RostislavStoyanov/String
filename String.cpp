//
// Created by rosti on 10.07.17.
//

#include "String.h"


String::String() {
    currentSize = 0;
    maxSize = 16;
    try {
        data = new char[maxSize];
    }
    catch (std::bad_alloc &) {
        std::cerr << "Not enough memory" << std::endl;
        throw;
    }
	data[0] = '\0';
}

String::~String() {
    delete[] data;
}

size_t String::length() const {
    return currentSize;
}

String::String(const String &other) {
    this->maxSize = other.maxSize;
    getData(other.data, maxSize);
}

String::String(const char *other) {
    this->maxSize = strlen(other) *2;
    getData(other, maxSize);
}

void String::getData(const char *dataSource, size_t maxSize) {
    currentSize = strlen(dataSource);
    try {
        char *newData = new char[maxSize];
        DELETE_TABLE (data);
		data = newData;
        strcpy(data, dataSource);
    }
    catch (std::bad_alloc &) {
        std::cerr << "Not enough memory" << std::endl;
        throw;
    }
}


String String::operator=(const String &other) {
    if (this != &other) {
        maxSize = other.maxSize;
        getData(other.data, maxSize);
    }
    return *this;
}

String String::operator=(const char *other) {
    if (this->data != other) {
        maxSize = strlen(other) *2;
        getData(other, maxSize);
    }
    return *this;
}

void String::addChar(const char newChar) {
    if (maxSize == currentSize+1) {
		maxSize *= 2;
		getData(this->data, maxSize);
    }
	data[currentSize++] = newChar;
}

void String::getLine(std::ifstream & is, const char delim='\n')
{
	char temp;
	while (!is.eof())
	{
		is.get(temp);
		if (temp == delim)
			break;
		else
			addChar(temp);
	}
	return;
}

size_t String::find(const char * text)
{
	size_t currPos=-1;
	bool found = 0;
	for (size_t i = 0; i < currentSize; i++)
	{
        if (data[i] == text[0])
		{
			for (size_t j = i+1; j < currentSize; j++)
			{
                if (data[j] == text[j - i])
					found = 1;
				else
				{
					found = 0;
					break;
				}
			}
			if (found == 1)
			{
				currPos = i;
				break;
			}
		}
	}
	return currPos;
}

void String::print() const
{
	for (size_t i = 0; i < currentSize; i++)
	{
		std::cout << data[i];
	}
	std::cout << std::endl;
}

char * String::toChar() const
{
	char* text= new char[currentSize+1];
	for (size_t i = 0; i < currentSize; i++)
	{
		text[i] = data[i];
	}
	text[currentSize + 1] = 0;
	return text;
}

