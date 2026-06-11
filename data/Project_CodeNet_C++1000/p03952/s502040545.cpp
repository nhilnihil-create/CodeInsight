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

  ll n, x;
  cin >> n >> x;

  if (n == 2) {
    if (x == 2) {
      cout << "Yes" << endl;
      REP(i, 4) {
        cout << i << endl;
      }
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << endl;
    return 0;
  }

  vb used(2 * n);
  deque<ll> ans;
  ans.push_back(x);
  used[x] = true;

  if (x == 2) {
    ans.push_front(x - 1);
    ans.push_front(x + 1);
    ans.push_back(x + 2);
    used[x - 1] = true;
    used[x + 1] = true;
    used[x + 2] = true;
  } else {
    ans.push_front(x + 1);
    ans.push_front(x - 1);
    ans.push_back(x - 2);
    used[x - 1] = true;
    used[x + 1] = true;
    used[x - 2] = true;
  }

  ll cnt = 0;
  REP(i, 2 * n) {
    if (used[i])
      continue;

    if (cnt % 2 == 0) {
      ans.push_back(i);
    } else {
      ans.push_front(i);
    }
    cnt++;
  }

  cout << "Yes" << endl;
  for (auto it : ans) {
    cout << it << endl;
  }

  return 0;
}
