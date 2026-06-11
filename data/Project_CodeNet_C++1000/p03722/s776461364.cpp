#include <bits/stdc++.h>
using namespace std;
const int64_t INF = (1LL << 62);
vector<int> to[1005];
vector<int> from[1005];
vector<tuple<int64_t, int64_t, int64_t>> edges;
bool used[1005];

bool isReachableFrom1[1005];
void dfs(int v)
{
  if (isReachableFrom1[v])
  {
    return;
  }
  isReachableFrom1[v] = true;
  for (int u : to[v])
  {
    dfs(u);
  }
}

bool isReachableToN[1005];
void rdfs(int v)
{
  if (isReachableToN[v])
  {
    return;
  }
  isReachableToN[v] = true;
  for (int u : from[v])
  {
    rdfs(u);
  }
}

int main()
{
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int64_t a, b, c;
    cin >> a >> b >> c;
    edges.emplace_back(a - 1, b - 1, -c);
    to[a - 1].push_back(b - 1);
    from[b - 1].push_back(a - 1);
  }
  dfs(0);
  rdfs(N - 1);
  for (int i = 0; i < N; i++)
  {
    used[i] = isReachableFrom1[i] && isReachableToN[i];
  }
  vector<int64_t> d(N, INF);
  d[0] = 0;
  bool upd = true;
  int64_t step = 0;
  while (upd)
  {
    upd = false;
    for (int i = 0; i < M; i++)
    {
      int64_t a, b, c;
      tie(a, b, c) = edges[i];
      if (!used[a] || !used[b])
        continue;
      int64_t newD = d[a] + c;
      if (newD < d[b])
      {
        upd = true;
        d[b] = newD;
      }
    }
    step++;
    if (step > N)
    {
      cout << "inf" << endl;
      return 0;
    }
  }
  cout << -d[N - 1] << endl;
}