#include <iostream>
#include <string>
int main()
{  
  int A, B;
  std::string op;
  
  std::cin >> A >> op >> B;
  
  if(op == "+")
  {
    std::cout << A + B;
  }
  else
  {
    std::cout << A - B;
  }
  
  return 0;
}