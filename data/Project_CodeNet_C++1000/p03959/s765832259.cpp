#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n;
  cin >> n;
  vector<ll> t(n), a(n);
  rep(i, n) cin >> t[i];
  rep(i, n) cin >> a[i];

  vector<ll> minth(n), maxth(n);
  minth[0] = t[0], maxth[0] = t[0];
  FOR(i, 1, n) {
    minth[i] = (t[i - 1] == t[i] ? 1 : t[i]);
    maxth[i] = t[i];
  }
  vector<ll> minah(n), maxah(n);
  minah[n - 1] = a[n - 1], maxah[n - 1] = a[n - 1];
  repr(i, n - 2) {
    minah[i] = (a[i] == a[i + 1] ? 1 : a[i]);
    maxah[i] = a[i];
  }

  ll ans = 1;
  rep(i, n) {
    ll minh = max(minth[i], minah[i]), maxh = min(maxth[i], maxah[i]);
    if (maxh - minh + 1 <= 0) {
      cout << 0 << '\n';
      return 0;
    }
    ans = ans * (maxh - minh + 1) % mod;
  }
  cout << ans << '\n';




  
  return 0;
}