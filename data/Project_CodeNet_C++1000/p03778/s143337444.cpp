#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int w, a, b;
  std::cin >> w >> a >> b;
  if (w < b - a)
  {
    std::cout << b - a - w << std::endl;
  }
  else if (b - a <= w && a <= b)
  {
    std::cout << 0 << std::endl;
  }
  else if (b < a && a - b < w)
  {
    std::cout << 0 << std::endl;
  }
  else
  {
    std::cout << a - b - w << std::endl;
  }
  return 0;
}