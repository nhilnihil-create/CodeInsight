#include <iostream>

int main()
{
  int a, b, c;
  int ans;

  std::cin >> a >> b >> c;
  int max = a;

  if (max < b) {
    max = b;
  }
  if (max < c) {
    max = c;
  }

  ans = a + b + c - max;

  std::cout << ans << std::endl;

  return 0;
}
