#include <bits/stdc++.h>
using namespace std;
int64_t INF = 10000000000;

int main()
{
  int64_t H, W, d1 = INF, d2 = INF, d3 = INF, d4 = INF;
  cin >> H >> W;

  // 1. 縦に3分割
  if (W >= 3)
  {
    d1 = (W % 3 == 0) ? 0 : H;
    if (d1 == 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }

  // 2. 横に3分割
  if (H >= 3)
  {
    d2 = (H % 3 == 0) ? 0 : W;
    if (d2 == 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }

  // 3. 縦に1回分割(1/3)。大きい方を横に分割(1/2)
  int64_t s1, s2, s3, h, w;
  for (int w = 1; w < W; w++)
  {
    s1 = w * H;
    h = H / 2;
    s2 = (W - w) * h;
    s3 = (W - w) * (H - h);
    d3 = min(d3, max(s1, max(s2, s3)) - min(s1, min(s2, s3)));
  }

  // 4. 横に1回分割(1/3)。大きい方を縦に分割(1/2)
  for (int h = 1; h < H; h++)
  {
    s1 = h * W;
    w = W / 2;
    s2 = (H - h) * w;
    s3 = (W - w) * (H - h);
    d4 = min(d4, max(s1, max(s2, s3)) - min(s1, min(s2, s3)));
  }

  cout << min(min(d1, d2), min(d3, d4)) << endl;
}
