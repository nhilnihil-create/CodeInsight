#include <iostream>

int main()
{
  uint64_t x;
  std::cin >> x;

  uint64_t ret = 2 * (x/11);
  x %= 11;

  if(x == 0 ) {
  } else if(x<=6) {
    ret += 1;
  } else if(x < 11) {
    ret += 2;
  }

  std::cout << std::fixed << ret << std::endl;
  return 0;
}
