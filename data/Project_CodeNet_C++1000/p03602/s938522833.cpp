#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli n, sum;
lli a[301][301];
bool b[301][301];
int main() {
  cin >> n;
  sum = 0;
  for (lli j=0; j<n; ++j) {
    for (lli i=0; i<n; ++i) {
      cin >> a[i][j];
      sum += a[i][j];
    }
  }
  sum /= 2;
  for (lli j=0; j<n; ++j) fill(begin(b[j]), end(b[j]), false);

  for (lli k=0; k<n; ++k) {
    for (lli j=0; j<n; ++j) {
      if (k==j) continue;
      for (lli i=j+1; i<n; ++i) {
        if (k==i) continue;
        lli c = a[i][j], d = a[i][k] + a[k][j];
        if (c > d) { cout << -1 << endl; return 0; }
        if (c == d && !b[i][j]) {
          sum -= c;
          b[i][j] = true;
        }
      }
    }
  }
  cout << sum << endl;
  return 0;
}

