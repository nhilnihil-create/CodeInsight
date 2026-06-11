#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  int mx = 0, MX = W;
  int my = 0, MY = H;
  rep(i, N) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) mx = max(x, mx);
    if (a == 2) MX = min(x, MX);
    if (a == 3) my = max(y, my);
    if (a == 4) MY = min(y, MY);
  }
  if (mx >= MX || my >= MY) cout << 0 << endl;
  else cout << (MX - mx) * (MY - my) << endl;
  return 0;
}
