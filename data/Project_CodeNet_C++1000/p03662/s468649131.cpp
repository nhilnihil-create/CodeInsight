#include <vector>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
const int INF = 1e9;
vector<int> G[MAXN];
int n;

vector<int> bfs(int start) {
  vector<int> dist(n, INF);
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int i = 0; i < G[cur].size(); ++i) {
      int next = G[cur][i];
      if (visited[next]) continue;
      q.push(next);
      dist[next] = dist[cur] + 1;
      visited[next] = true;
    }
  }
  return dist;
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> dist_b = bfs(0);
  vector<int> dist_w = bfs(n - 1);

  ll bcnt = 0;
  ll wcnt = 0;
  for (int i = 0; i < n; ++i) {
    if (dist_b[i] <= dist_w[i]) bcnt++;
    else wcnt++;
  }

  if (bcnt > wcnt) puts("Fennec");
  else puts("Snuke");
  return 0;
}
