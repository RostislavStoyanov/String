//
// Created by rosti on 10.07.17.
//
#pragma warning(disable:4996)
#ifndef STRING_STRING_H
#define STRING_STRING_H

#include<iostream>
#include<cstring>
#include<fstream>

class String {
private:
    char *data; //holds the text
    size_t maxSize; //maximum number of chars in data
    size_t currentSize; //current number of chars in data

    void getData(const char *, size_t maxSize); //sets currentSize to the other char* size and
												// copies the content of the other char* to data
public:
    String(); //default constructor
    ~String(); //destructor

    String(const String &); //copy-constructor(from String)
    String(const char *);   //copy-constructor(from char*)

    String operator=(const String &); //operator= (from string)
    String operator=(const char *);  //operator=(from char*)

    size_t length() const; //currentSize getter

    void addChar(const char); //adds a char to the data array

	void getLine(std::istream&, const char delim = '\n'); // reads line till deliminator and stores it in this string object(all data previously stored is lost)

	size_t find(const char*); //searches for text in the string and if found returns the starting position , if not found returns -1;

	char* toChar() const; //returns a new allocated char pointer with the text inside (must be deleted afterwards)

	friend std::istream& operator>>(std::istream&,String&); //reads till space or enter(as normal >>)

	friend std::ostream& operator<<(std::ostream&, const String&); //prints the current object to ostream
};


#endif //STRING_STRING_H
