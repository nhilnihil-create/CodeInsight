#include <iostream>
#include <string>

int main()
{
  std::string s;
  std::cin >> s;
  
  for(int i = 0; s[i] != NULL; i++)
  {
    if(i % 2 == 0)
    {
      std::cout << s[i];
    }
  }
  
  return 0;
}