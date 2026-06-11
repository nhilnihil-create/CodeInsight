#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int a[1 + nmax], b[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> a[i] >> b[i];
  ll result = 0;
  for(int i = n; 1 <= i; i--) {
    if((a[i] + result) % b[i] == 0)
      continue;
    else 
      result += b[i] - (a[i] + result) % b[i];
  }
  std::cout << result;
  return 0;
}
