#include<bits/stdc++.h>
#define INF 1000000001
#define fi first
#define se second
using namespace std;
const int N=2e3+100;
vector<int> adj[N]={};
int cnt=0;
void dfs(int u,int p=-1,int level=0){
  if(level<0) return ;
  cnt++;
  for(auto v: adj[u]){
   if(v!=p) dfs(v,u,level-1);
}
}
int main(){
  int n,k;
  cin>>n>>k;
  vector<pair<int,int> > edge;
  for(int i=0;i<n-1;i++){
   int a,b;
   cin>>a>>b;
   adj[a].push_back(b);
   adj[b].push_back(a);
   edge.push_back(make_pair(a,b));
}
   int min1=INF;
   if(k%2==0){
    for(int i=0;i<n;i++){
     dfs(i,-1,k/2);
     min1=min(min1,n-cnt);
     cnt=0;
}
}
   else {
   for(auto p: edge){
    dfs(p.fi,p.se,(k-1)/2);
    int a=cnt;
    cnt=0;
    dfs(p.se,p.fi,(k-1)/2);
    a+=cnt;
    min1=min(min1,n-a);
    cnt=0;
}
}
   cout<<min1<<endl;
   return 0;
}