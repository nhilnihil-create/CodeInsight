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
  
  ll n; cin >> n;

  auto f = [&](ll x) {
    int res = 0;
    while (x) {
      x /= 10;
      ++res;
    }
    return res;
  };

  ll ans = MOD;
  rep2(i, 1, sqrt(n)) {
    if (n % i == 0) {
      ll a = i, b = n / i;
      chmin(ans, max(f(a), f(b)));
    }
  }

  cout << ans << endl;
  
  return (0);
}