#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<vector<int>> g;
vector<int> dist;

long long solve();

int main() {
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0, bipartite = 0, nonbipartite = 0, cnt = n;
  dist.assign(n, 0);
  for (int i = 0; i < n; ++i)
    if (dist[i] == 0) {
      if (g[i].size() == 0)
        res += 2 * (cnt--) - 1;
      else {
        queue<int> qu;
        qu.push(i);
        dist[i] = 1;
        while (qu.size()) {
          int now = qu.front();
          qu.pop();
          int cos = dist[now] / 2 + ((dist[now] & 1) << 1);
          for (auto to : g[now])
            if (dist[to] != (dist[to] | cos)) {
              dist[to] |= cos;
              qu.push(to);
            }
        }
        if (dist[i] == 3)
          ++nonbipartite;
        else
          ++bipartite;
      }
    }
  res += (nonbipartite + bipartite) * (nonbipartite + bipartite) +
         bipartite * bipartite;
  return res;
}