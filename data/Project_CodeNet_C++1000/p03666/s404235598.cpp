#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int64 a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  int64 t = b - a;
  bool valid = false;
  for (int i = 0; i <= n - 1; i++) {
    int64 l = i * c + (n - 1 - i) * (-d);
    int64 u = i * d + (n - 1 - i) * (-c);
    if (l <= t && t <= u) {
      // cout << "i:" << i << endl;
      valid = true;
      break;
    }
  }
  if (valid) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}