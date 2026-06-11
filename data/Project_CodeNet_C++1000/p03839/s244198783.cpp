/**
 *    author:  tourist
 *    created: 27.01.2020 05:40:27       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long inner = 0;
  for (int i = 0; i < k; i++) {
    inner += a[i];
  }
  long long outer = 0;
  for (int i = k; i < n; i++) {
    outer += max(a[i], 0);
  }
  long long ans = max(inner, 0LL) + outer;
  for (int i = k; i < n; i++) {
    inner += a[i] - a[i - k];
    outer += max(a[i - k], 0) - max(a[i], 0);
    ans = max(ans, max(inner, 0LL) + outer);
  }
  cout << ans << '\n';
  return 0;
}
