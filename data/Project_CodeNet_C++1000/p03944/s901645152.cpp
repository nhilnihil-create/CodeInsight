#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int w, h, n; cin >> w >> h >> n;
  int xl=0, xu=w, yl=0, yu=h;
  rep(i,n) {
    int x, y, a; cin >> x >> y >> a;
    if (a == 1) xl = max(xl,x);
    if (a == 2) xu = min(xu,x);
    if (a == 3) yl = max(yl,y);
    if (a == 4) yu = min(yu,y);
  }
  w = xu - xl;
  h = yu - yl;
  int ans = 0;
  if (w < 0 || h < 0) ans = 0;
  else ans = w * h;
  cout << ans << endl;
  return 0;
}