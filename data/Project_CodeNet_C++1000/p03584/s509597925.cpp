#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

bool check(int x, int y) {
  rep(i, 30) {
    if (!(x>>i&1) && y>>i&1)
      return false;
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  ll ans = 0;
  for (int i = 30; i >= 0; i--) {
    if (k>>i&1) {
      int x = 0;
      for (int j = 30; j >= 0; j--) {
        if (j > i)
          x |= k&1<<j;
        if (j < i)
          x |= 1<<j;
      }
      ll res = 0;
      rep(j, n) {
        if (check(x, a[j]))
          res += b[j];
      }
      chmax(ans, res);
    }
  }
  ll res = 0;
  rep(i, n) {
    if (check(k, a[i]))
      res += b[i];
  }
  chmax(ans, res);
  cout << ans << endl;
  return 0;
}