//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
//const ll MOD=998244353LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

int main(){
  ll n,k;cin>>n>>k;
  vl a(n);
  rep(i,n)cin>>a[i];
  vl b(n);
  rep(i,n)b[i]=a[i];
  ll ans=0;
  ll total=0;
  rep(i,n)total+=b[i];
  ll ans2=0;
  rep(i,n){
    if(a[i]>0){
      ans+=a[i];
      a[i]=0;
    }
    else {
      ans2+=b[i];
      b[i]=0;
    }
  }
  ll MAX=-INF;
  vl sum(n+1);
  sum[1]=a[0];
  rep(i,n-1)sum[i+2]=sum[i+1]+a[i+1];
  rep(i,n-k+1){
    MAX=max(MAX,sum[i+k]-sum[i]);
  }
  ans+=MAX;
  
  ll MIN=INF;
  vl sum2(n+1);
  sum2[1]=b[0];
  rep(i,n-1)sum2[i+2]=sum2[i+1]+b[i+1];
  rep(i,n-k+1){
    MIN=min(MIN,sum2[i+k]-sum2[i]);
  }
  ans2+=MIN;
  //for(ll i=1;i<=n;i++)cout<<sum2[i]<<" ";
  //cout<<endl;
  //cout<<total<<" "<<ans2<<" "<<MIN<<endl;
  cout<<max(ans,total-ans2)<<endl;
}