#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))

using namespace std;

using i32 = int;
using i64 = long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); return a / gcd(a, b) * b; }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template <typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

struct UnWeightedGraph {
  struct Edge {
    int to;
    Edge(int to) : to(to) {}
  };
  vector<vector<Edge>> edges;
  int n;
  UnWeightedGraph(int n) : n(n) {
    edges.assign(n, vector<Edge>());
  }
  void add_edge(int v, int u) {
    edges[v].emplace_back(u);
  }
  vector<Edge> &operator[](int x) {
    return edges[x];
  }
};

void solve() {
  int n;
  cin >> n;
  UnWeightedGraph g(n);
  reps(i, n - 1) {
    int a;
    cin >> a;
    a--;
    g.add_edge(i, a);
    g.add_edge(a, i);
  }
  auto dfs = [&](auto dfs, int u, int p) -> int {
    vi32 lst;
    each(e, g[u]) if (e.to != p) {
      int x = dfs(dfs, e.to, u) + 1;
      lst.emplace_back(x);
    }
    if (lst.size() == 0) {
      return 0;
    }
    sort(all(lst));
    rep(i, lst.size()) {
      lst[i] += (int) lst.size() - 1 - i;
    }
    return *max_element(all(lst));
  };
  cout << dfs(dfs, 0, -1) << endl;
}
