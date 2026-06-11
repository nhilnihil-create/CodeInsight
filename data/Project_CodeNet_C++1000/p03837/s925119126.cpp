#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  Graph d(n, vector<int>(n, 100100100));
  map<P, int> edge;
  int ans = 0;
  for(int i=0;i<n;i++) d[i][i] = 0;
  for(int i=0;i<m;i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    d[a][b] = c;
    d[b][a] = c;
    P p = make_pair(a, b);
    edge[p] = c;
  }
  for(int k=0;k<n;k++) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
      }
    }
  }
  for(auto it = edge.begin(); it!= edge.end(); it++) {
    int from = (it->first).first;
    int to = (it->first).second;
    if(d[from][to] != it->second) ans++;
  }
  cout << ans << endl;
}
