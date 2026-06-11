#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax];

int main() {
  int n;
  ll result = 0;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++) {
    if(v[i - 1] == 1 && 0 < v[i]) {
      v[i]--;
      result++;
    }
    result += v[i] / 2;
    v[i] %= 2;
  }
  std::cout << result;
  return 0;
}
