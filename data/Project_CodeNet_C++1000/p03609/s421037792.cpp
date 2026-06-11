#include <iostream>

int main()
{
  long int x, t;
  
  std::cin >> x >> t;

  if (x-t > 0) {
    std::cout << x-t << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
