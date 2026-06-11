#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int64 Solve(int64 a, int64 b) {
  if (a % b == 0) {
    int64 k = a / b;
    return (2 * k - 1) * b;
  }
  int64 r = a % b;
  int64 k = a / b;
  return 2 * k * b + Solve(b, r);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int64 n, x;
  cin >> n >> x;
  if (2 * x < n) {
    cout << n + Solve(n - x, x) << endl;
  } else {
    cout << n + Solve(x, n - x) << endl;
  }
}