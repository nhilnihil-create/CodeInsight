#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=1; i<=(ll)(n); i++)
ll l=1000000007;

int main() {
  ll n,m;cin>>n>>m;
  ll ans=1;
  if(abs(n-m)<=1){
    rep(i,n){
      ans*=i;
      if(ans>=l)ans%=l;
    }
    rep(i,m){
      ans*=i;
      if(ans>=l)ans%=l;
    }
    if(n==m){
      ans*=2;
      if(ans>=l)ans%=l;
    }
  }
  else{ans=0;}
  cout<<ans;
  
  
}