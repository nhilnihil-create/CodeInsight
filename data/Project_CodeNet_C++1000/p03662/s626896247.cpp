#include <bits/stdc++.h>
using namespace std;
 
vector<int> G[100010];
int depth[100010];
bool check[100010];
int fen=0;
int snu=0;
 
void dfs(int p,int v){
 
  if(p<0) depth[v]=0; 
  else depth[v]=depth[p]+1;
 
  for(auto nv:G[v]){
    if(nv!=p){
      dfs(v,nv);
    }
  }
 
}
 
void black(int p,int v){
 
  ++fen;
 
  for(auto nv:G[v]){
    if(nv!=p && check[nv]==false){
      black(v,nv);
    }
  }
  
}
 
 
int main(){
 
  int N;
  cin>>N;
  for(int i=0;i<N-1;++i){
    int a,b;
    cin>>a>>b;
    --a,--b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
 
  dfs(-1,0);
 
  int v=N-1;
  int d=depth[v]/2;
 
  memset(check,false,sizeof(check));
  
  while(depth[v]>d){
    bool rep=false;
    check[v]=true;
    for(auto nv:G[v]){
      if(depth[nv]<depth[v]){
        v=nv;
        rep=true;
      }
    }
    if(!rep) break;
  }
  
  black(-1,0);
  snu=N-fen;
 
  if(fen>snu) cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
 
}