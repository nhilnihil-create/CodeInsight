#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) FOR(i, n, 0);

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  int n; cin >> n;
  vector<int> a(n), sum(n);
  int su = 0;
  REP(i, n) cin >> a[i];
  REP(i, n) {
    su += a[i];
    sum[i] = su;
  }
  int ans = abs(2 * sum[0] - sum[n-1]);
  FOR(i, 1, n-1) {
    ans = min(ans, abs(2 * sum[i] - sum[n-1]));
  }
  cout << ans << endl;
}
