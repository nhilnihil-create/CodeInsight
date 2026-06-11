#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m);
  rep(i, m) {
    cin >> x[i] >> y[i];
    --x[i];
    --y[i];
  }

  vector<int> ball(n, 1), red(n, 0);
  red[0] = 1;

  rep(i, m) {
    --ball[x[i]];
    ++ball[y[i]];
    if (red[y[i]] == 0) red[y[i]] = red[x[i]];
    if (ball[x[i]] == 0) red[x[i]] = 0;
  }

  int ans = 0;
  rep(i, n) ans += red[i];
  cout << ans << endl;

  return 0;
}