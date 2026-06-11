#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  for (int i = 0; i < n; i++) {
    long long maxdec = -1LL * (n - 1 - i) * d;
    long long mindec = -1LL * (n - 1 - i) * c;
    long long maxinc = 1LL * i * d;
    long long mininc = 1LL * i * c;
    if (1LL * a + maxinc + mindec >= 1LL * b && 1LL * a + mininc + maxdec <= 1LL * b) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;	
}