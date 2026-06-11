#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int w, h;
  cin >> w >> h;
  vector<pair<int, int>> v;
  for (int i = 0; i < w; i++) {
    int x;
    cin >> x;
    v.emplace_back(x, 0);
  }
  for (int i = 0; i < h; i++) {
    int x;
    cin >> x;
    v.emplace_back(x, 1);
  }
  sort(v.begin(), v.end());
  w++;
  h++;
  long long ans = 0;
  for (auto i : v) {
    if (i.second) ans += 1LL * w * i.first, h--;
    else ans += 1LL * h * i.first, w--;
  }
  cout << ans << endl;
  return 0; 
}