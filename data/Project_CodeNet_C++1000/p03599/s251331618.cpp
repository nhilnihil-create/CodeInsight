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
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  a *= 100; b *= 100;
  set<int> water, sugar;
  rep(i, f+1){
    rep(j, f+1){
      if(i == j && i == 0) continue;
      int add = a*i + b*j;
      if(add > f) continue;
      water.insert(add);
    }
  }
  rep(i, f+1){
    rep(j, f+1){
      int add = c*i + d*j;
      if(add > f) continue;
      sugar.insert(add);
    }
  }

  pair<int, int> ans(-1, -1);
  double p = -1;
  for(auto wa : water){
    for(auto su : sugar){
      if(wa+su > f) break;
      double ap = (double)su/(wa+su);
      if(ap > (double)e/(100+e)) break;
      if(ap > p){
        ans = make_pair(wa, su);
        p = ap;
      }
    }
  }
  cout << ans.first+ans.second << " " << ans.second << endl;
  return 0;
}