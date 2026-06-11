#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,T;
  cin >> n >> T;
  vector<ll> t(n);
  rep(i,n){
    cin >> t.at(i);
  }
  ll ans=0,sum=0;
  for(ll i=1;i<n;i++){
    if(t.at(i)-t.at(i-1)<=T){
      ans+=t.at(i)-t.at(i-1);
    }else{
      ans+=T;
    }
  }
  cout << ans+T;
}