#include"String.h"

int main() {

	char* fileName=new char[100];
	std::cin >> fileName;
	std::ifstream is(fileName, std::ios::in);
	String str;
	str.getLine(is, '.');
	str.print();
	is.close();
	delete[] fileName;
    return 0;
}