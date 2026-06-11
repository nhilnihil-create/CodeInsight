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

lli n;
vector<lli> p;
int main() {
  cin >> n; read_n(p, n, 1);
  lli ans = 0;
  for (lli i=1; i<=n-1; ++i) {
    if (p[i]==i && p[i+1]==i+1) {
      swap(p[i], p[i+1]);
      ++ans;
    }
  }
  for (lli i=1; i<=n; ++i) {
    if (p[i]==i) ++ans;
  }
  cout << ans << endl;
  return 0;
}

