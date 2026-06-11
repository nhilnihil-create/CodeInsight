#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  ll n,x;
  cin >> n >> x;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  ll old = min(v[0],x*1ll);
  ll sum = max(0ll,v[0]-x);
  ll res = 1ll << 60;
  rep(i,n-1){
    if(v[i+1]+old > x)sum += v[i+1]+old-x,old = x-old;
    else old = v[i+1];
  }
  res = min(res,sum);
  sum = max(v.back()-x,0ll);
  old = min(x*1ll,v.back());
  for(ll i = n-2;i >= 0;i--){
    if(v[i]+old > x)sum += v[i]+old-x,old = x-old;
    else old = v[i];
  }
  res = min(res,sum);
  cout << res << endl;




  return 0;
}
