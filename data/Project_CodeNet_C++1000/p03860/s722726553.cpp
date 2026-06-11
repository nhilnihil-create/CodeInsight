#include <iostream>
#include <string>

int main(void){
  std::string str;
  std::cin >> str >> str;
  std::cout << 'A' << str.at(0) << 'C' << std::endl;
  return 0;
}