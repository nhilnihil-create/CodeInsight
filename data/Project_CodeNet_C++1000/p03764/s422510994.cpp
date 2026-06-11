#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  int n, m;

  std::cin >> n >> m;

  long long x[111111], y[111111];

  for (int i = 0; i < n; i ++)
    std::cin >> x[i];

  for (int i = 0; i < m; i ++)
    std::cin >> y[i];

  long long a = 0, A = 0;

  for (int i = 0; i < n - 1; i ++)
    (a += (x[i + 1] - x[i]) * (i + 1) % MOD * (n - (i + 1)) % MOD) %= MOD;

  for (int i = 0; i < m - 1; i ++)
    (A += a * (y[i + 1] - y[i]) % MOD * (i + 1) % MOD * (m - (i + 1)) % MOD) %= MOD;

  std::cout << A << std::endl;

  return 0;
}
