#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  int ball_cnt[n];
  bool red[n];
  for (int i = 0; i < n; i++) {
    ball_cnt[i] = 1;
    red[i] = false;
  }
  red[0] = true;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (red[x]) red[y] = true;

    ball_cnt[x]--;
    ball_cnt[y]++;
    if (!ball_cnt[x]) red[x] = false;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (red[i]) ans++;
  }

  cout << ans << endl;
  return 0;
}