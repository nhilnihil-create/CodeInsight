#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll ans=0;
  ll now=1;
  for(ll i=0;i<n;i++){
    ll a;cin>>a;
    if(i==0){
      ans+=a-1;
      now++;
      continue;
    }
    if(a==now){
      now++;
      continue;
    }
    if(a%now==0){
      ans+=a/now-1;
    }
    else{
      ans+=a/now;
    }
  }
  cout<<ans<<endl;
}