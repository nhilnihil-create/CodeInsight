#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(snip_i, n) cin >> a.at(snip_i);
  vector<ll> sum(n);
  rep(i, n){
    sum.at(i) = a.at(i);
    if(i > 0) sum.at(i) += sum.at(i-1);
  }
  ll ans1 = 0, ans2 = 0;
  ll pos = 0;
  rep(i, n){//du
    if(i % 2 == 0){
      if(pos <= sum.at(i)){
        ans1 += sum.at(i) - pos + 1;
        pos = sum.at(i) + 1;
      }
    }else{
      if(pos >= sum.at(i)){
        ans1 += pos - sum.at(i) + 1;
        pos = sum.at(i) - 1;
      }
    }
  }

  pos = 0;
  rep(i, n){//du
    if(i % 2 == 1){
      if(pos <= sum.at(i)){
        ans2 += sum.at(i) - pos + 1;
        pos = sum.at(i) + 1;
      }
    }else{
      if(pos >= sum.at(i)){
        ans2 += pos - sum.at(i) + 1;
        pos = sum.at(i) - 1;
      }
    }
  }

  ll ans = min(ans1, ans2);
  cout << ans << endl;
  return 0;
}