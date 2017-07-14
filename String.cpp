//
// Created by rosti on 10.07.17.
//

#include "String.h"


String::String() {
    currentSize = 0;
    maxSize = 16;
    try {
        data = new char[maxSize];
		data[0] = '\0';
    }
    catch (std::bad_alloc &) {
        std::cerr << "Not enough memory" << std::endl;
        throw;
    }
}

String::~String() {
    delete[] data;
}

size_t String::length() const {
    return currentSize;
}

String::String(const String &other) :currentSize(0),
									maxSize(other.maxSize),
									data(nullptr){
    getData(other.data, maxSize);
}

String::String(const char *other) : currentSize(0),
									maxSize(strlen(other) * 2),
									data(nullptr) {
    getData(other, maxSize);
}

void String::getData(const char *dataSource, size_t maxSize) {
    currentSize = strlen(dataSource);
    try {
        char *newData = new char[maxSize];
			strcpy(newData, dataSource);
			delete[] data;
			data = newData;
    }
    catch (std::bad_alloc &) {
        std::cerr << "Not enough memory" << std::endl;
        throw;
    }
}


String String::operator=(const String &other) {
    if (this != &other) {
        maxSize = other.maxSize+1;
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

void String::getLine(std::istream & is, const char delim)
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

std::istream & operator>>(std::istream &is, String &str)
{
	delete[] str.data;
	str.maxSize = 16;
	try{
		str.data = new char[str.maxSize];
		str.data[0] = '\0';
	}
	catch(std::bad_alloc&)
	{
		str.maxSize = 0;
		throw;
	}
	str.currentSize = 0;
	char temp;
	while (is)
	{
		is.get(temp);
		if (temp == '\n' || temp == ' ')
			break;
		str.addChar(temp);
	}
	return is;
}
