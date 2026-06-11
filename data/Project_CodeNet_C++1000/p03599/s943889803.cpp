#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  vector<int> X, Y;
  for (int i = 0; i < 30 + 1; i++) {
    for (int j = 0; j < 30 + 1; j++) {
      if (i == 0 && j == 0) continue;
      X.emplace_back(100 * A * i + 100 * B * j);
    }
  }
  for (int i = 0; i < 100 + 1; i++) {
    for (int j = 0; j < 100 + 1; j++) {
      Y.emplace_back(C * i + D * j);
    }
  }
  int a = -1, b = 0;
  for (int x : X) {
    for (int y : Y) {
      if (x + y <= F && y <= x * E / 100) {
        if ((double)y / (x + y) > (double)a / b) {
          a = y, b = x + y;
        }
      }
    }
  }
  cout << b << ' ' << a << '\n';
  return 0;
}
