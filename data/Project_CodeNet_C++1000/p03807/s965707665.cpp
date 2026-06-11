#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  int n;
  std::cin >> n;
  int even = 0, odd = 0;
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    if(val % 2 == 0)
      even++;
    else
      odd++;
  }
  even += odd / 2;
  odd %= 2;
  if(0 < even && 0 < odd)
    std::cout << "NO";
  else
    std::cout << "YES";
  return 0;
}
