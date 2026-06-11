#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n + 1), ps(n + 1), s(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ps[i] = ps[i - 1] + (a[i] > 0 ? a[i] : 0);
    s[i] = s[i - 1] + a[i];
  }
  long long best = 0;
  for (int i = 1; i <= n - k + 1; ++i) {
    best = max(best, ps[i - 1] + ps[n] - ps[i + k - 1] + max(0ll, s[i + k - 1] - s[i - 1]));
  }
  cout << best << endl;
  return 0;
}
