#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int N,M;
vector<vector<int> > G(101010);
int color[101010];

bool dfs(int v, int c){
  color[v]=c;
  bool res=1;
  for(int u:G[v]){
    if(color[u]==-1) res&=dfs(u,(c+1)%2);
    else if(color[u]==c) res=0;
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin>>N>>M;
  rep(i,M){
    int u,v; cin>>u>>v; u--,v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  rep(i,N) color[i]=-1;
  int koritu=0,nibu=0,kihei=0;
  rep(i,N) if(color[i]==-1){
    if(G[i].size()==0) koritu++;
    else{
      if(dfs(i,0)) nibu++;
      else kihei++;
    }
  }
  ll ans=0;
  ans+=1LL*koritu*koritu;
  ans+=2LL*koritu*(N-koritu);
  ans+=2LL*nibu*nibu;
  ans+=1LL*kihei*kihei;
  ans+=2LL*kihei*nibu;
  cout<<ans<<endl;
  return 0;
}
