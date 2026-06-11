#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[8];
int main() {
  for (int i = 1; i <= 7; ++i) scanf("%d", &a[i]);
  ll ans = a[2];
  if (!a[1] || !a[4] || !a[5])
    ans += a[1] / 2 * 2 + a[4] / 2 * 2 + a[5] / 2 * 2;
  else {
    ans += (ll)a[1] + a[4] + a[5];
    ans -= !(a[1] % 2 == a[4] % 2 && a[4] % 2 == a[5] % 2);
  }
  printf("%lld\n", ans);
  return 0;
}
