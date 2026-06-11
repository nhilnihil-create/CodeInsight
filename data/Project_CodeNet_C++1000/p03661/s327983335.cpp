#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long) 1e18;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long sum = accumulate(a, a + n, 0LL);
  for (int i = 1; i < n; i++) a[i] += a[i - 1];
  long long res = INF;
  for (int i = 0; i < n - 1; i++) {
    res = min(res, abs(a[i] - (sum - a[i])));
  }
  cout << res << "\n";
  return 0;
}