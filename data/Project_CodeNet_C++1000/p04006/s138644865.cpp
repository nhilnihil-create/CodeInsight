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

ll dp[2000][2000] = {};

int main() {
  int n;
  cin >> n;
  ll x;
  cin >> x;
  vl a(n);
  REP(i, n) { cin >> a[i]; }

  REP(i, n) { dp[0][i] = a[i]; }
  FOR(i, 1, n) {
    REP(j, n) {
      int idx = j - i >= 0 ? j - i : n + (j - i);
      dp[i][j] = min(a[idx], dp[i - 1][j]);
    }
  }

  ll ans = 1e18;
  REP(i, n) {
    ll tmp = 0;
    REP(j, n) { tmp += dp[i][j]; }
    ans = min(tmp + i * x, ans);
  }
  cout << ans << endl;
}
