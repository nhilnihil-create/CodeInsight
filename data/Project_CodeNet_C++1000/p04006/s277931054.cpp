#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long best = 1e18;
  vector<int> mi(n, 1e9);
  for (int y = 0; y <= n; ++y) {
    long long cur = (long long) x * y;
    for (int i = 0; i < n; ++i) {
      int j = (i + y) % n;
      mi[i] = min(mi[i], a[j]);
    }
    for (int i = 0; i < n; ++i) {
      cur += mi[i];
    }
    best = min(best, cur);
  }
  cout << best << endl;
  return 0;
}
