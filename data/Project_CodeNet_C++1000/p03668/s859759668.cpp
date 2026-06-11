#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
const int mx=1e5+10;
int f[mx];
vector<int>g[mx];
void dfs(int u,int pu=0){
  f[u]=0;
  for(int v:g[u])if(v!=pu){
    dfs(v,u);
    f[u]^=f[v];
  }
  f[u]++;
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n-1;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  dfs(0);
  int x=0;
  for(int v:g[0])x^=f[v];
  if(x==0)puts("Bob");
  else puts("Alice");

  return 0;
}
