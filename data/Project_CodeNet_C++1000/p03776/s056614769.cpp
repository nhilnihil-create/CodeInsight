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

ll calcNumOfCombination(ll n, ll r){
  ll num = 1;
  for(ll i = 1; i <= r; i++){
    num = num * (n - i + 1) / i;
  }
  return num;
}

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  map<ll, int> mp;
  rep(i, n){
    ll in;
    cin >> in;
    mp[in]++;
  }
  int co = 0;
  ll sum = 0, pans = 0;
  bool f = false;
  rrepit(itr, mp){
    if(a - itr->second - co > 0){
      co += itr->second;
      sum += itr->first*itr->second;
      f = true;
    }else{
      sum += itr->first*(a-co);
      if(f == false){
        rep2(i, a-co, min(b-co+1, itr->second+1)){
          pans += calcNumOfCombination(itr->second, i);
        }
      }else{
        pans += calcNumOfCombination(itr->second, a-co);
      }
      break;
    }
  }
  double ans = (double)sum/a;
  printf("%.10f\n", ans);
  cout << pans << endl;
  // vector<ll> v(n);
  // rep(i, n) cin >> v.at(i);
  // sort(v.rbegin(), v.rend());
  // ll mx = 0;
  // rep(i, a){
  //   mx += v.at(i);
  // }
  // int ans = 1;
  // rep2(i, a, n){
  //   if(v.at(a-1) == v.at(i)) ans++;
  // }
  // double p = (double)mx / a;
  // cout << p << endl;
  // cout << ans << endl;
  return 0;
}