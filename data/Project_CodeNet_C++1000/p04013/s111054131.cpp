#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll pw(ll x,ll y){
  if(y==0) return 1;
  ll z=pw(x*x,y/2);
  if(y%2==1) z*=x;
  return z;
}
int main(){
  ll n,a,i,j,zn=0,pn=0,mn=0,psum=0,msum=0,ma,ans=0;
  cin>>n>>a;
  vector<ll> x(n),p,m;
  for(i=0;i<n;i++){
    cin>>x[i];
    x[i]-=a;
    if(x[i]==0) zn++;
    else if(x[i]>0){
      pn++;
      psum+=x[i];
      p.push_back(x[i]);
    }
    else if(x[i]<0){
      mn++;
      msum-=x[i];
      m.push_back(-x[i]);
    }
  }
  ma=min(psum,msum);
  vector<vector<ll>> pdp(pn+1,vector<ll>(ma+1)),mdp(mn+1,vector<ll>(ma+1));
  pdp[0][0]=1;
  mdp[0][0]=1;
  for(i=0;i<pn;i++){
    for(j=0;j<=ma;j++){
      pdp[i+1][j]+=pdp[i][j];
      if(j+p[i]<=ma) pdp[i+1][j+p[i]]+=pdp[i][j];
    }
  }
  for(i=0;i<mn;i++){
    for(j=0;j<=ma;j++){
      mdp[i+1][j]+=mdp[i][j];
      if(j+m[i]<=ma) mdp[i+1][j+m[i]]+=mdp[i][j];
    }
  }
  for(j=0;j<=ma;j++) ans+=pdp[pn][j]*mdp[mn][j];
  ans=ans*pw(2,zn)-1;
  cout<<ans<<endl;
}