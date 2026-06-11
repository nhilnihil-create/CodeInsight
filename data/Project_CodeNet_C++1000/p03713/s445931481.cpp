#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  long long h, w;
  cin >> h >> w;
  long long ans = (1LL << 60);

  // patern A (三枚おろし)
  if (h >= 3) {
    if (h % 3 == 0) {
      ans = 0;
    } else {
      ans = min(ans, w);
    }
  }
  if (w >= 3) {
    if (w % 3 == 0) {
      ans = 0;
    } else {
      ans = min(ans, h);
    }
  }

  // patern B (横に切ってから, 縦)
  for (long long i = 0; i < h - 1; i++) {
    long long area1 = (i + 1) * w;
    long long area2 = (h - i - 1) * (w / 2);
    long long area3 = (h - i - 1) * ((w + 1) / 2);
    ans = min(ans, max({area1, area2, area3}) - min({area1, area2, area3}));
  }
  // patern C (縦に切ってから, 横)
  for (long long i = 0; i < w - 1; i++) {
    long long area1 = (i + 1) * h;
    long long area2 = (w - i - 1) * (h / 2);
    long long area3 = (w - i - 1) * ((h + 1) / 2);
    ans = min(ans, max({area1, area2, area3}) - min({area1, area2, area3}));
  }

  cout << ans << endl;
  return 0;
}