#include <iostream>
#include <string>

int main()
{  
  std::string haiku;
  std::cin >> haiku;
  
  haiku.replace(5, 1, " ");
  haiku.replace(13, 1, " ");
  
  std::cout << haiku;
  
  return 0;
}