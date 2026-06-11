#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int r, c, h, w;
  cin >> r >> c >> h >> w;
  if (r % h == 0 && c % w == 0) {
    cout << "No" << endl;
    return 0;
  }
  const int C = 999999999 / (h * w - 1);
  vector<vector<long long>> a(r, vector<long long>(c, C));
  for (int i = h - 1; i < r; i += h) {
    for (int j = w - 1; j < c; j += w) {
      a[i][j] = -(C * (h * w - 1) + 1);
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
