#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vl a(n);
  REP(i, n) { cin >> a[i]; }
  ll ans = 1e11;
  REP(i, (1 << n)) {
    ll tmp = 0;
    int vis = 1;
    ll ma = a[0];
    FOR(j, 1, n) {
      if ((i >> j) % 2 == 1 && a[j] <= ma) {
        tmp += ma - a[j] + 1;
        ma = ma + 1;
        vis++;
      } else if (a[j] > ma) {
        vis++;
      }
      ma = max(ma, a[j]);
    }
    if (vis >= k) {
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
