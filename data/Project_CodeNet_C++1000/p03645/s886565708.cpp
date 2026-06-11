// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

const int INF = 500000;

int n, m;
vector<int> G[200000];

int bfs() {
  vector<int> dist(200000, INF);
  queue<int> Q;
  Q.push(0);
  dist[0] = 0;
  
  while (Q.size()) {
    int v = Q.front(); Q.pop();
    for (auto u: G[v]) {
      if (dist[u] < INF) continue;
      Q.push(u);
      dist[u] = dist[v] + 1;
    }
  }
  
  return dist[n-1];
}

int main() {
  cin >> n >> m;
  loop(i,0,m) {
    int a, b;
    cin >> a >> b; a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  if (bfs() <= 2) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}
