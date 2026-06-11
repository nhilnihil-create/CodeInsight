#include <iostream>

int main(void){
  int a, b;
  char op;
  std::cin >> a >> op >> b;
  switch(op){
    case '+': std::cout << a + b << std::endl; break;
    case '-': std::cout << a - b << std::endl; break;
  }
  return 0;
}