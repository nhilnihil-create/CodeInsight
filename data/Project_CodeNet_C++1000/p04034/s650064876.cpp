#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//UnionFindで1のもの
//だめか。1ときはとらざるをえない

int main(){
  ll N,M; cin>>N>>M;
  vector<ll> G(N+1,1);
  vector<bool> is_red(N+1, false);
  is_red[1]=true;
  for(int i=0; i<M; i++){
    ll a,b; cin>>a>>b;
    if(G[a]==1 && is_red[a]){
      is_red[a]=false;
      is_red[b]=true;
    }
    else if(G[a]>1 && is_red[a])
      is_red[b]=true;
    G[a]--;
    G[b]++;
  }
  ll ans=0;
  for(int i=1; i<=N; i++){
    if(is_red[i]) ans++;
  }
  cout<<ans<<endl;
}