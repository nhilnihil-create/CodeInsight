#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int max_n = 1e6;
ll a[max_n];
int main(){
  ll n; cin >> n;
  map<ll,ll> ma;
  for(int i=0 ; i<n ; i++){
    cin >> a[i];
    ma[a[i]]++;
  }
  if(ma.count(0)){
    if(n%2==0 || ma[0] != 1){
      cout << 0 << endl;
      return 0;
    }
    ma.erase(0);
  }
  ll ans = 1;
  for(auto ite=begin(ma) ; ite != end(ma) ; ite++){
    if(ite -> second  != 2){
      cout << 0 << endl;
      return 0;
    }
    ans *= ite -> second % mod;
    ans %= mod;
  }
  cout << ans%mod << endl;
  return 0;
}
