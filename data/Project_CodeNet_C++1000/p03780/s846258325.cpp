#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  uint64_t sum = 0;
  int ans = n;
  for (int i = n-1; 0 <= i; --i) {
    if (sum + a[i] < k) sum += a[i];
    else ans = min(ans, i);
  }
  cout << ans << "\n";
}
