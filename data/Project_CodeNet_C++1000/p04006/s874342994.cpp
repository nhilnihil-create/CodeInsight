#include <bits/stdc++.h>

using namespace std;

int n;
long long x, a[6969], b[6969], c[6969];

int main() {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
  	cin >> a[i];
  	b[i] = a[i];
  }
  long long ans = LLONG_MAX;
  for (int k = 0; k < n; ++k) {
  	long long cur = k * x;
  	for (int i = 0; i < n; ++i) cur += b[i];
  	ans = min(ans, cur);
  	for (int i = 0; i < n; ++i) c[i] = min(b[i], a[(i - k - 1 + n) % n]);
  	for (int i = 0; i < n; ++i) b[i] = c[i];
  }
  cout << ans << endl;
  return 0;
}

