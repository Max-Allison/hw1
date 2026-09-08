#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr dat;
    dat.push_back("7");
    dat.push_front("8");
    dat.push_back("9");
    std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;
    std::cout << dat.size() << std::endl; 
    dat.pop_front();
    std::cout << dat.get(0) << std::endl;
    dat.push_front("19");
    dat.pop_back();
    std::cout << dat.get(1) << std::endl;
    dat.pop_back();
    dat.pop_back();
    dat.pop_back();
    dat.pop_back();
    std::cout << dat.size() << std::endl;
    dat.push_front("2");
    dat.push_back("11");
    std::cout << dat.front() << std::endl;
    std::cout << dat.back() << std::endl;
    dat.clear();
    for (int i = 0; i < 30; i++) {
        dat.push_front(std::to_string(i));
    }
    std::cout << dat.get(0) << " " << dat.get(23) << " " << dat.get(35) << std::endl;






}
