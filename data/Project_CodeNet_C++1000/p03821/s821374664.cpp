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
  vector<int> a(n), b(n);
  rep(i, n){
    int aa, bb;
    cin >> aa >> bb;
    a.at(i) = aa;
    b.at(i) = bb;
  }
  ll ans = 0;
  rrep(i, n){
    ll now = a.at(i), ta = b.at(i);
    now += ans;
    if(now % ta != 0){
      ans += ta - now % ta;
    }
  }
  cout << ans << endl;
  return 0;
}