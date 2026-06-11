#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  int s = 0, t = 0;
  rep(i,n) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      if (s<x) s=x;
    }
    if (a == 2) {
      if (w>x) w=x;
    }
    if (a==3) {
      if (t<y) t=y;
    }
    if (a==4) {
      if (h>y) h=y;
    }
  }
  if (w-s <= 0 || h-t <= 0) {
    cout << 0 << endl;
    return 0;
  }
  int ans = (w-s)*(h-t);
  cout << ans << endl;
  return 0;
}