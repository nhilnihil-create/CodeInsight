#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int c[101] = {};
  int ans = 0;

  for (int i = 0; i < 3; ++i) {
    int a;
    cin >> a;

    ++c[a];
  }

  for (auto e : c) if (e) ++ans;

  cout << ans << endl;

  return (0);
}
