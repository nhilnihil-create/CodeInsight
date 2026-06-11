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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(snip_i, n) cin >> a.at(snip_i);
  sort(a.begin(), a.end());
  vector<ll> sums(n+1, 0);
  rep(i, n){
    sums.at(i+1) = sums.at(i) + a.at(i);
  }
  int ans = 1;
  rrep(i, n-1){
    ll ns = sums.at(i+1), na = a.at(i+1);
    if(ns *2 < na) break;
    ans++;
  }
  cout << ans << endl;

  return 0;
}