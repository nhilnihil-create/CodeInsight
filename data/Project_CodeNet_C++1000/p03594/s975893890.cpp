#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ul;
typedef signed long long ll;
ul over = 1000000007;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed;
  ll h, w, d;
  cin >> h >> w >> d;
  char cmap[5] = {'N', 'R', 'G', 'B', 'Y'};
  int color[h][w];
  for (ll i = 0; i < h; ++i) {
    for (ll j = 0; j < w; ++j) color[i][j] = 0;
  }
  for (ll i = 0; i <= h+w; ++i) {
    for (ll j = 0; j <= i; ++j) {
      ll xi = i-j, xj = j;
      if (xi < 0 || h <= xi) continue;
      if (xj < w) color[xi][xj] += (i/d)%2;
      xj = w - j - 1;
      if (0 <= xj && xj < w) color[xi][xj] += ((i/d)%2)*2;
    }
  }
  for (ll i = 0; i < h; ++i) {
    for (ll j = 0; j < w; ++j) {
      cout << cmap[color[i][j]+1];
    }
    cout << endl;
  }
  return 0;
}
