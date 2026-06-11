#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template <typename T>
using pqrev = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
//*
constexpr ll MOD = 1e9 + 7;
/*/
constexpr ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
constexpr bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
constexpr bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T>
bool print_(const T &a) {
  cout << a;
  return true;
}
template <typename T>
bool print_(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) {
      cout << " ";
    }
  }
  return false;
}
template <typename T>
bool print_(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back()) {
        cout << " ";
      }
    }
    if (&v != &vv.back()) {
      cout << "\n";
    }
  }
  return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&... tail) {
  bool f = print_(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? " " : "\n");
  }
  print(forward<Tail>(tail)...);
}
#pragma endregion

template <typename T>
struct Edge {
  int from, to;
  T cost;
  int id;
  Edge(int from_, int to_, T cost_, int id_) : from(from_), to(to_), cost(cost_), id(id_) {}
  Edge(int from_, int to_, T cost_) : from(from_), to(to_), cost(cost_) {}
  Edge(int from_, int to_) : from(from_), to(to_), cost(1) {}
  bool operator<(const Edge<T> &r) {
    return cost < r.cost;
  }
};
template <typename T>
ostream &operator<<(ostream &os, Edge<T> edge) {
  os << edge.from << " -> " << edge.to << " (" << edge.cost << ")";
  return os;
}

// グラフテンプレート(隣接リスト)
template <typename E = Edge<ll>>
struct GraphL {
  // 頂点数、辺数
  int n, m;
  // 隣接リスト
  vector<vector<E>> adj;
  GraphL(int n_)
      : n(n_), m(0), adj(n_) {}

  template <typename... Args>
  void add_edge(int from, int to, Args... args) {
    adj[from].emplace_back(from, to, args...);
    m++;
  }
  vector<E> &operator[](int i) { return adj[i]; }
};
template <typename E = Edge<ll>>
ostream &operator<<(ostream &os, GraphL<E> graph) {
  os << "V = " << graph.n << ", E = " << graph.m << "\n";
  for (const auto &ev : graph.adj) {
    for (const auto &e : ev) {
      os << e << "\n";
    }
  }
  return os;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, k;
  cin >> n >> k;
  GraphL<> g(n);
  rep(i, n-1){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    g.add_edge(a, b);
    g.add_edge(b, a);
  }
  vector<bool> visited(n, false);
  auto bfs = [&](int start, int md) -> ll{
    ll ret = 0;
    queue<pair<int, int>> q;
    q.emplace(start, 0);
    visited[start] = true;
    while(q.size()){
      ret++;
      ll node = q.front().first;
      ll d = q.front().second;
      q.pop();
      for(auto&& e: g[node]){
        if(!visited[e.to]){
          visited[e.to] = true;
          if(d < md) q.emplace(e.to, d+1);
        }
      }
    }
    return ret;
  };
  ll ans = 0;
  if(k&1){
    rep(i, n){
      for(auto&& e: g[i]){
        visited.assign(n, false);
        visited[e.from] = true;
        visited[e.to] = true;
        chmax(ans, bfs(e.from, k/2) + bfs(e.to, k/2));
      }
    }
  }else{
    rep(i, n){
      visited.assign(n, false);
      chmax(ans, bfs(i, k/2));
    }
  }
  print(n-ans);
}
