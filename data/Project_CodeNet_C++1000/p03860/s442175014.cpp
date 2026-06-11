#include<iostream>
int main(void){
  std::string C;
  std::getline(std::cin, C);
  std::cout << 'A' << char(C[8]) << 'C' << std::endl;
  return 0;
}