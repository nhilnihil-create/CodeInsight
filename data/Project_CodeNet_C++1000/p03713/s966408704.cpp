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

  ll h, w;
  cin >> h >> w;

  if (h % 3 == 0 || w % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = INF;

  rep(c, 2) {
    if (h >= 3) {
      chmin(ans, w);
    }
    FOR(x, w / 3, w / 3 + 3) {
      FOR(y, h / 2, h / 2 + 2) {
        if (x > w || y > h)
          continue;

        ll a = x * h;
        ll b = (w - x) * y;
        ll c = w * h - a - b;
        ll mx = a;
        ll mn = a;
        chmax(mx, b);
        chmax(mx, c);
        chmin(mn, b);
        chmin(mn, c);
        ll v = mx - mn;
        chmin(ans, v);
      }
    }
    swap(w, h);
  }

  cout << ans << endl;

  return 0;
}
