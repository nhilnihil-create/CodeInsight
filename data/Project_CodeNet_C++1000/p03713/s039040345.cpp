#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long H, W;
  cin >> H >> W;
  
  long ans = H * W;
  long S1, S2, S3;
  for (int w1 = 1; w1 < W; w1++) {
    S1 = H * w1;
    if (H % 2 == 0 || (W - w1) % 2 == 0) {
      S2 = H * (W - w1) / 2; // == S3
      ans = min(ans, abs(S1 - S2));
    } else if (H <= W - w1) {
      S2 = H * ((W - w1) / 2);
      S3 = S2 + H;
      ans = min(ans, max({S1, S2, S3}) - min({S1, S2, S3}));
    } else {
      S2 = (W - w1) * (H / 2);
      S3 = S2 + (W - w1);
      ans = min(ans, max({S1, S2, S3}) - min({S1, S2, S3}));
    }
  }
  for (int h1 = 1; h1 < H; h1++) {
    S1 = W * h1;
    if (W % 2 == 0 || (H - h1) % 2 == 0) {
      S2 = W * (H - h1) / 2; // == S3
      ans = min(ans, abs(S1 - S2));
    } else if (W <= H - h1) {
      S2 = W * ((H - h1) / 2);
      S3 = S2 + W;
      ans = min(ans, max({S1, S2, S3}) - min({S1, S2, S3}));
    } else {
      S2 = (H - h1) * (W / 2);
      S3 = S2 + (H - h1);
      ans = min(ans, max({S1, S2, S3}) - min({S1, S2, S3}));
    }
  }
  
  cout << ans << endl;
  return 0;
}