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
  
  int n; cin >> n;

  set<int> se;
  int cnt = 0;
  
  rep(i, n) {
    int r; cin >> r;
    if (r >= 3200) {
      ++cnt;
      continue;
    }
    se.emplace(r / 400);
  }

  if (se.empty()) cout << 1 << " " << cnt << endl;
  else cout << si(se) << " " << cnt + si(se) << endl;
  
  return (0);
}