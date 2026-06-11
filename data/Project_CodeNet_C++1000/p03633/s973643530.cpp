#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  ll g;
  int n;
  cin >> n;
  vector<ll> t(n);
  ll ans = 1;
  rep(i, n){
    ll in;
    cin >> in;
    t.at(i) = in;
    if(i == 0){
      g = in;
      ans = in;
    }else{
      g = __gcd(in, ans);
      ans = ans / g * t.at(i);
    }
  }
  cout << ans << endl;
  return 0;
}