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

template <typename T>
class SegTree {
  int n;
  vector<T> data;
  T default_value;
  function<T(T a, T b)> operation;
  function<T(T prev_val, T new_val)> _update;

  // [a,b)
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return default_value;
    }

    if (a <= l && r <= b) {
      return data[k];
    } else {
      T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
      T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
      return operation(vl, vr);
    }
  }

 public:
  SegTree(int _n, T _default_value, function<T(T a, T b)> _operation,
          function<T(T prev_val, T new_val)> update_function)
    : default_value(_default_value), operation(_operation), _update(update_function) {
    n = 1;
    while (n < _n) {
      n <<= 1;
    }
    data = vector<T>(2 * n - 1, default_value);
  }

  SegTree(vector<T> initial_value, T _default_value, function<T(T a, T b)> _operation,
          function<T(T prev_val, T new_val)> update_function)
    : default_value(_default_value), operation(_operation), _update(update_function) {
    ll sz = initial_value.size();
    n = 1;
    while (n < sz) {
      n <<= 1;
    }
    data = vector<T>(2 * n - 1, default_value);
    for (int i = 0; i < sz; i++) {
      data[n - 1 + i] = initial_value[i];
    }
    for (int i = n - 2; i >= 0; i--) {
      data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  // update i-th value (0-indexed)
  void update(int i, T x) {
    i += n - 1;
    data[i] = _update(data[i], x);
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  // execute query of section [a, b)
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  // get i-th value
  T operator[](int i) {
    return data[i + n - 1];
  }
};

#if 0
void sample_func() {
  // get max
  SegTree<ll> st(
    n, 0ll, [](ll a, ll b) { return max(a, b); }, [](ll prev_val, ll new_val) { return new_val; });

  // get min
  SegTree<ll> st(
    n, INF, [](ll a, ll b) { return min(a, b); }, [](ll prev_val, ll new_val) { return new_val; });
}
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n, m;
  cin >> n >> m;

  vvll a(n, vll(m));
  rep(i, n) {
    rep(j, m) {
      ll tmp;
      cin >> tmp;
      tmp--;
      a[i][j] = tmp;
    }
  }

  vvll order(n, vll(n));

  vector<SegTree<P>> st(
    n, SegTree<P>(
         m, make_pair(INF, 0ll), [](P a, P b) { return min(a, b); }, [](P prev_val, P new_val) { return new_val; }));

  rep(i, n) {
    ll v = 0;
    rep(j, m) {
      ll idx = a[i][j];
      st[i].update(idx, make_pair(v++, idx));
    }
  }

  auto bkup = st;

  ll l = 1, r = n;

  while (l < r) {
    st = bkup;

    ll c = (l + r) / 2;
    bool ok = false;
    rep(i, m) {
      vll kyogi(m);
      rep(i, n) {
        ll like = st[i].query(0, m).second;
        kyogi[like]++;
      }
      int max_idx = distance(kyogi.begin(), max_element(all(kyogi)));
      if (kyogi[max_idx] <= c) {
        ok = true;
        break;
      }
      rep(i, n) {
        st[i].update(max_idx, make_pair(INF, INF));
      }
    }

    if (ok) {
      r = c;
    } else {
      l = c + 1;
    }
  }

  cout << l << endl;

  return 0;
}
