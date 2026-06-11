#pragma region header
#include <bits/stdc++.h>
#define int long long
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define mp make_pair
#define mt make_tuple
#define rep1(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define rrep1(i, n) for (auto i = n - 1; i > static_cast<decltype(i)>(-1); i--)
#define rep2(i, a, b) for (auto i = (a); i < (b); i++)
#define rrep2(i, a, b) for (auto i = b - 1; i >= a; i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1) (__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep2, rrep1) (__VA_ARGS__)
#define each(i, a) for (auto &&i : (a))
using namespace std;

using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using mii = map<int, int>;
using vm = vector<mii>;
using vvm = vector<vm>;
template <class T, class U>
using umap = unordered_map<T, U>;
using umii = umap<int, int>;
using seti = set<int>;
template <class T>
using uset = unordered_set<T>;
using useti = uset<int>;
template <class T>
using less_queue = priority_queue<T>;
template <class T>
using greater_queue = priority_queue<T, vector<T>, greater<T>>;

constexpr int INF = 1e18;

template <class T>
void SORT(T &a) { stable_sort(all(a)); }
template <class T>
void RSORT(T &a) { stable_sort(rall(a)); }
template <class T>
void rev(T &a) { reverse(rall(a)); }
template <class T>
void uniq(T &a) { a.erase(unique(all(a)), end(a)); }
template <class T>
auto min_of(T a) { return *min_element(all(a)); }
template <class T>
auto max_of(T a) { return *max_element(all(a)); }
template <class T>
int sum_of(T a) { return accumulate(all(a), 0ll); }
template <class T, class U>
auto sum_of(T a, U init) { return accumulate(all(a), init); }
template <class T, class U>
int count_of(T a, U i) { return count(all(a), i); }
template <class T, class U>
bool has(T a, U i) { return find(all(a), i) != end(a); }
template <class T>
int sz(T a) { return a.size(); };

template <class T>
void COUT(T x) { cout << x << endl; }
template <class T, class U>
void COUT(T x, U y) { cout << x << ' ' << y << endl; }
template <class T, class U, class V>
void COUT(T x, U y, V z) { cout << x << ' ' << y << ' ' << z << endl; }
template <class T>
void CSP(T x) { cout << x << ' '; }
template <class T>
void CVEC(T v) {
  int c = v.size() - 1;
  for (size_t i = 0; i < c; i++) cout << v[i] << ' ';
  if (c > -1) cout << v[c];
  cout << endl;
}

template <class T>
bool amin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool amax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int ceil_div(int x, int y) { return (x - 1) / y + 1; }

#pragma endregion header

template< typename Monoid >
struct segment_tree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;
  const F f;
  const Monoid M1;

  segment_tree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }
  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }
  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }
  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};
// segment_tree<int> st(n, [](int a, int b){ return a + b; }, 0);

template <class T>
vector<pair<T, int>> zip_vi(vector<T> v) {
  int n = sz(v);
  vector<pair<T, int>> w(n);
  for (int i = 0; i < n; i++) w[i] = make_pair(v[i], i);
  return w;
}
template <class T>
vector<pair<int, T>> zip_iv(vector<T> v) {
  int n = sz(v);
  vector<pair<int, T>> w(n);
  for (int i = 0; i < n; i++) w[i] = make_pair(i, v[i]);
  return w;
}
template <class T, class S>
vector<pair<T, S>> zip(vector<T> v, vector<S> w) {
  int n = min(sz(v), sz(w));
  vector<pair<T, S>> x(n);
  for (int i = 0; i < n; i++) x[i] = make_pair(v[i], w[i]);
  return x;
}
template <class T, class S>
pair<vector<T>, vector<S>> unzip(vector<pair<T, S>> v) {
  int n = sz(v);
  auto w = make_pair(vector<T>(n), vector<S>(n));
  for (int i = 0; i < n; i++) {
    w.first[i] = v[i].first;
    w.second[i] = v[i].second;
  }
  return w;
}
template <class T, class S>
vector<T> unzip_first(vector<pair<T, S>> v) {
  int n = sz(v);
  vector<T> w(n);
  for (int i = 0; i < n; i++) w[i] = v[i].first;
  return w;
}
template <class T, class S>
vector<S> unzip_second(vector<pair<T, S>> v) {
  int n = sz(v);
  vector<S> w(n);
  for (int i = 0; i < n; i++) w[i] = v[i].second;
  return w;
}

void solve(int N, int K, vi a) {
  each(x, a)x -= K;
  vi cum(N + 1);
  mii ac;
  rep(i, N){
    cum[i + 1] = cum[i] + a[i];
    ac[cum[i + 1]]++;
  }
  int m = sz(ac);
  vi ia, ic;
  each(p, ac){
    ia.push_back(p.first);
    ic.push_back(p.second);
  }
  mii ai;
  rep(i, m)ai[ia[i]] = i;
  segment_tree<int> st(m, [](int a, int b){ return a + b; }, 0);
  rep(i, m)st.set(i, ic[i]);
  st.build();
  int ans = 0, now = 0;
  rep(i, N) {
    int index = lower_bound(all(ia), now) - ia.begin();
    ans += st.query(index, m);
    int cur = ai[cum[i + 1]];
    st.update(cur, st[cur] - 1);
    now = cum[i + 1];
  }
  COUT(ans);
}


#pragma region main
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);

  int N;
  cin >> N;
  int K;
  cin >> K;
  vi a(N);
  for(int i = 0 ; i < N ; i++){
    cin >> a[i];
  }
  solve(N, K, move(a));
}
#pragma endregion main
