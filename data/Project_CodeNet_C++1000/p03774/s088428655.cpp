#include <bits/stdc++.h>

#define fi first
#define se second
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define endl '\n'

#define si(v) int(v.size())
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep2(i, n, m) for (ll i = n; i <= (m); ++i)
#define rep3(i, n, m) for (ll i = n; i >= (m); --i)

template<class T, class U> void chmax(T &a, U b) { if (a < b) a = b; }
template<class T, class U> void chmin(T &a, U b) { if (b < a) a = b; }

using ll = long long;
using ld = long double;
using namespace std;

constexpr ll MOD = 1000000007;

signed main()
{
  cout << fixed << setprecision(20);
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m; cin >> n >> m;

  vpi st(n), check(m);
  rep(i, n) cin >> st[i].fi >> st[i].se;
  rep(i, m) cin >> check[i].fi >> check[i].se;

  rep(i, n) {
    int idx = 0;

    rep(j, m) {
      int diff = abs(st[i].fi - check[j].fi) + abs(st[i].se - check[j].se);
      if (diff < abs(st[i].fi - check[idx].fi) + abs(st[i].se - check[idx].se)) idx = j;
    }

    cout << idx+1 << endl;
  }
  
  return (0);
}