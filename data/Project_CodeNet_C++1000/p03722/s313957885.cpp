#include<bits/stdc++.h>
using namespace std;
#define int long long 

int N,M;

struct edge{int from,to,cost;};

edge E[2020];
int dist[1010];

vector<bool> ava;

const int INF = 1LL << 60;

void Bellmanford(const int &str){ 
  
  for(int i = 0; i < N; i++){ 
    dist[i] = -INF;
  }
  
  dist[str] = 0;
  
  
  vector<int> vec;
  
  for(int i = 0; i < N; i++){ 
    for(int j = 0; j < M; j++){
      
      int r1 = dist[E[j].from];
      int &r2 = dist[E[j].to];
      int w = E[j].cost;
      
      if( r2 < r1+w && r1 != -INF ){
        r2 = r1+w;
        if( i == N-1 ){ 
          vec.push_back(E[j].to); //この点はループに含まれる
        }
      }
    }
    
  }
  
  if( !vec.empty() ){ 
    for(int i = 0; i < (int)vec.size(); i++){ 
      if(ava[vec[i]]){ cout <<"inf" << endl; exit(0);}
      //N-1へと到達可能でないループは検出されても無視しなければならない
    }
    
  }
  
  cout << dist[N-1] << endl;
  
  
  return;
}
 

signed main(void){
  
  cin >> N >> M;
  
  vector<vector<int>> to(N);
  
  for(int i = 0; i < M; i++){ 
    
    int a,b,c; cin >> a >> b >> c; a--; b--;
    E[i].from = a; E[i].to = b; E[i].cost = c;
    
    to[b].push_back(a);

  }
  
  queue<int> Q;
  Q.push(N-1);
  ava = vector<bool>(N,false);
  ava[N-1] = true;
  
  while(!Q.empty()){ //N-1へと到達可能な点を全て列挙
    int p = Q.front(); Q.pop();
    for(auto q : to[p]){
      if( ava[q] ){ continue;}
      ava[q] = true;
      Q.push(q);
    }
  }
  
  Bellmanford(0);
  
  return 0;
} 
