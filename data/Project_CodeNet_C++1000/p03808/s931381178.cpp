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
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli n;
vector<lli> a;
int main() {
  cin >> n; read_n(a, n);
  lli sum = 0;
  for (lli x : a) sum += x;
  lli k = n*(n+1)/2;
  if (sum % k != 0) { cout << "NO" << endl; return 0; }
  lli d = sum / k;
  bool ok = true;
  for (lli i=0; i<n; ++i) {
    lli x = a[i], y = a[(i+1)%n];
    if (y - x > d) ok = false; 
    if (y - x < d) {
      if ((y - x - d) % n != 0) ok = false;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
