#include<iostream>
#include<vector>
using namespace std;
const int MAXN=1e5;

struct edge{int to;
            long long cost;
           };
vector<edge> G[MAXN];
vector<long long> dis(MAXN);
int N,Q,K;

void dfs(int v,int p,long long d){
  dis[v]=d;
  for(auto& e:G[v]){
    if(e.to==p) continue;
    dfs(e.to,v,d+e.cost);
  }
  return;
}

int main(){
  cin>>N;
  int a,b,c;
  for(int i=0;i<N-1;i++){
    cin>>a>>b>>c;
    a--;b--;
    G[a].push_back({b,c});
    G[b].push_back({a,c});
  }
  cin>>Q>>K;
  dfs(K-1,-1,0);
  int x,y;
  for(int i=0;i<Q;i++){
    cin>>x>>y;
    x--;y--;
    cout<<dis[x]+dis[y]<<endl;
  }
  return 0;
}