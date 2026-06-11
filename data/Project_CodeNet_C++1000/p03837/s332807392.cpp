#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)
const int INF = 1e9;
int g[101][101];
int dist[101][101];
struct edge{ int from,to,cost;};

int main(){
  int n,m;
  cin >> n >> m;
  rep(i,n) rep(j,n) {
    if (i == j) dist[i][i] = 0;
    else dist[i][j] = INF;
  }
  vector<edge> e(m);
  vector<bool> edges(m,false);
  for (int i = 0; i < m;i++){
    int a,b,c;
    cin >> a >> b >> c;
    a--;b--;
    e[i].from = a; e[i].to = b; e[i].cost = c;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  for (int i = 0;i < n;i++){
    for (int j = 0;j < n;j++){
      for (int k = 0; k < n;k++){
        dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
      }
    }
  }
  //rep(i,n){
  //  rep(j,n) if (dist[i][j] == INF) cout << "f"; else cout << dist[i][j];
  //  cout << endl;
  //}
  int cnt = 0;
  for (int i = 0;i < m;i++){
    for (int s = 0; s < n;s++){
      for (int t = 0; t < n;t++){
        if (dist[s][t] == dist[s][e[i].from] + e[i].cost + dist[e[i].to][t]) {
          edges[i] = true;
          //printf("(s,t) = (%d, %d)\n",s,t);
        }
        if (dist[s][t] == dist[s][e[i].to] + e[i].cost + dist[e[i].from][t]){
          edges[i] = true;
          //printf("(s,t) = (%d ,%d)\n",s,t);
        }
      }
    }
  }
  for (int i = 0; i < m;i++){
     if (!edges[i]) cnt++;
  }

  cout << cnt << endl;

  


  return 0; 
}

