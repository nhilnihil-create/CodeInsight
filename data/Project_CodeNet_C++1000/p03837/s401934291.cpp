#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

int main() {
  int n,m;
  cin >> n >> m;

  vector<vector<int>> edge(n, vector<int> (n, 0));
  vector<vector<int>> dist(n, vector<int> (n, INF));
  for (int i = 0; i < m; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    a--, b--;
    dist[a][b] = dist[b][a] = edge[a][b] = edge[b][a] = c;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(edge[i][j] > dist[i][j]) ans++;
    }
  }
  cout << ans/2 << '\n';
}