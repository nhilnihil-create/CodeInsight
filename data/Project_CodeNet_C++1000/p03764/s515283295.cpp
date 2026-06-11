#define _USE_MATH_DEFINES
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }
  int L = 0;
  for (int i = 1; i < n; ++i) {
    L += (int64)i * (n - i) % MOD * (a[i] - a[i - 1]) % MOD;
    L %= MOD;
  }
  int R = 0;
  for (int i = 1; i < m; ++i) {
    R += (int64)i * (m - i) % MOD * (b[i] - b[i - 1]) % MOD;
    R %= MOD;
  }
  printf("%lld\n", (int64)L * R % MOD);
  return 0;
}
