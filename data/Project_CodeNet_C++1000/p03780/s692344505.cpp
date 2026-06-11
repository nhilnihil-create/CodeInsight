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

  ll n, k;
  cin >> n >> k;

  vll a(n + 1);
  ll nl = 0;
  ll nh = 0;
  REP(i, n + 1) {
    cin >> a[i];
  }

  if (nh > 0) {
    cout << nl << endl;
    return 0;
  }

#if 0
  vvi ldp(n + 2, vi(k + 1));
  vvi rdp(n + 2, vi(k + 1));
#else
  using vc = vector<char>;
  using vvc = vector<vc>;
  vvc ldp(n + 2, vc(k + 1));
  vvc rdp(n + 2, vc(k + 1));
#endif

  ldp[0][0] = 1;
  rdp[n + 1][0] = 1;

  REP(i, n + 1) {
    rep(j, k) {
      ldp[i][j] |= ldp[i - 1][j];
      if (j + a[i] < k) {
        ldp[i][j + a[i]] |= ldp[i - 1][j];
      } else {
        ldp[i][k] = ldp[i - 1][j];
      }
    }
  }

  for (ll i = n; i >= 1; i--) {
    rep(j, k) {
      rdp[i][j] |= rdp[i + 1][j];
      if (j + a[i] < k) {
        rdp[i][j + a[i]] |= rdp[i + 1][j];
      } else {
        rdp[i][k] = rdp[i + 1][j];
      }
    }
  }

  ll ans = n;

  REP(i, n + 1) {
    vll l, r;
    rep(j, k + 1) {
      if (ldp[i - 1][j]) {
        l.push_back(j);
      }
      if (rdp[i + 1][j]) {
        r.push_back(j);
      }
    }

    // (k - a[i]) <= (l[i] + r[j]) < k
    // となるl, rの組を探す
    for (auto val : l) {
      ll tl = k - a[i] - val;
      ll tr = k - val;

      auto itr = lower_bound(all(r), tl);
      if (itr != r.end() && *itr < tr) {
        ans--;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
