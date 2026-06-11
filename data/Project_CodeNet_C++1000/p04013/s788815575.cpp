#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

ll dp[55][55][2600];

int main(void){
  ll n, a;
  cin >> n >> a;
  vector<ll> x(n);
  REP(i, n) cin >> x[i];

  dp[0][0][0] = 1;
  REP(i, n) REP(j, n) REP(k, 2500){
    dp[i+1][j][k] += dp[i][j][k];
    dp[i+1][j+1][k+x[i]] += dp[i][j][k];
  }
  ll ans = 0;
  FORe(i, 1, n) ans += dp[n][i][i*a];
  cout << ans << endl;
  return 0;
}