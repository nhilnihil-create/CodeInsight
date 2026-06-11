#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int N, K;
vector<vector<int>> G(101010);
int ans=0;

int dfs(int v, int p){
  int ma=0;
  for(int u:G[v]) if(u!=p){
    ma=max(ma,dfs(u,v));
  }
  if(ma+1==K){
    if(p!=0) ans++;
    return 0;
  }else return (ma+1);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin>>N>>K;
  rep(i,N){
    int a; cin>>a; a--;
    if(i) G[a].push_back(i);
    else if(a!=0) ans++;
  }
  dfs(0,0);
  cout<<ans<<endl;
  return 0;
}
