#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> cnt(100010);
  for (int i = 0; i < n; i++) cnt[a[i]]++;

  int ans = 0;
  for (int i = 1; i < 100000; i++) {
    ans = max(ans, cnt[i] + cnt[i - 1] + cnt[i + 1]);
  }
  cout << ans << endl;
}
