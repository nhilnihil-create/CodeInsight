#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
ll fact(ll n){
  ll tmp = 1;
  for(int i=0; i<n; i++){
    tmp *= (i+1);
    tmp %= MOD;
  }
  return tmp;
}
int main(){
  ll a,b; cin >> a >> b;
  if(abs(a-b) >= 2){
    cout << 0 << endl;
    return 0;
  }
  ll ans = fact(a)*fact(b)%MOD;
  
  if(a == b){
    ans *= 2;
  }
  cout << ans%MOD << endl;
  
}
  