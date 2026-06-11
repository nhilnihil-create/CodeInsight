#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 2000;
ll v[1 + nmax], part[1 + nmax];

int main() {
  ll n, x;
  std::cin >> n >> x;
  for(int i = 0;i < n; i++) {
    std::cin >> v[i];
    part[i] = v[i];
  }
  ll result = 1LL * nmax * 1000000000, sum = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      part[j] = std::min(part[j], v[(j + n - i) % n]);
    sum = 0;
    for(int j = 0; j < n; j++)
      sum += part[j];
    result = std::min(result, sum + i * x);
  }
  std::cout << result;
  return 0;
}
