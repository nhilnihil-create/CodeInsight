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
  vector<int> c(9, 0);
  rep(i, n){
    int a;
    cin >> a;
    a /= 400;
    if(a > 8) a = 8;
    c.at(a)++;
    // cerr << a << endl;
  }
  int mn = 0, mx = 0;
  rep(i, 8){
    if(c.at(i) > 0){
      mn++; mx++;
    }
  }
  if(c.at(8) > 0){
    if(mn == 0) mn++;
    mx += c.at(8);
  }
  cout << mn << " " << mx << endl;
  return 0;
}