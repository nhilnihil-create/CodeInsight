#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const ll INF = 1e18;

signed main() {
  int n,k;
  int a[15];
  cin >> n >> k;
  rep(i,n) cin >> a[i];

  ll ans = INF;
  rep(b, 1<<n) {
    if(__builtin_popcountll(b) != k) continue;
    ll s = 0;
    int maxh = 0;
    rep(i, n) {
      if ((b & 1<<i) && (maxh >= a[i])) {
        s += maxh - a[i] + 1;
        maxh++;
      }
      maxh = max(maxh, a[i]);
    }
    ans = min(ans, s);
  }
  cout << ans << endl;

}
