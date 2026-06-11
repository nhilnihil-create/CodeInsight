#include <iostream>
#include <string>

int main()
{  
  std::string s;
  std::cin >> s;
  
  int length = s.rfind("Z") - s.find("A") + 1;

  std::cout << length;
  return 0;
}