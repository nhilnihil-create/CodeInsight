#include <bits/stdc++.h>

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> void chmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> void chmin(T &a, U b) { if (b < a) a = b; }

using ll = long long;
using ld = long double;
using namespace std;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int w, h, n; cin >> w >> h >> n;
  
  int mat[h][w];
  rep(i, h) rep(j, w) mat[i][j] = 0;
  
  rep(i, n) {
    int x, y, a; cin >> x >> y >> a;

    if (a == 1) rep(k, h) rep(j, x) mat[k][j] = 1;
    else if (a == 2) rep(k, h) rep2(j, x, w-1) mat[k][j] = 1;
    else if (a == 3) rep(k, y) rep(j, w) mat[k][j] = 1;
    else rep2(k, y, h-1) rep(j, w) mat[k][j] = 1;
  }

  int ans = 0;
  rep(i, h) rep(j, w) ans += mat[i][j];

  cout << h * w - ans << endl;
  
  return (0);
}