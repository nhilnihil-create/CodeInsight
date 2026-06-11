#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  int a, b;
  std::cin >> a >> b;
  if(a <= 0 && 0 <= b)
    std::cout << "Zero";
  else if(0 < a)
    std::cout << "Positive";
  else if(b < 0) {
    int sum = a + b;
    if(sum % 2 == 0)
      std::cout << "Negative";
    else
      std::cout << "Positive";
  }
  return 0;
}
