#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a; i<n; i++)
#define P pair<int,int>
#define INF 1000000000
using namespace std;;
 
int N,M;
vector<int> cost(200001);
vector<vector<int>> G(200001,vector<int>());

void calc() {
  priority_queue<P,vector<P>,greater<P>> Q;
  rep(i,1,N+2) cost[i] = INF;
  cost[1] =0;
  Q.push(P(1,0));
  
  while(!Q.empty()) {
    P p = Q.top(); Q.pop();
    int v = p.first;
    if (cost[v] < p.second) continue;
    int M = G[v].size();
    rep(j,0,M) {
      int q = G[v][j];
      if (cost[q] > cost[v] + 1) {
        cost[q] = cost[v] + 1;
        Q.push(P(q,cost[q]));
      }
    }
  }
}           

int main() {
  cin >> N >> M;
  rep(i,0,M) {
    int x,y; cin >> x >> y;
    G[x].push_back(y); G[y].push_back(x);
  }
  
  calc();
  
  if (cost[N] == 2) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl; 
  return 0; 
}