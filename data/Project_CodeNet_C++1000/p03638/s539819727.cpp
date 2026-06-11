#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define INF 1e9;
using namespace std;
typedef long long ll;
int main() {
  ll h, w, n;
  cin >> h >> w >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  vector<vector<ll>> ans(h, vector<ll>(w));

  ll now = 1;
  REP(i, h) {
    if (i % 2 == 0) {
      REP(j, w) {
        ans[i][j] = now;
        --a[now - 1];
        if (a[now - 1] == 0) now++;
      }
    } else {
      REPR(j, w - 1) {
        ans[i][j] = now;
        --a[now - 1];
        if (a[now - 1] == 0) now++;
      }
    }
  }
  REP(i, h) {
    REP(j, w) { cout << ans[i][j] << " "; }
    cout << endl;
  }
  return 0;
}