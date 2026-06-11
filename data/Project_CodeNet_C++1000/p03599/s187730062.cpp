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
  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  a *= 100; b *= 100;
  vector<double> water, sugar;
  rep(i, f+1){
    if(i * a > f) break;
    rep(j, f+1){
      double add = i*a + j*b;
      if(add <= f) water.push_back(add);
      else break;
    }
  }
  rep(i, f+1){
    if(i * c > f) break;
    rep(j, f+1){
      double add = i*c + j*d;
      if(add <= f) sugar.push_back(add);
      else break;
    }
  }
  double ap = 0;
  pair<double, double> ans;
  for(double wa : water){
    for(double su : sugar){
      if(wa + su == 0) continue;
      double p = su/(wa+su);
      if(p <= e/(100.+e) && wa + su <= f){
        if(ap <= p){
          ap = p;
          ans = make_pair(wa, su);
        }
      }
    }
  }
  int a1 = ans.first + ans.second, a2 = ans.second;
  cout << a1 << " " << a2 << endl;
  return 0;
}