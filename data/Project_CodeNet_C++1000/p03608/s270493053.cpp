#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int main() {
  int n,m,r;
  cin>>n>>m>>r;
  int p[r];
  for(int i=0;i<r;i++){
    int v;
    cin>>v;
    v--;
    p[i]=v;
  }
  ll d[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      d[i][j]=10000000;
    }
  }
  for(int i=0;i<n;i++) d[i][i]=0;
  for(int i=0;i<m;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    d[a][b]=min(d[a][b],c);
    d[b][a]=d[a][b];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
      }
    }
  }
  sort(p,p+r);
  ll ans=1000000000;
  do{
    ll temp=0;
    for(int i=0;i<r-1;i++){
      temp+=d[p[i]][p[i+1]];
    }
    ans=min(temp,ans);
  }while(next_permutation(p,p+r));
  cout<<ans<<endl;
  return 0;
}

