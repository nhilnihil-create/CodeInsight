#include <bits/stdc++.h>

#define fi first
#define se second
#define ep emplace_back
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
  
  map<int,int> mp;
  rep(i, m) {
    int a, b; cin >> a >> b;
    ++mp[a], ++mp[b];
  }

  rep2(i, 1, n) cout << mp[i] << endl;
  
  return (0);
}