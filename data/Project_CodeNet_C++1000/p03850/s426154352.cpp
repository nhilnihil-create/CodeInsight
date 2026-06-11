#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define re register
#define il inline
#define inf 0x3f3f3f
#define N 100010
using namespace std;

ll f[N], g[N], a[N];
char op, lst;

int main() {
  int n, x, y = 0, i, cnt = 0;
  cin >> n;
  ll ans = 0;
  for (i = 1; i <= n; ++i) {
    cin >> x;
    lst = op;
    if (i < n)
      cin >> op;
    if (lst == '-') {
      x = -x;
      a[++cnt] = x;
    }
    if (y <= 0 && x > 0)
      cnt++, a[cnt] = x;
    if (y > 0 && x > 0)
      a[cnt] += x;
    y = x;
  }
  f[1] = a[1];
  for (i = cnt; i >= 1; --i)
    g[i] = g[i + 1] + abs(a[i]);
  for (i = 2; i <= cnt; ++i)
    f[i] = f[i - 1] + a[i];
  ans = f[cnt];
  for (i = 1; i < cnt; ++i)
    if (a[i + 1] < 0)
      ans = max(ans, f[i + 1] - a[i + 2] + g[i + 3]);
  cout << ans;
}
