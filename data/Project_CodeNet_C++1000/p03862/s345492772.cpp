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
  int n, x;
  cin >> n >> x;
  int bf;
  ll ans = 0;
  rep(i, n){
    int in;
    cin >> in;
    if(i == 0){
      if(in > x){
        ans += in - x;
        in = x;
      }
    }else{
      if(bf + in > x){
        ans += bf + in - x;
        in = x - bf;
      }
    }
    bf = in;
  }
  cout << ans << endl;
  return 0;
}