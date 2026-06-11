#include <bits/stdc++.h>
using namespace std;

long long n, k, suf = 0, pre = 0, mid = 0;
vector<long long> a;

int main() {
  cin >> n >> k;
  a.resize(n);
  for (auto &p : a) cin >> p;
  for (int i = k; i < n; ++i)
    if (a[i] > 0) suf += a[i];
  for (int i = 0; i < k; ++i) mid += a[i];
  long long res = 0;
  for (int i = k; i <= n; ++i) {
    res = max({res, pre + mid + suf, pre + suf});
    if (a[i - k] > 0) pre += a[i - k];
    mid -= a[i - k];
    if (i != n) {
      mid += a[i];
      if (a[i] > 0) suf -= a[i];
    }
  }
  cout << res << endl;
  return 0;
}
