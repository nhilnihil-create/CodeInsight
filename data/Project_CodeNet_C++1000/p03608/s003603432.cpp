#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3")

#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i) 
#define rep2(i, n, m) for (ll i = n; i <= (ll)(m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (ll)(m); --i)

template<class T, class U> bool chmax(T &a, U b) { if (a < b) a = b; return true; }
template<class T, class U> bool chmin(T &a, U b) { if (a > b) a = b; return true; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1e18;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, r; cin >> n >> m >> r;
  vi town(r);

  rep(i, r) cin >> town[i];

  int dp[201][201];
  rep(i, 201) rep(j, 201) {
    if (i == j) dp[i][j] = 0;
    else dp[i][j] = MOD;
  }

  rep(i, m) {
    int a, b, c; cin >> a >> b >> c;
    chmin(dp[a-1][b-1], c);
    chmin(dp[b-1][a-1], c);
  }

  rep(k, n) rep(i, n) rep(j, n) {
    if (dp[i][k] == MOD || dp[k][j] == MOD) continue;
    if (dp[i][j] > dp[i][k] + dp[k][j]) {
      dp[i][j] = dp[i][k] + dp[k][j];
    }
  }

  ll ans = MOD;
  sort(all(town));

  do {
    ll score = 0;
    rep(i, r-1) score += dp[town[i]-1][town[i+1]-1];

    chmin(ans, score);

  } while (next_permutation(all(town)));

  cout << ans << endl;

  return (0);
}
