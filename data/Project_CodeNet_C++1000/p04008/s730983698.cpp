#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// #undef DEBUG
// #define DEBUG
/// {{{ DEBUG --- ///
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if(&o == &cerr) { o << '{'; for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? ", " : ""); o << "}"; } else { for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? " " : ""); } return o; }
#ifdef DEBUG
#ifdef USE_COUT
#define dump(...) (cout<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n")
#else
#define dump(...) (cerr<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n")
#endif
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream &o, tuple<T...> const &t){ o << "("; _ot<0>(o, t); o << ")"; return o; }
template<class T, class U> ostream & operator<<(ostream &o, pair<T, U> const &p) { o << "(" << p.first << ", " << p.second << ")"; return o; }
#else
#define dump(...) (0)
#endif
/// }}}--- ///

const int N = 1e5;
int a[N];
vector<int> g[N];
int n;
int dep[N];
int k;
int c[N];
int par[18][N];
int x = 0;
int st[N], ed[N];
int tour;

// use 2^i size by yourself
/// --- LazySegmentTree Library {{{ ///

/*
   struct Monoid {
   using T = _underlying_set_;
   static T op(const T& a, const T& b) { return _a_op_b_; }
   static constexpr T identity() { return _identity_element_; }
   };
 */

/*
   struct MM {
   using OperatorMonoid = _operator_monoid_;
   using DataMonoid = _data_monoid_;
   static T act(const OperatorMonoid::T& m, const T& a)
   { return _m_act_a; }
   };
 */

template<class MM>
struct LazySegTree {
private:
  using DM = typename MM::DataMonoid;
  using OM = typename MM::OperatorMonoid;
  using DT = typename DM::T;
  using OT = typename OM::T;
  const int n, h;
  vector<DT> data;
  vector<OT> lazy; // act

  void propFrom(int i, int sz) {
    if(lazy[i] == OM::identity()) return;
    data[i] = MM::act(lazy[i], sz, data[i]);
    if(i < n) {
      lazy[i * 2] = OM::op(lazy[i], lazy[i * 2]);
      lazy[i * 2 + 1] = OM::op(lazy[i], lazy[i * 2 + 1]);
    }
    lazy[i] = OM::identity();
  }

  void propToO(int i) {
    i += n;
    for(int j = h - 1; j >= 0; j--) propFrom(i >> j, 1 << j);
  }

  void propToD(int i) {
    i += n;
    int sz = 1;
    while(i >>= 1) propFrom(i * 2, sz), propFrom(i * 2 + 1, sz), //// important!!!
      data[i] = DM::op(data[i * 2], data[i * 2 + 1]), sz <<= 1;
  }

  void propToDataOne(int i) {
    data[i] = DM::op(data[i * 2], data[i * 2 + 1]);
  }

  int log(int x) {
    int h = 0;
    while(x >> h) h++;
    return h;
  }

public:
  LazySegTree(int n, const DT& v = DM::identity(), const OT& w = OM::identity())
    : n(n), h(log(n)), data(2 * n, v), lazy(2 * n, w) {}

  template <class InputIt>
    LazySegTree(InputIt first, InputIt last)
    : n(distance(first, last)), h(log(n)),
    data(2 * n, DM::identity()), lazy(2 * n, OM::identity()) {
      copy(first, last, begin(data) + n);
      for(int i = n - 1; i > 0; i--) propToDataOne(i);
    }

