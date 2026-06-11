#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, d;
  cin >> h >> d;
  if(h % 3 == 0 || d % 3 == 0){
    cout << 0 << endl;
    return 0;
  }
  int ans = 1000000;
  // case 1
  ans = min(h, d);
  
  //case 2
  int as = h/3, al = as + 1;
  int sa = as * d, sb = (h-as) * (d/2), sc = h*d - sa - sb;
  int t = max(abs(sa-sb), max(abs(sb-sc), abs(sc-sa)));
  int la = al * d, lb = (h-al) * (d/2), lc = h*d - la - lb;
  int u = max(abs(la-lb), max(abs(lb-lc), abs(lc-la)));
  ans = min(u, min(ans, t));
  
  //case 3
  as = d/3, al = as + 1;
  sa = as * h, sb = (d-as) * (h/2), sc = h*d - sa - sb;
  t = max(abs(sa-sb), max(abs(sb-sc), abs(sc-sa)));
  la = al * h, lb = (d-al) * (h/2), lc = h*d - la - lb;
  u = max(abs(la-lb), max(abs(lb-lc), abs(lc-la)));
  ans = min(u, min(ans, t));
  
  cout << ans << endl;
}