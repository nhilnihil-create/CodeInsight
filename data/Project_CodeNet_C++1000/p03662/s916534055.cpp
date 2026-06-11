#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>

template <class T>
using greater_queue=std::priority_queue<T, std::deque<T>, std::greater<T>>;

template <class Weight>
struct Edge {
  size_t src, dst;
  Weight cost;
  Edge(size_t src, size_t dst, Weight cost=1):
    src(src), dst(dst), cost(cost)
  {}
};

template <class Weight>
using Graph=std::vector<std::vector<Edge<Weight>>>;

template <class Weight>
constexpr Weight inf=(Weight(1)<<(8*sizeof (Weight)-3));

template <class Weight>
std::vector<Weight> dijkstra(const Graph<Weight> &g, size_t s) {
  std::vector<Weight> dist(g.size(), inf<Weight>);
  greater_queue<std::pair<Weight, size_t>> q;
  dist[s] = 0;
  q.emplace(0, s);
  while (!q.empty()) {
    auto p=q.top();
    q.pop();
    Weight w=p.first;
    size_t v=p.second;
    if (w > dist[v])
      continue;

    for (const Edge<Weight> &e: g[v]) {
      if (dist[e.dst] > w + e.cost) {
        dist[e.dst] = w + e.cost;
        q.emplace(dist[e.dst], e.dst);
      }
    }
  }
  return dist;
}

int main() {
  size_t N;
  scanf("%zu", &N);

  Graph<int> g(N);
  for (size_t i=1; i<N; ++i) {
    size_t a, b;
    scanf("%zu %zu", &a, &b);
    --a;
    --b;

    g[a].emplace_back(a, b);
    g[b].emplace_back(b, a);
  }

  std::vector<int> fennec=dijkstra(g, 0), snuke=dijkstra(g, N-1);
  int ff=0, ss=0;
  for (size_t i=0; i<N; ++i)
    ++(fennec[i]<=snuke[i]? ff:ss);

  printf("%s\n", ff>ss? "Fennec":"Snuke");
}
