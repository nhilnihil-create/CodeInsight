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

int main(){
  int w, h, n;
  cin >> w >> h >> n;
  int l = 0, r = w, d = 0, u = h;
  rep(i, n){
    int x, y, mode;
    cin >> x >> y >> mode;
    if(mode == 1){
      l = max(l, x);
    }
    if(mode == 2){
      r = min(r, x);
    }
    if(mode == 3){
      d = max(d, y);
    }
    if(mode == 4){
      u = min(u, y);
    }
  }
  if(r < l || u < d) cout << 0 << endl;
  else cout << (r-l)*(u-d) << endl;
  return 0;
}