#include <iostream>

int main()
{
  int a, b, c, d;

  std::cin >> a >> b >> c >> d;

  if (a*b >= c*d) {
    std::cout << a*b << std::endl;
  } else {
    std::cout << c*d << std::endl;
  }

  return 0;
}
