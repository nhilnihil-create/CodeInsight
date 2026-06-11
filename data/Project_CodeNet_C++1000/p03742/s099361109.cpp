#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

/*
int memo[1000][1000];
bool rec(lli x, lli y) {
  if (memo[x][y]) return memo[x][y] - 1;
  if (x == 0 && y == 0) return false;
  bool res = false;
  for (lli i=2; i<=x; i+=2) {
    res = res || !rec(x-i, y+i/2);
  }
  for (lli i=2; i<=y; i+=2) {
    res = res || !rec(x+i/2, y-i);
  }
  memo[x][y] = int(res) + 1;
  return res;
}

lli x, y;
int main() {
  cin >> x >> y;
  rec(x, y);
  cout << boolalpha;
  for (lli i=0; i<=x; ++i) {
    for (lli j=0; j<=y; ++j) {
      cout << i << ',' << j << '\t' << rec(i, j) << endl;
    }
  }
  return 0;
}
*/

int main() {
  lli x, y; cin >> x >> y;
  lli d = x - y;
  if (-1 <= d && d <= 1) cout << "Brown\n";
  else cout << "Alice\n";
  return 0;
}

