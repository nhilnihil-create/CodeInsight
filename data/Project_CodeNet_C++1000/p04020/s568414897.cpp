#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;

int main() {
  cin >> n;
  a.resize(n);
  for (auto &p : a) cin >> p;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (i != 0 && a[i] && a[i - 1]) {
      --a[i - 1];
      --a[i];
      ++res;
    }
    res += a[i] / 2;
    a[i] %= 2;
  }
  cout << res << endl;
  return 0;
}
