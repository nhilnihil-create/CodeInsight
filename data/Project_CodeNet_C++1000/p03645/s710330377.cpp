#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
  int n, m;
  cin >> n >> m;
  Graph G(n);
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i = 0; i < G[0].size(); i++){
    for(int j = 0; j < G[G[0][i]].size(); j++){
      if(G[G[0][i]][j] == n-1) {
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}