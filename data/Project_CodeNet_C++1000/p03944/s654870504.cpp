#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll w, h, n;
  cin >> w >> h >> n;
  ll minx = 0, maxx = w, miny = 0, maxy = h;
  rep(i, n) {
    ll x, y, a;
    cin >> x >> y >> a;
    if (a == 1) chmax(minx, x);
    if (a == 2) chmin(maxx, x);
    if (a == 3) chmax(miny, y);
    if (a == 4) chmin(maxy, y);
  }

  if (minx >= maxx || miny >= maxy) cout << 0 << endl;
  else cout << (maxx - minx) * (maxy - miny) << endl;

  return 0;
}
