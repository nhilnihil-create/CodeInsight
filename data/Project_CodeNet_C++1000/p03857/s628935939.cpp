#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define range(i, l, r) for (int i = (int)l; i < (int)(r); ++(i))
#define rrange(i, l, r) for (int i = ((int)(r) - 1); i >= (int)l; --(i))

#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
#define rwhole(f,x,...) ([&](decltype((x)) whole) { return (f)(rbegin(whole), rend(whole), ## __VA_ARGS__); })(x)

#define debug(x) cerr << "(" << __LINE__ << ")" << #x << ": " << (x) << endl

inline void br(ostream &os = cerr) { os << endl; }

using int32 = int;
using int64 = long long;

const int mod     = 1e9 + 7;
const int32 inf   = 1001001001;
const int64 infll = 1001001001001001001ll;

const int dx[] = {0, -1, 1, 0, -1, 1, -1, 1}, dy[] = {-1, 0, 0, 1, -1, -1, 1, 1};
const string YES = "YES", NO = "NO", Yes = "Yes", No = "No", yes = "yes", no = "no";

struct IoSetup { IoSetup(){ cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); cerr << fixed << setprecision(10); } } iosetup;

template <typename T = int64> T input() { T x; cin >> x; return x; }

template <typename T> ostream &operator<<(ostream &os, vector<T> &v) { range(i, 0, v.size()) { os << v[i] << (i + 1 != v.size() ? " " : ""); } return os; } 
template <typename T> istream &operator>>(istream &is, vector<T> &v) { for (T &in : v) is >> in; return is; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p) { os << p.fs << " " << p.sc; return os; }
template <typename T1, typename T2> istream &operator>>(istream &is, pair<T1, T2> &p) { is >> p.fs >> p.sc; return is; }

template <typename T> vector<T> make_v(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_v(size_t a, Ts... ts) { return vector<decltype(make_v(ts...))>(a, make_v(ts...)); }

template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
// clang-format on

struct UnionFind {
  UnionFind(size_t size) : v(size, -1) {}
  vector<int> v;

  int root(int x) {
    return (v[x] < 0 ? x : v[x] = root(v[x]));
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (v[x] > v[y]) swap(x, y);
      v[x] += v[y];
      v[y] = x;
    }
  }

  int size(int x) {
    return -v[root(x)];
  }
};

void solver() {
  int N = input(), K = input(), L = input();

  UnionFind s(N), t(N);
  range(i, 0, K) s.unite(input() - 1, input() - 1);
  range(i, 0, L) t.unite(input() - 1, input() - 1);

  map<pair<int, int>, int> cnt;
  range(i, 0, N) {
    cnt[make_pair(s.root(i), t.root(i))]++;
  }

  range(i, 0, N) {
    cout << cnt[make_pair(s.root(i), t.root(i))] << (i + 1 == N ? "\n" : " ");
  }
}

signed main(int argc, char *argv[]) {
  solver();
}