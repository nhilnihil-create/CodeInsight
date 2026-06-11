#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll mod=1e9+7;
  ll n,m;
  cin>>n>>m;
  if(abs(n-m)==0){
    ll ans=2;
    for(ll i=1;i<=n;i++){
      ans*=i;
      ans%=mod;
      ans*=i;
      ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
  }
  if(abs(n-m)==1){
    ll ans=1;
    for(ll i=1;i<=min(n,m);i++){
      ans*=i;
      ans%=mod;
      ans*=i;
      ans%=mod;
    }
    ans*=max(n,m);
    ans%=mod;
    cout<<ans<<endl;
    return 0;
  }
  cout<<0<<endl;
  return 0;
}