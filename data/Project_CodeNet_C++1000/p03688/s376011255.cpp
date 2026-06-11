#include <bits/stdc++.h>

using namespace std;

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

  vll a(n);
  rep(i, n) {
    cin >> a[i];
  }

  sort(all(a));

  ll vl = *a.begin();
  ll vr = *a.rbegin();
  if (vr - vl > 1) {
    cout << "No" << endl;
    return 0;
  }

  ll nl = distance(a.begin(), upper_bound(all(a), *a.begin()));
  ll nr = n - nl;

  if (nr == 0) {
    // 帽子はvr+1色存在する？
    if (vl == n - 1 || (vl <= n / 2)) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  if (nr == 1) {
    cout << "No" << endl;
    return 0;
  }

  // 帽子はvr色存在する。
  // nl人が1人だけその帽子をかぶっている

  ll num_color = vr;
  ll original = nl;
  ll grp_people = nr;

  bool flag1 = original + grp_people / 2 >= num_color;
  bool flag2 = original + 1 <= num_color;

  if (flag1 && flag2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
