#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

i64 n;
vector<i64> a;
int main() {
  cin >> n;
  read_n(a, n, 1);

  map<i64, i64> left, cnt;
  for (i64 i = n; i > 0; --i) {
    left[a[i]] = i;
    cnt[a[i]]++;
  }

  vector<i64> xs;
  xs.push_back(0);
  for (auto p : left) {
    xs.push_back(p.first);
  }

  vector<i64> ans(n + 1);
  for (i64 i = xs.size() - 1, l = n, c = 0; i > 0; --i) {
    i64 x = xs[i];
    l = min(l, left[x]);
    c += cnt[x];
    ans[l] += c * (x - xs[i - 1]);
  }

  for (i64 i = 1; i <= n; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
