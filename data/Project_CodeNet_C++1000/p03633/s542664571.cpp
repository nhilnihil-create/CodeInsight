#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, ll>;
#define rep(i, n) for (int i = 0; i < n; ++i)

ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
ll lcm(ll a,ll b){
  ll g=gcd(a,b);
  return a/g*b;
}

main() {
  ll n;cin>>n;
  ll ans;cin>>ans;
  for(ll i=1;i<n;i++){
    ll t;cin>>t;
    ans=lcm(ans,t);
  }
  
  cout << ans << endl;
  return 0;
}