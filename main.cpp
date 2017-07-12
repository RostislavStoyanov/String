#include"String.h"

int main() {

	char* fileName=new char[100];
    //std::cin >> fileName;
    std::ifstream is(fileName);

    /*if(is.good()) {
        String str;
        str.getLine(is, '.');
        str.print();
        is.close();
    }
    else std::cerr<<"Error opening the file"<<std::endl;
     */
	delete[] fileName;
    String str = "helloooo!";
    str.print();
    return 0;
}