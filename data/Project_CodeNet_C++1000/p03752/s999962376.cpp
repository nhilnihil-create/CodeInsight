#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())
template <class T> bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T> using V = vector<T>;
using P = pair<int, int>;

/*
 *  *  */

signed main() {
  int n, k;
  cin >> n >> k;

  V<int> a(n);
  rep(i, 0, n) cin >> a[i];

  int ans = 1LL<<60;
  rep(mask, 0, 1<<n){
    if(__builtin_popcount(mask) < k) continue;
    int cost = 0, h = -1;
    rep(i, 0, n){
      if(mask>>i & 1){
        cost += max(0LL, h+1-a[i]);
        h++;
      }
      chmax(h, a[i]);
    }

    chmin(ans, cost);
  }

  cout << ans << endl;

  return 0;
}
