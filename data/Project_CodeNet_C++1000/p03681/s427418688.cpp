#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll n,m;
  cin >> n >> m;
  if(abs(n-m)>1){
    cout << 0 << endl;
    return 0;
  }
  if(abs(n-m)==1){
    ll ans=1;
    ll k=min(n,m);
    for(ll i=1;i<k+1;i++){
      ans=(ans*i)%MOD;
    }
    ans=ans%MOD;
    cout << ((ans*ans)%MOD*max(n,m))%MOD << endl;
  }
  if(n==m){
    ll ans=1;
    for(ll i=1;i<n+1;i++){
      ans=(ans*i)%MOD;
    }
    ans=ans%MOD;
    cout << (ans*ans*2)%MOD << endl;
  }
}

