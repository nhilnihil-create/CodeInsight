#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int64_t> C(26, 0);
  int H, W;
  cin >> H >> W;
  char c;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> c;
      int idx = c - 'a';
      C[idx]++;
    }
  }
  int fs = (H / 2) * (W / 2), ts = 0, os = 0;
  if (H % 2)
    ts += W / 2;
  if (W % 2)
    ts += H / 2;
  if (H % 2 && W % 2)
    os++;
  for (int i = 0; i < 26; i++)
  {
    while (C[i] >= 4 && fs > 0)
    {
      C[i] -= 4;
      fs--;
    }
    while (C[i] >= 2 && ts > 0)
    {
      C[i] -= 2;
      ts--;
    }
    if (C[i] == 1 && os > 0)
    {
      C[i]--;
      os--;
    }
  }
  cout << ((fs == 0 && ts == 0) ? "Yes" : "No") << endl;
}