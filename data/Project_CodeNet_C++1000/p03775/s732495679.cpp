#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int fsz(ll n){
  int res = 0;
  while(n != 0){
    res++;
    n /= 10;
  }
  return res;
}

int main(){
  ll n;
  cin >> n;
  int ans = 1001001001;
  for(ll i = 1; i*i <= n; i++){
    if(n % i != 0) continue;
    ll j = n/i;
    ans = min(ans, max(fsz(i), fsz(j)));
  }
  cout << ans << endl;
  return 0;
}