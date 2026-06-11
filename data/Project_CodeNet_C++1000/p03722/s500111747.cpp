#include<bits/stdc++.h>
using namespace std;

const int N = 2002;
                               
int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    edges.push_back({u, {v, w}});
  }
  vector<long long>cost(n, -1e12);
  cost[0] = 0;      
  bool f = false;
  for (int i = 0; i < n; i++){
    for (auto edge : edges){
      int u = edge.first;
      int v = edge.second.first;
      int w = edge.second.second;
      if (cost[v] < cost[u] + w){
        cost[v] = cost[u] + w;
        if (i == n - 1 && v == n - 1){
          f = true;
        }
      }
    }        
  }
  if (f){
    cout << "inf\n";
  } else {
    cout << cost[n - 1] << "\n";
  } 
  return 0;
}