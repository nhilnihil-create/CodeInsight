#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  int now = 0, rank = 1;
  for (auto c : s) {
    int d = c - 'a';
    bool ok = true;

    switch (d) {
      case 0:
        if (now < a + b) ++now;
        else ok = false;
        break;
      case 1:
        if (now < a + b && rank <= b) ++rank, ++now;
        else ok = false;
        break;
      case 2:
        ok = false;
        break;
    }

    if (ok) puts("Yes");
    else puts("No");
  }

  return (0);
}