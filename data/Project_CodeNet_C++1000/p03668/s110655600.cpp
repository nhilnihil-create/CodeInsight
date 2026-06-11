#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> G[114514];
int dfs(int v,int p){
  int res=0,cnt=0;
  for(int u:G[v]){
    if(u==p) continue;
    res^=dfs(u,v)+1;
    cnt++;
  }
  return res;
}
signed main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  cout<<(dfs(0,-1)?"Alice":"Bob")<<endl;
  return 0;
}
