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
	//String str,str2;
	//std::cin >> str >> str2;
	//String str;
	//str.getLine(std::cin);
	//std::cout << str << " " << str2 << std::endl;
	//String sub = str.substr(2, 2);
	//std::cout << str << std::endl;
	//std::cout << sub << std::endl;
	const String str = "testingsomethingcalled";
	//String str2 = "concat";
	//str += "concat";
	//std::cout << str << std::endl;
	
	std::cout << str[5] << std::endl;
    return 0;
}