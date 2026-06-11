#include <bits/stdc++.h>
using namespace std;

// boost
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;
using vld = vector<ld>;
using vvld = vector<vld>;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
// #define mod (998244353ll)

const long long INF = 1LL << 60;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll w, h;
  cin >> w >> h;

  vll p(w);
  vll q(h);
  rep(i, w) cin >> p[i];
  rep(i, h) cin >> q[i];

  sort(all(p));
  sort(all(q));
  ll ans = 0;
  for (auto it : p) {
    ll v = lower_bound(all(q), it) - q.begin();
    ans += (h + 1 - v) * it;
  }

  for (auto it : q) {
    ll v = upper_bound(all(p), it) - p.begin();
    ans += (w + 1 - v) * it;
  }

  cout << ans << endl;

  return 0;
}
