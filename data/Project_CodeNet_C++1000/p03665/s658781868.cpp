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

constexpr ll MOD = 1000000007;

int d[51][5001];

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, p; cin >> n >> p;
  vi a(n);

  rep(i, n) cin >> a[i];

  d[0][0] = 1;
  
  rep(i, n) rep(j, 5001) {
    if (j-a[i] >= 0) d[i+1][j] += d[i][j-a[i]];
    d[i+1][j] += d[i][j];
  }

  int ans = 0;
  rep(i, 5001) if (i % 2 == p) ans += d[n][i];

  cout << ans << endl;

  return (0);
}
