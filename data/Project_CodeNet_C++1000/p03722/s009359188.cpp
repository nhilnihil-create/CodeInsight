#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

// bellman_ford
template<typename Edge>
struct bellman_ford {
  using Graph = std::vector<std::vector<Edge>>;
  using T = typename Edge::cost_type;

  Graph& G;
  int N;
  std::vector<T> d;
  std::vector<bool> neg;
  T INF;
  bellman_ford(Graph& Graph, T inf):
    G(Graph), N(Graph.size()), INF(inf) {}

  bool search(int s) {
    d.assign(N, INF);
    neg.assign(N, false);
    d[s] = 0;
    bool has_nl = false;
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) for(auto const& e: G[j]) {
        T newd = d[j] + e.cost;
        if(d[e.to] > newd) {
          d[e.to] = newd;
          if(i == N-1) has_nl = neg[e.to] = true;
        }
      }
    }
    for(int i = 0; i < N-1; ++i) {
      for(int j = 0; j < N; ++j) if(neg[j]) for(auto const& e: G[j]) {
        neg[e.to] = true;
      }
    }
    return has_nl;
  }
};

struct edge {
  typedef int64_t cost_type;
  cost_type cost;
  int to;
  edge(cost_type c, int t): cost(c), to(t) {}
};

int64_t const INF = 1e18;

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, M; std::cin >> N >> M;
  std::vector<std::vector<edge>> G(N);
  for(int i = 0; i < M; ++i) {
    int a, b, c; std::cin >> a >> b >> c; --a; --b;
    G[a].emplace_back(-c, b);
  }
  bellman_ford<edge> bf(G, INF);
  bf.search(0);
  if(bf.neg[N-1]) fin("inf");
  fin(-bf.d[N-1]);
  return 0;
}
