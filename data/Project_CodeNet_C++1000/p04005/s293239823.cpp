#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
    std::cout << 0;
  else
    std::cout << std::min(1LL * a * b, std::min(1LL * a * c, 1LL * b * c));
  return 0;
}
