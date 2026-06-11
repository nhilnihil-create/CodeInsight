#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void)
{
  int H, W;
  char C[105][105];

  cin >> H >> W;
  for (int i = 1; i <= H; ++i)
  {
    for (int j = 1; j <= W; ++j)
    {
      cin >> C[i][j];
    }
  }

  for (int i = 1; i <= H * 2; ++i)
  {
    for (int j = 1; j <= W; ++j)
    {
      cout << C[(i + 1) / 2][j];
    }
    cout << endl;
  }

  return 0;
}