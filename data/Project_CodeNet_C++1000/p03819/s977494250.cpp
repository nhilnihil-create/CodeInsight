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

const int N = 1e5 + 10;
int c[N];

void add(int x, int y, int n) {
  for (; x <= n; x += x & -x) {
    c[x] += y;
  }
}

int query(int x) {
  int ret = 0;
  for (; x; x -= x & -x) {
    ret += c[x];
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<ii> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }
  sort(a.begin(), a.end(), [](const ii& a, const ii& b) {
      return a.second - a.first < b.second - b.first;
    });
  int k = 0;
  for (int i = 1; i <= m; ++i) {
    while (k < n && a[k].second - a[k].first + 1 < i) {
      add(a[k].first, 1, m);
      add(a[k].second + 1, -1, m);
      ++k;
    }
    int cur = n - k;
    for (int j = i; j <= m; j += i) {
      cur += query(j);
    }
    printf("%d\n", cur);
  }
  return 0;
}
