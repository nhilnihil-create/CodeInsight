#include <bits/stdc++.h>
using namespace std;

int n;
int MAXIMUM=100005;
long INF = 1e15;
// W:未訪問
// G:訪問する候補
// B:訪問済み
int W=0,G=1,B=2;
vector<pair<int,int>> adj[100005];
long d[100005];
void dijkstra(int K){
  priority_queue<pair<int,int>> PQ;
  int u,minv;
  int color[MAXIMUM];
  // d[n]:Tに属する頂点と V - T に属する頂点をつなぐ辺の中で重みが最小の辺の重みを記録

  //初期化
  for(int i=0;i<n;i++){
    d[i]=INF;
    color[i]=W;
  }

  d[K]=0;
  PQ.push(make_pair(0,K));
  color[K] = G;

  while (!PQ.empty()) {
    pair<int,int> f = PQ.top();
    PQ.pop();
    u = f.second;
    // 頂点を訪問済に
    color[u] = B;
    //最小値を取り出し、それが最短でなければ無視
    if( d[u]<f.first*(-1)) continue;

    //訪問済みでないかつ辺がつながっている頂点の中でコストが最小の辺を選択
    for(int j=0;j<adj[u].size();j++){
      int v = adj[u][j].first;
      if(color[v]== B) continue;
      if(d[v]>d[u]+adj[u][j].second){
        d[v]=d[u]+adj[u][j].second;
        PQ.push(make_pair(d[v]*(-1),v));
        color[v]=G;
      }
    }
  }


}

int main(){
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
      adj[a-1].push_back(make_pair(b-1,c));
      adj[b-1].push_back(make_pair(a-1,c));
    }

  int Q,K;
  cin>>Q>>K;
  dijkstra(K-1);
  for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      cout<<d[x-1]+d[y-1]<<endl;
  }

}
