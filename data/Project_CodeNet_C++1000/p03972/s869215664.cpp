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

struct Es {
  lli c, h, v;
};
bool operator<(const Es& e, const Es& f) { return e.c < f.c; }

lli w, h, p[100001], q[100001];
vector<Es> es;
int main() {
  cin >> w >> h;
  for (lli i=0; i<w; ++i) {
    lli c; cin >> c;
    es.push_back({ c, -1, i });
  }
  for (lli i=0; i<h; ++i) {
    lli c; cin >> c;
    es.push_back({ c, i, -1 });
  }
  sort(begin(es), end(es));

  lli ans = 0, ver = w + 1, hol = h + 1;
  for (const Es& e : es) {
    if (e.h >= 0) {
      ans += ver * e.c;
      --hol;
    } else {
      ans += hol * e.c;
      --ver;
    }
    cerr << e.c << ' ' << ans << endl;
  }
  cout << ans << '\n';
  return 0;
}

