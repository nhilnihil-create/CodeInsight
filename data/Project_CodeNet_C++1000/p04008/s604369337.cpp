#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll par[100005]={0};
vector<ll> node[100005];
ll ans=0;
ll dfs(ll pos,ll k){
  ll max_d=0;
  for(int i=0;i<node[pos].size();i++){
    ll to=node[pos][i];
    max_d=max(max_d,dfs(to,k)+1);
  }
  if(max_d>=k-1&&par[pos]!=1){
    ans++;
    return -1;
  }
  else return max_d;
}
int main(){
  ll n,k;
  cin>>n>>k;
  for(ll i=1;i<=n;i++){
    cin>>par[i];
    if(i!=1) node[par[i]].push_back(i);
  }
  if(par[1]!=1) ans++;
  par[1]=1;
  dfs(1,k);
  cout<<ans<<endl;
}
