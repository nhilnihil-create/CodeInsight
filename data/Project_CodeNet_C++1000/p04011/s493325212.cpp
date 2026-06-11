#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k, x, y; cin >> n >> k >> x >> y;
  int ans = 0;

  if (n <= k) ans += x * n;
  else ans += k * x + (n - k) * y;

  cout << ans << endl;
}