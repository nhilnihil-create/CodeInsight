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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll ans = LINF;
  rep(i, 1<<n) {
    if (__builtin_popcount(i) != k)
      continue;
    ll sum = 0, prev = 0;
    rep(j, n) {
      if (i>>j & 1) {
        sum += max(prev+1-a[j], 0LL);
        prev++;
      }
      chmax(prev, a[j]);
    }
    chmin(ans, sum);
  }
  cout << ans << endl;
  return 0;
}