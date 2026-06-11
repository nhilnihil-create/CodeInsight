#include <iostream>
#include <string>

int main()
{  
  std::string a, b;
  std::cin >> a >> b;
  
  for(int i = 0; a[i] != NULL; i++)
  {
    if(b[i] != NULL)
    {
      std::cout << a[i] << b[i];
    }
    else
    {
      std::cout << a[i];
    }
  }

  return 0;
}