#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
typedef pair<int64_t, int64_t> P;
vector<P> to[MAXN];
vector<int64_t> d(MAXN, -1);

void dfs(int v)
{
  for (auto u : to[v])
  {
    if (d.at(u.first) == -1)
    {
      d.at(u.first) = d.at(v) + u.second;
      dfs(u.first);
    }
  }
}

int main()
{
  int64_t N, a, b, c;
  cin >> N;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> a >> b >> c;
    a--, b--;
    to[a].emplace_back(b, c);
    to[b].emplace_back(a, c);
  }
  int Q, K, x, y;
  cin >> Q >> K;
  K--;
  d[K] = 0;
  dfs(K);
  for (int i = 0; i < Q; i++)
  {
    cin >> x >> y;
    x--, y--;
    cout << d[x] + d[y] << endl;
  }
}