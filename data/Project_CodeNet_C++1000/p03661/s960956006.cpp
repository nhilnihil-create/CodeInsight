/**
 *    author:  tourist
 *    created: 20.11.2019 14:11:01       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  long long ans = (long long) 9e18;
  for (int i = 1; i < n; i++) ans = min(ans, abs(2 * a[i] - a[n]));
  cout << ans << '\n';
  return 0;
}
