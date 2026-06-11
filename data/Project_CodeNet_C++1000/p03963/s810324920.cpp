#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n,k;
  cin>>n>>k;
  ll ans=1;
  ans*=k;
  for(ll i=1;i<n;i++){
    ans*=(k-1);
  }
  cout<<ans<<endl;
}