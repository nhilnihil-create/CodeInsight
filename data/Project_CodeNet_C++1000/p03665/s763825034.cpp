#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

ll calcNumOfCombination(ll n, ll r){
  ll num = 1;
  for(ll i = 1; i <= r; i++){
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main(){
  int n, p;
  cin >> n >> p;
  ll ev = 1, od = 0;
  rep(i, n){
    int a;
    cin >> a;
    if(a % 2 == 0){
      ev *= 2;
      od *= 2;
    }else{
      ll n = ev + od;
      ev = od = n;
    }
  }
  ll ans = 0;
  if(p % 2 == 0) ans = ev;
  else ans = od;
  // ans = od*ev;
  // if(p % 2 == 0){
  //   ll t = 0;
  //   rep2(i, 1, ev+1){
  //     t += calcNumOfCombination(ev, i);
  //   }
  //   cerr << ans << " " << t << endl;
  //   ans += t;
  // }
  cout << ans << endl;
  return 0;
}