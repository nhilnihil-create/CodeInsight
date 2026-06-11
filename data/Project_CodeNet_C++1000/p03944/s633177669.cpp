#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  
  int x, y, a;
  int wmin=0, wmax=w, hmin=0, hmax=h;
  for(int i=0; i<n; i++) {
    cin >> x >> y >> a;
    if(a==1 && x>wmin) wmin = x; 
    else if(a==2 && x<wmax) wmax = x;
    else if(a==3 && y>hmin) hmin = y;
    else if(a==4 && y<hmax) hmax = y;
  }
  int ans = (wmax-wmin)*(hmax-hmin);
  if(wmax-wmin>0 && hmax-hmin>0) cout << ans << endl;
  else cout << 0 << endl;
  return 0;
}