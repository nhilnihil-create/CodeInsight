#include <iostream>
#include <string>
#include <regex>
 
int main() {
    std::string str;
    std::cin >> str;
    std::regex re(",+");
    std::string format = " ";
 
    std::cout << std::regex_replace(str, re, format) << std::endl;
 
    return 0;
}