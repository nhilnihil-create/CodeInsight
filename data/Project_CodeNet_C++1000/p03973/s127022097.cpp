#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for (auto& p : a) cin >> p;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0, now = 1;
  for (int i = 0; i < n; ++i) {
    long long x = (a[i] - 1) / now;
    res += x;
    if (x) a[i] = 1;
    now = max(now, a[i] + 1);
  }
  return res;
}