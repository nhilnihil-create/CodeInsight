#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
  ll n,t,ans=0,res=0; cin>>n>>t;
  vector<ll> d(n);
  cin>>d[0];
  for(ll i=1; i<n; i++) {
    ll x; cin>>x;
    d[i] = x-res;
    res = x;
  }
  for(ll i=1; i<d.size(); i++) {
    if(d[i]>t) ans += t;
    else ans += d[i];
  }
  ans += t;
  cout<<ans;
}