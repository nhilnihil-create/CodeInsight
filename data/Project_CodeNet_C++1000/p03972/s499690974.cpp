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
#include <functional>

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
  vector<ii> a;
  int x;
  int64 ret = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    a.push_back({x, 0});
    ret += (int64)x * (m + 1);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &x);
    a.push_back({x, 1});
    ret += (int64)x * (n + 1);
  }
  sort(a.begin(), a.end(), [](const ii x, const ii y) {
      return x.first < y.first;
    });
  int cnt[2] = {0};
  for (auto& it : a) {
    int x = it.first, k = it.second;
    ret -= (int64)cnt[1 - k] * x;
    ++cnt[k];
  }
  printf("%lld\n", ret);
  return 0;
}
