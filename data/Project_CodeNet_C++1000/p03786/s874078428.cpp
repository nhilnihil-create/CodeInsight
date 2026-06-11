#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 1, sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  for (int i = n - 2; i >= 0; --i) {
    sum -= a[i + 1];
    if (sum * 2 < a[i + 1]) break;
    ++res;
  }
  return res;
}
