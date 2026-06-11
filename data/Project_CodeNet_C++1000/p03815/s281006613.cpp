#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  long long x, num;
  cin >> x;
  num = (x + 11 - 1) / 11;
  long long ans = 2 * num;
  if (x <= 11 * (num - 1) + 6)
    ans--;
  cout << ans << endl;
  return 0;
}