#include <bits/stdc++.h>
using namespace std;

template<class T> inline int sgn(T x){return (x>0)-(x<0);}

int main() {
  int x, y, ans; cin >> x >> y;

  if (sgn(x) == sgn(y)) {
    if (x <= y) ans = y - x;
    else ans = 2 + x - y;
  }
  else ans = 1 + abs(abs(y) - abs(x));
  
  if (x == 0) ans = ((sgn(y) == 1) ? y : abs(y) + 1);
  if (y == 0) ans = ((sgn(x) == 1) ? x + 1 : abs(x));
  
  cout << ans << endl;
  return 0;
}