#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  long long H, W;
  cin >> H >> W;

  if (H % 3 == 0 || W % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  long long mn = H * W;
  for (int i = 1; i < H; i++) {
    long long S1 = i * W;
    long long S2 = (H - i) * (W / 2);
    long long S3 = (H - i) * ((W + 1) / 2);
    long long Smax = std::max(S1, std::max(S2, S3));
    long long Smin = std::min(S1, std::min(S2, S3));
    if (mn > Smax - Smin) mn = Smax - Smin;

    if (H - i < 2) continue;
  
    S2 = (H - i) / 2 * W;
    S3 = (H - i + 1) / 2 * W;
    Smax = std::max(S1, std::max(S2, S3));
    Smin = std::min(S1, std::min(S2, S3));
    if (mn > Smax - Smin) mn = Smax - Smin;
  }

  for (int i = 1; i < W; i++) {
    long long S1 = i * H;
    long long S2 = (W - i) * (H / 2);
    long long S3 = (W - i) * ((H + 1) / 2);
    long long Smax = std::max(S1, std::max(S2, S3));
    long long Smin = std::min(S1, std::min(S2, S3));
    if (mn > Smax - Smin) mn = Smax - Smin;

    if (W - i < 2) continue;

    S2 = (W - i) / 2 * H;
    S3 = (W - i + 1) / 2 * H;
    Smax = std::max(S1, std::max(S2, S3));
    Smin = std::min(S1, std::min(S2, S3));
    if (mn > Smax - Smin) mn = Smax - Smin;
  }

  cout << mn << endl;

  return 0;
}
