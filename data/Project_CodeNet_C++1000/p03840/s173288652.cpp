#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c, d, e, f, g;
  cin >> a >> d >> e >> b >> c >> f >> g;
  long long ans = 0;
  if (a % 2 && b % 2 && c % 2) {
    --a, --b, --c;
    ans += 3;
  } else if (a % 2 && (b % 2 && c || c % 2 && b)) {
    --a, --b, --c;
    ans += 3;
  } else if (b % 2 && c % 2 && a) {
    --a, --b, --c;
    ans += 3;
  }
  a = a / 2 * 2;
  b = b / 2 * 2;
  c = c / 2 * 2;
  ans += a + b + c + d;
  cout << ans << endl;
  return 0;
}
