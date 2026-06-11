#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> ya(1000,1);
  for(ll i=1;i<=n;i++){
    ll cp=i;
    for(ll j=2;j*j<=n;j++){
      while(cp%j==0){
        ya.at(j)++;
        cp/=j;
      }
    }
    if(cp!=1){
      ya.at(cp)++;
    }
  }
  ll ans=1,mod=1e9+7;
  rep(i,1000){
    ans*=ya.at(i);
    ans%=mod;
  }
  cout << ans;
}
    
  