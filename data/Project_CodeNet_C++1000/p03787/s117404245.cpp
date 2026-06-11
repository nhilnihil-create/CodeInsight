#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//INSERT ABOVE HERE
signed main(){
  Int n,m;
  cin>>n>>m;
  vector<vector<Int> > G(n);
  for(Int i=0;i<m;i++){
    Int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<Int> used(n,-1);
  Int cnt=0,flg=0;
  function<void(Int)> dfs=[&](Int v){
    cnt++;
    for(Int u:G[v]){
      if(~used[u]){
	flg|=~(used[v]-used[u])&1;
      }else{
	used[u]=used[v]+1;
	dfs(u);
      }
    }
  };
  Int x=0,y=0,z=n;
  for(Int i=0;i<n;i++){
    if(~used[i]) continue;
    cnt=flg=used[i]=0;
    dfs(i);
    if(cnt!=1){
      z-=cnt;
      if(flg) y++;
      else x++;
    }
  }
  Int ans=n*n-(n-z)*(n-z);
  ans+=(x+y)*(x+y);
  ans+=x*x;
  cout<<ans<<endl;
  return 0;
}
