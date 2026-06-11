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
  
  int n, m; cin >> n >> m;
  char a[n][n], b[m][m];

  rep(i, n) rep(j, n) cin >> a[i][j];
  rep(i, m) rep(j, m) cin >> b[i][j];

  rep(i, n - m + 1) rep(j, n - m + 1) {
    bool ok = true;
    rep(k, m) rep(l, m) if (a[i+k][j+l] != b[k][l]) ok = false;

    if (ok) {
      cout << "Yes\n";
      return (0);
    }
  }

  cout << "No\n";
  
  return (0);
}