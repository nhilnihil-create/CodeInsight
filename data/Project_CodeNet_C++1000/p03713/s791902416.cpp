#include <bits/stdc++.h>
using namespace std;

int main() {
  long H, W;
  cin >> H >> W;
  if (H % 3 == 0 || W % 3 == 0) return cout << 0 << "\n", 0;
  long ans = min(H, W);
  for (int h = 0; h < H - 1; h++) {
    long a = (h + 1) * W;
    long b = (H - h - 1) * (W / 2);
    long c = (H - h - 1) * (W - W / 2);
    ans = min(ans, max({a, b, c}) - min({a, b, c}));
  }
  swap(H, W);
  for (int h = 0; h < H - 1; h++) {
    long a = (h + 1) * W;
    long b = (H - h - 1) * (W / 2);
    long c = (H - h - 1) * (W - W / 2);
    ans = min(ans, max({a, b, c}) - min({a, b, c}));
  }
  cout << ans << "\n";
}