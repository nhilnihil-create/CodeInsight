#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  long long ba = b - a;
  long long dc = d - c;
  for (long long x = 0; x <= n - 1; x++) {
    long long y = n - 1 - x;
    long long l = -d * x + c * y;
    if (l <= ba && ba <= l + (n - 1) * dc) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}