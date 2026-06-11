#include<bits/stdc++.h>
using namespace std;
#define int long long 

int N,M;
vector<vector<int>> to; vector<int> color;
int Q;

vector<int> used;

vector<tuple<int,int,int>> Queries;

void DFS(int u, int d, int c){
  
  if( used[u] >= d ){ return ;}
  
  used[u] = d;
  //一度同じペアについて塗ったことがあるなら、上書き不可だからもうしなくていい
  
  if( d == -1 ){ return ;} //終了
  
  if( color[u] == -1 ){ //まだ塗られていなかったら塗る
    color[u] = c;
  }
  
  for(auto p : to[u] ){ 
    
    DFS(p,d-1,c);
    
  }
  
  DFS(u,d-1,c);
  
  return ;
}



signed main(void){ 
  
  cin >> N >> M; to.resize(N); 
  used = vector<int>(N,-1);
  color = vector<int>(N,-1); //-1はまだ色を塗っていない
  
  for(int i = 0; i < M; i++){
    int a,b; cin >> a >> b; a--; b--;
    to[a].push_back(b); to[b].push_back(a);
  }
  
  cin >> Q; 
  Queries.resize(Q);
  
  for(int i = 0; i < Q; i++){
    int u,d,c; cin >> u >> d >> c; u--;
    Queries.emplace_back(u,d,c);
  }
  
  reverse(Queries.begin(),Queries.end());
  
  for(int i = 0; i < Q; i++){ 
    auto q = Queries[i];
    int u = get<0>(q); 
    int d = get<1>(q);
    int c = get<2>(q);
    
    // ここからBFS
    
    DFS(u,d,c);
    
  }
  
  for(int i = 0; i < N; i++){ 
    int res = color[i];
    if( res == -1 ){ res = 0;}
    
    cout << res << endl;
    
                    
  }
  return 0;
}