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
map<i64, i64> mp;

bool f() {
  if (mp.size() >= 3) return false;

  vector<i64> col, cnt;
  i64 i = 0;
  for (auto p : mp) {
    col.push_back(p.first);
    cnt.push_back(p.second);
  }

  if (mp.size() == 1) {
    if (col[0] <= n / 2 || col[0] == n - 1) return true;
    return false;
  }

  if (col[0] + 1 != col[1] || cnt[1] == 1) return false;

  if (cnt[0] <= col[0] && 
      col[0] < cnt[0] + cnt[1] / 2) return true;
  return false;
}

// a b b b b b
// 1 2 2 2 2 2
//
// a b b c c c
// 2 3 3 3 3 3
//
// a b c c c c
// 2 2 3 3 3 3
//
// a b c c d d
// 3 3 4 4 4 4
//
// a b c d d d
// 3 3 3 4 4 4
//
// a b c d e e
// 4 4 4 4 5 5

int main() {
  cin >> n;
  for (i64 i = 0; i < n; ++i) {
    i64 a;
    cin >> a;
    mp[a]++;
  }
  cout << (f() ? "Yes" : "No") << endl;
  return 0;
}
