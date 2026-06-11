#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);

  for (auto &i : a) cin >> i;

  int64_t sum = 0;
  vector<int64_t> b(2 * m + 3);

  for (int i = 1; i < n; ++i) {
    int l = a[i - 1], r = a[i] + (a[i - 1] < a[i] ? 0 : m);

    sum += r - l;
    b[l + 2]--;
    b[r + 1] += (r - l);
    b[r + 2] -= (r - l - 1);
  }

  for (int i = 1; i < b.size(); ++i) b[i] += b[i - 1];
  for (int i = 1; i < b.size(); ++i) b[i] += b[i - 1];

  int64_t ans = sum;
  for (int i = 1; i <= m; ++i) {
    ans = min(ans, sum + b[i] + b[i + m]);
  }

  cout << ans << endl;
}
