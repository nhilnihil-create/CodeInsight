/**
 *    author:  lets
 *    created: 2020-06-07 18:34:47 JST
 **/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> col(9, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 400)
      col[0] = 1;
    else if (a[i] < 800)
      col[1] = 1;
    else if (a[i] < 1200)
      col[2] = 1;
    else if (a[i] < 1600)
      col[3] = 1;
    else if (a[i] < 2000)
      col[4] = 1;
    else if (a[i] < 2400)
      col[5] = 1;
    else if (a[i] < 2800)
      col[6] = 1;
    else if (a[i] < 3200)
      col[7] = 1;
    else
      col[8]++;
  }
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    ans += col[i];
  }
  if (ans == 0) {
    ans = 1;
    col[8]--;
  }
  cout << ans << ' ' << ans + col[8] << '\n';
  return 0;
}