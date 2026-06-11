#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 20000;


int main() {
  int x, y;
  std::cin >> x >> y;
  if(0 <= x && x <= y)
    std::cout << y - x;
  else if(x <= y && y <= 0) 
    std::cout << y - x;
  else {
    int coef = fabs(fabs(x) - fabs(y));
    if(0 < x && 0 < y)
      std::cout << coef + 2;
    else if(x < 0 && y < 0)
      std::cout << coef + 2;
    else
      std::cout << 1 + coef;
  }

  return 0;
}
