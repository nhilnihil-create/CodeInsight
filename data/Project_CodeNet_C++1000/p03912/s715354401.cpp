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
const int INF = 1 << 30;
const int MOD = 1e9 + 7;

const int N = 1e5 + 10;
vector<int> a[N];
int cnt[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    int u = x % m;
    a[u].push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    sort(a[i].begin(), a[i].end());
    for (int j = 0, k; j < a[i].size(); j = k) {
      for (k = j + 1; k < a[i].size() && a[i][j] == a[i][k]; ++k);
      cnt[i] += (k - j) / 2;
    }
  }
  int ret = 0;
  for (int i = 0; i * 2 <= m; ++i) {
    int j = m - i;
    if (i == 0 || i == j) {
      ret += a[i].size() / 2;
    } else {
      int cur = min(a[i].size(), a[j].size());
      ret += cur;
      ret += min(cnt[i], ((int)a[i].size() - cur) / 2);
      ret += min(cnt[j], ((int)a[j].size() - cur) / 2);
    }
  }
  printf("%d\n", ret);
  return 0;
}
