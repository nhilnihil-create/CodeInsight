#include <cstdio>
#include <vector>
#include <algorithm>

struct edge
{
  short from;
  short to;
  int cost;
};

constexpr long long INF = 1e18;
long long dist[1000];

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);

  std::vector<edge> edges;
  for (int i = 0; i < m; ++i)
  {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    edges.emplace_back(edge{a - 1, b - 1, -c});
  }

  std::fill(dist + 1, dist + n, INF);
  for (int i = 0; i < n - 1; ++i)
  {
    for (edge& e : edges)
    {
      if (dist[e.from] == INF) continue;
      if (dist[e.to] > dist[e.from] + (long long)e.cost) dist[e.to] = dist[e.from] + (long long)e.cost;
    }
  }
  for (edge& e : edges)
  {
    if (dist[e.from] == INF) continue;
    if (dist[e.to] > dist[e.from] + (long long)e.cost)
    {
      if (e.to == n - 1)
      {
        puts("inf");
        return 0;
      }
      dist[e.to] = dist[e.from] + (long long)e.cost;
    }
  }
  printf("%lld\n", -dist[n - 1]);
  return 0;
}
