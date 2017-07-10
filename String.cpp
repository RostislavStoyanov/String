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
    this->maxSize = strlen(other);
    getData(other, maxSize);
}

void String::getData(const char *dataSource, size_t maxSize) {
    currentSize = strlen(dataSource);
    try {
        char *newData = new char[maxSize];
        delete[] data;
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
        maxSize = strlen(other);
        getData(other, maxSize);
    }
    return *this;
}

void String::addChar(const char newChar) {
    if (maxSize == currentSize) {

    }
}

