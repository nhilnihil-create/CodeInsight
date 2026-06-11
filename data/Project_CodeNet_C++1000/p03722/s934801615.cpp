#include <bits/stdc++.h>
using namespace std;

const long long INF = -1 * 1e18;

struct edge{  
  int to;
  int cost;
  edge(int &to, int &cost){  
    this-> to = to;
    this-> cost = cost;
  }
};

int V, E;

//if G has negative cycle d[start] = INF
vector<long long> BellmanFord(int start, vector<vector<edge>> G){  
  vector<long long> d(V, INF);
  d[start] = 0;
  long long N = 0;
  for(int i = 0; i <= 2 * V; i++){  
    bool update = false;
    if(i == V){  
      N = d[V-1];
    } 
    if(i == 2 * V){
      if(N == d[V-1]) cout << d[V-1] <<endl;
      else cout << "inf" <<endl;
      return d;
    }
    for(int j = 0; j < V; j++){  
      for(auto e: G[j]){  
        if(d[j] == INF) continue;
        else if(d[e.to] < d[j] + e.cost){  
          d[e.to] = d[j] + e.cost; 
          update = true;
        } 
      } 
    }
    if(!update){ 
      cout << d[V-1] <<endl; 
      return d;
    }
  }
  return d;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  cin >> V >> E;
  vector<vector<edge>> G(V);
  for(int i = 0; i < E; i++){  
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    G[a].push_back(edge(b, c));
  }
  BellmanFord(0, G);;
}
