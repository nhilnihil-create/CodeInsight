#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 5;
typedef long long int64;
int n, m;
vector<int> adj[maxn];
int visited[maxn];
int color[maxn];

int64 solve()
{
  fill(visited, visited+n+1, 0);
  int64 sp = 0;
  int64 p2 = 0;
  int64 pc = 0;
  for (int i = 1; i <= n; ++i) if (visited[i] == 0)
  {
    visited[i] = 1;
    color[i] = 0;
    queue<int> q;
    q.push(i);
    int mixed = 0;
    int cnt = 0;
    while (!q.empty())
    {
      int curr = q.front(); q.pop();
      ++cnt;
      for (auto& next: adj[curr])
      {
        if (visited[next]) mixed |= color[curr] == color[next];
        else color[next] = color[curr] ^ 1, visited[next] = 1, q.push(next);
      }
    }
    if (cnt == 1) ++sp;
    else if (mixed) ++pc;
    else ++p2;
  }
  int64 ans = 0;
  ans += sp * n * 2 - sp - sp * (sp - 1);
  ans += 2 * p2 + pc;
  ans += 2 * p2 * (p2 - 1);
  ans += pc * (pc - 1);
  ans += 2 * p2 * pc;
  // cout << sp << " " << p2 << " " << pc << endl;
  return ans;
}

int64 bf()
{
  int64 ans = 0;
  set<pair<int, int>> st;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
  if (st.count({i, j}) == 0)
  {
    pair<int, int> now{i, j};
    queue<pair<int, int>> q;
    q.push(now);
    st.insert(now);
    ++ans;
    while (!q.empty())
    {
      auto curr = q.front(); q.pop();
      for (auto& a: adj[curr.first]) for (auto& b: adj[curr.second]) if (st.count({a, b}) == 0)
      {
        st.insert({a,b}); q.push({a,b});
      }
    }
  }
  return ans;
}

int main()
{
  while (scanf("%d%d", &n, &m) == 2)
  {
    for (int i = 0; i < m; ++i)
    {
      int u, v; scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    cout << solve() << endl;
    // cerr << bf() << endl;
    for (int i = 1; i <= n; ++i) adj[i].clear();
  }
  return 0;
}