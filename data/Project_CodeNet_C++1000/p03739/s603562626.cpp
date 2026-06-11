#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;
int n, a[100010];
ll calc(ll s) {
  ll sum = 0, res = 0;
  for (int i = 0; i < n; ++i, s *= -1) {
    sum += a[i];
    if (sum * s > 0) continue;
    if (s > 0)
      res += (-sum + s), sum += (-sum + s);
    else
      res += (sum - s), sum += -(sum - s);
  }
  return res;
}
int main() {
  cin >> n;
  rep(i, n) cin >> a[i];
  cout << min(calc(1), calc(-1)) << endl;
  return 0;
}