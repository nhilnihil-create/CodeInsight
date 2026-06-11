#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int t = 0; t < 32; ++t) {
    if ((a & 1) || (b & 1) || (c & 1)) {
      cout << t << "\n";
      return 0;
    }
    int A = a / 2, B = b / 2, C = c / 2;
    a = B + C, b = A + C, c = A + B;
  }
  cout << -1 << "\n";
  return 0;
  return 0;
}