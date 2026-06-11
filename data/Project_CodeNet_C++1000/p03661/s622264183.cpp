#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long now = 0, ans = 1e18;
  for (int i = 1; i < n; i++) {
    now += a[i - 1];
    ans = min(ans, abs(now - (sum - now)));
  }
  cout << ans << '\n';
  return 0;
}