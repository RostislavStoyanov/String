#include"String.h"

int main() {

	/*
	char* fileName=new char[100];
    std::cin >> fileName;
    std::ifstream is(fileName);

    if(is.good()) {
        String str3;
        str3.getLine(is);
        str3.print();
        is.close();
    }
    else std::cerr<<"Error opening the file"<<std::endl;
     
	delete[] fileName;
	String str = "hello";
	String str2 = str;
	str2.print();
    str.print();
	*/
	String str,str2;
	std::cin >> str >> str2;
	//str.getLine(std::cin);
	std::cout << str << " " << str2 << std::endl;
    return 0;
}