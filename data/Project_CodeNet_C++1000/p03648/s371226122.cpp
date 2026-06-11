#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long k;
  cin >> k;
  int n = 50;
  long long d = k / n;
  k -= d * n;
  vector<long long> a(n, n - 1 + d);
  for (int i = 0; i < k; i++) {
    a[i] += n - k + 1;
  }
  for (int i = k; i < n; i++) {
    a[i] -= k;
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i < n) cout << ' '; else cout << '\n';
  }
  return 0;
}