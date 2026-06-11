#include<bits/stdc++.h>
using namespace std;

#define dbg(a)  cerr << __LINE__ << ": " << #a << " = " << a << '\n'

struct graph
{
  int n;
  vector<vector<int>> g, c, used;
  vector<int> par;

  graph(int n):n(n),g(n),c(n){
    used.assign(n, vector<int> (n,1));
  }

  void add_edge(int u, int v, int w){
    g[u].push_back(v);
    c[u].push_back(w);
    g[v].push_back(u);
    c[v].push_back(w);
    used[u][v]=0;
    used[v][u]=0;
  }

  void dijkstra(int s){
    vector<int> dis(n,1e9);
    dis[s]=0;
    par.assign(n, -1);
    par[s]=s;
    auto comp = [&dis](int x, int y){return dis[x]>dis[y];};
    priority_queue <int, vector<int>, decltype(comp)> pq(comp);
    pq.push(s);
    while (!pq.empty()){
      int v=pq.top(); pq.pop();
      int sz = g[v].size();
      for (int i = 0; i < sz; ++i){
        int u=g[v][i];
        if(dis[u] > dis[v]+c[v][i]){
          dis[u] = dis[v]+c[v][i];
          used[u][v]=1;
          used[v][u]=1;
          if(par[u]!=-1){
            used[u][par[u]]=0;
            used[par[u]][u]=0;
          }
          par[u]=v;
          pq.push(u);
        }
      }
    }
  }

  int solve(){
    vector<vector<int>> usedall(n,vector<int> (n,0));
    for (int i = 0; i < n; ++i){
      dijkstra(i);
      for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
          if(used[i][j])  usedall[i][j]=1;
        }
      }
    }
    int ret = 0;
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
        if(!usedall[i][j]){
         ret++;
        }
      }
    }
    return ret/2;
  }
};


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  graph g(n);
  for (int i = 0; i < m; ++i){
    int u, v, c; cin >> u >> v >> c;
    g.add_edge(u-1, v-1, c);
  }
  cout << g.solve() << endl;
  return 0;
}