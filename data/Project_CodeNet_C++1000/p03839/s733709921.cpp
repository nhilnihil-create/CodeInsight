#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll v[1 + nmax];
ll sum[1 + nmax];
ll pref[1 + nmax], suff[1 + nmax];

int main() {
  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    sum[i] = sum[i - 1] + v[i];
  for(int i = 1; i <= n; i++)
    pref[i] = pref[i - 1] + std::max(0LL, v[i]);
  for(int i = n; 1 <= i; i--)
    suff[i] = suff[i + 1] + std::max(0LL, v[i]);
  ll result = 0;
  for(int i = k; i <= n; i++)
    result = std::max(result, pref[i - k] + suff[i + 1] + std::max(sum[i] - sum[i - k], 0LL));
  std::cout << result;
  return 0;
}
