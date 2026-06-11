#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

ll power(ll x,ll n){
    if(n==0) return 1;
    ll res=power(x*x%mod,n/2);
    if(n&1) res=res*x%mod;
    return res;
}

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  ll v[n];
  rep(i,0,n){
    cin>>v[i];
  }
  sort(v,v+n);
  reverse(v,v+n);
  ll sum=0;
  rep(i,0,a){
    sum+=v[i];
  }
  cout<<fixed<<setprecision(10)<<(sum+0.0)/a<<endl;
  int c=0;
  int d=0;
  int e=0;
  rep(i,0,n){
    if(v[i]>v[a-1]) c++;
    else if(v[i]==v[a-1]) d++;
    else e++;
  }
  if(c!=0){
    ll cur=1;
    rep(i,1,a-c+1){
      cur=cur*(d+1-i)/i;
    }
    cout<<cur<<endl;
  }
  else{
    ll ans=0;
    ll cur=1;
    rep(i,1,min(d,b-c)+1){
      cur=cur*(d+1-i)/i;
      if(i>=a-c) ans+=cur;
    }
    cout<<ans<<endl;
  }
}