  void act(int l, int r, const OT& m) {
    l = max(0, l); r = min(r, n);
    propToO(l);
    propToO(r - 1);
    int tl = l, tr = r;
    int sz = 1;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1, sz <<= 1) {
      if(l & 1) propFrom(l, sz), lazy[l] = m, propFrom(l, sz), l++;
      if(r & 1) --r, propFrom(r, sz), lazy[r] = m, propFrom(r, sz);
    }
    propToD(tl);
    propToD(tr - 1);
  }

  void set(int i, const DT& v) {
    propToO(i);
    data[i + n] = v;
    propToD(i);
  }

  DT get(int i) {
    propToO(i);
    return data[i + n];
  }

  DT query(int l, int r) {
    l = max(0, l); r = min(r, n);
    propToO(l);
    propToO(r - 1);
    DT tmpL = DM::identity(), tmpR = DM::identity();
    int sz = 1;
    int tl = l, tr = r;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1, sz <<= 1) {
      if(l & 1) propFrom(l, sz), tmpL = DM::op(tmpL, data[l++]);
      if(r & 1) propFrom(--r, sz), tmpR = DM::op(data[r], tmpR);
    }
    return DM::op(tmpL, tmpR);
  }

  inline void dum(int r = -1) {
#ifdef DEBUG
    if(r < 0) r = n;
#ifdef USE_COUT
    for(int i = 0; i < min(r, n); i++) cout << get(i) << ", ";
    cout << endl;
#else
    for(int i = 0; i < min(r, n); i++) cerr << get(i) << ", ";
    cerr << endl;
#endif
#endif
  }
};

struct RangeMin {
  using T = long long;
  static T op(const T& a, const T& b) { return min(a, b); }
  static constexpr T identity() { return numeric_limits<T>::max(); }
};

struct RangeMax {
  using T = long long;
  static T op(const T& a, const T& b) { return max(a, b); }
  static constexpr T identity() { return numeric_limits<T>::min(); }
};

struct RangeSum {
  using T = long long;
  static T op(const T& a, const T& b) { return a + b; }
  static constexpr T identity() { return 0; }
};

struct RangeSet {
  using T = long long;
  static T op(const T& a, const T&) { return a; }
  static constexpr T identity() { return -1; }
};

// MinAdd m + a
// MinSet m
// SumAdd m * z + a
// SumSet m * z

struct RangeMinAdd {
  using OperatorMonoid = RangeSum;
  using DataMonoid = RangeMin;
  static DataMonoid::T act(const OperatorMonoid::T& m, int, const DataMonoid::T& a)
  { return m + a; }
};

struct RangeMinSet {
  using OperatorMonoid = RangeSet;
  using DataMonoid = RangeMin;
  static DataMonoid::T act(const OperatorMonoid::T& m, int, const DataMonoid::T&)
  { return m; }
};

struct RangeSumAdd {
  using OperatorMonoid = RangeSum;
  using DataMonoid = RangeSum;
  static DataMonoid::T act(const OperatorMonoid::T& m, int sz, const DataMonoid::T& a)
  { return m * sz + a; }
};

struct RangeSumSet {
  using OperatorMonoid = RangeSet;
  using DataMonoid = RangeSum;
  static DataMonoid::T act(const OperatorMonoid::T& m, int sz, const DataMonoid::T&)
  { return m * sz; }
};

/// }}}--- ///


void dfs(int i, int p, int d) {
  st[i] = tour++;
  dep[i] = d;
  par[0][i] = p;
  for(int j : g[i]) if(j != p) dfs(j, i, d + 1);
  ed[i] = tour++;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> k;
  LazySegTree<RangeSumAdd> seg(2 * n, 0, 0);
  for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
  for(int i = 1; i < n; i++) {
    g[i].emplace_back(a[i]);
    g[a[i]].emplace_back(i);
  }
  dfs(0, -1, 0);
  for(int j = 1; j < 18; j++) {
    for(int i = 0; i < n; i++) {
      int p = par[j-1][i];
      par[j][i] = p == -1 ? -1 : par[j-1][p];
    }
  }
  int ans = 0;
  if(a[0] != 0) ans++;
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int a, int b) {
        return dep[a] > dep[b];
      });
  for(int id = 0; id < n - 1; id++) {
    int i = ord[id];
    if(seg.get(st[i])) continue;
    if(dep[i] > k) {
      /* dep[a[i]] = min(dep[a[i]], k - 1); */
      for(int j = 17; j >= 0; j--) {
        if((k-1) & (1 << j)) i = par[j][i];
      }
      c[i] = 1;
      dump(i);
      seg.act(st[i], ed[i], 1);
    }
  }
  for(int i = 1; i < n; i++) ans += c[i];
  cout << ans << endl;
}

