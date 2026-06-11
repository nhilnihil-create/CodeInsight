#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a, b;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[n - 1 - i] >> b[n - 1 - i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    long long now = 0;
    a[i] += res;
    if (a[i] % b[i] != 0) now = b[i] - (a[i] % b[i]);
    res += now;
  }
  return res;
}