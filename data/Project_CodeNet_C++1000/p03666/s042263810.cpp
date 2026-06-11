#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c, d;

bool solve();

int main() {
  cin >> n >> a >> b >> c >> d;
  if (a > b) swap(a, b);
  if (solve())
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

bool solve() {
  b -= a;
  --n;
  for (int i = 0; i <= n; ++i) {
    long long now = c * (2 * i - n);
    if (now - (d - c) * (n - i) <= b && b <= now + (d - c) * i) return 1;
  }
  return 0;
}