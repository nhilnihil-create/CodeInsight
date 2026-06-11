# include <bits/stdc++.h>
using namespace std;

struct Query {
  int node, dist, color;
  Query(){}
  Query(int _n, int _d, int _c){
    node = _n;
    dist = _d;
    color = _c;
  }
};
Query query[100005];
vector<int> adj[100005];
int color[100005][15];

void dfs(int u, int d, int col){
  if(d >= 0 && color[u][d] == 0){
    color[u][d] = col;
    for(int v : adj[u]){
      dfs(v, d-1, col);
    }
  }
}

int main(){
  ios_base :: sync_with_stdio(false);
  int V, E;
  cin >> V >> E;
  for(int i=1; i<=E; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int Q;
  cin >> Q;
  for(int i=1; i<=Q; i++){
    cin >> query[i].node >> query[i].dist >> query[i].color;
  }

  for(int i=Q; i>=1; i--){
    for(int d=query[i].dist; d>=0; d--){
      dfs(query[i].node, d, query[i].color);
    }
  }

  for(int i=1; i<=V; i++) cout << color[i][0] << endl;


  return 0;
} 