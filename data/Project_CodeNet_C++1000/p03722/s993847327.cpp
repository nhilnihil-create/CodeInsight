#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P2;
vector<P> kn[3005];
bool used[3005];
ll mincost[3005]={0};
bool dfs(ll pos,ll goal){
  if(pos==goal) return true;
  for(int i=0;i<kn[pos].size();i++){
    ll to=kn[pos][i].first;
    if(!used[to]){
      used[to]=true;
      if(dfs(to,goal)) return true;
    }
  }
  return false;
}
int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    ll s,t,cos;
    cin>>s>>t>>cos;
    kn[s].push_back(P(t,-cos));
  }
  ll gs=0;
  vector<P2> node;
  for(int i=1;i<=n;i++){
    for(int j=0;j<3005;j++) used[j]=false;
    used[i]=true;
    if(dfs(i,n)){
      for(int j=0;j<3005;j++) used[j]=false;
      used[1]=true;
      if(!dfs(1,i)) continue;
      for(int j=0;j<kn[i].size();j++) node.push_back(P2(i,kn[i][j]));
      gs++;
    }
  }
  for(int i=2;i<=3005;i++) mincost[i]=17441744174417;
  int cnt=0;
  while(1){
    bool upd=false;
    for(int i=0;i<node.size();i++){
      ll s=node[i].first,t=node[i].second.first,cos=node[i].second.second;
      if(mincost[s]+cos<mincost[t]){
        upd=true;
        mincost[t]=mincost[s]+cos;
      }
    }
    cnt++;
    if(!upd) break;
    if(upd&&cnt>=gs){
      cout<<"inf"<<endl;
      return 0;
    }
  }
  cout<<mincost[n]*-1<<endl;
  return 0;
}
