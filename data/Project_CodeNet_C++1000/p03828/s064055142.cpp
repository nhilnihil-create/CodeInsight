#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int max_n = 1e6;
ll a[max_n];
vector<ll> v;
map<ll,ll> ma;
ll n;

int main(){
  cin >> n;
  map<ll,ll> ma;
  for(ll nn=2 ; nn<=n ; nn++){
    ll k = nn;
    for(ll i=2 ; i*i<=k ; i++){
      while(k % i == 0){
        ++ma[i];
        k /= i;
      }
    }
    if(k!=1) ma[k]++;
  }
  ll ans = 1;
  for(auto ite=begin(ma) ; ite!=end(ma); ite++){
    ans *= (ite->second+1) % mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
