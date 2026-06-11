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

  string s, t;
  cin >> s >> t;

  vll x(s.size() + 1);
  vll y(t.size() + 1);
  rep(i, s.size()) {
    ll add = (s[i] == 'A') ? 2 : 1;
    x[i + 1] = x[i] + add;
  }

  rep(i, t.size()) {
    ll add = (t[i] == 'A') ? 2 : 1;
    y[i + 1] = y[i] + add;
  }

  ll q;
  cin >> q;
  rep(i, q) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((x[b] - x[a - 1]) % 3 == (y[d] - y[c - 1]) % 3) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
