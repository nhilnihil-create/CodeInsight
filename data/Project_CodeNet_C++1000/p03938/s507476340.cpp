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

  ll n;
  cin >> n;
  vll p(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }

  vll order(n);
  rep(i, n) {
    order[p[i]] = i;
  }

  vll a(n), b(n);
  a[0] = 4e8 + order[0];
  b[0] = 4e8;

  REP(i, n) {
    a[i] = a[i - 1] + 1;
    b[i] = b[i - 1] - 1;
    if (order[i] > order[i - 1]) {
      a[i] += abs(order[i] - order[i - 1]);

    } else {
      b[i] -= abs(order[i] - order[i - 1]);
    }
  }

  for (auto it : a)
    cout << it << " ";
  cout << endl;
  for (auto it : b)
    cout << it << " ";
  cout << endl;

  return 0;
}
