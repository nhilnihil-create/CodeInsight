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

lli i, o, t, j, l, s, z;
int main() {
  cin >> i >> o >> t >> j >> l >> s >> z;
  lli ans = o;
  if (i>0 && j>0 && l>0
      && ((j%2==1 && l%2==1)
      || (i%2==1 && j%2==1)
      || (i%2==1 && l%2==1))) {
    --i; --j; --l;
    ans += 3;
  }
  ans += i/2*2 + j/2*2 + l/2*2;
  cout << ans << endl;
  return 0;
}

