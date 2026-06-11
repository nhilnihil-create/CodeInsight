#include<bits/stdc++.h>
using namespace std;
#define int long long
struct  edge{int to, cost;};
vector<vector<edge> > G;
int N, K;
vector<int> dist;

void dfs( int now, int ago, int depth ){
  dist[now] = depth;
  for( int i = 0; i < G[now].size(); i++ ){
    int next = G[now][i].to;
    if( next == ago ) continue;
    dfs( next, now, depth + G[now][i].cost );
  }
}

signed main(){
  cin >> N;
  G.resize(N); dist.resize(N, -1);
  for(int i = 1; i < N; i++){
    int a, b, c; scanf("%d%d%d", &a, &b, &c); --a; --b; 
    G[a].push_back(edge{b, c}); G[b].push_back(edge{a, c});
  }
  int Q; cin >> Q;
  cin >> K; --K;
  dfs(K, -1, 0);
  for( int i = 0; i < Q; i++ ){
    int x, y; scanf("%d%d", &x, &y); --x; --y;
    cout << dist[x] + dist[y] << '\n';
  }
}
