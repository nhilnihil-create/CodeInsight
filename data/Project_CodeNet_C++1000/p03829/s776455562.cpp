#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int64_t a, b, ans = 0;
  cin >> n >> a >> b;
  vector < int64_t > x(n);
  for (int64_t &y: x)
    cin >> y;
  for (int i = 1; i < n; ++i) 
    ans += min((x[i] - x[i - 1]) * a, b);
  cout << ans << '\n';
}