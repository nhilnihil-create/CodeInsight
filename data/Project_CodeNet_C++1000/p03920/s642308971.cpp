#include <bits/stdc++.h>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

int main() {
  int n, s = 0;
  cin >> n;
  for (int i = 0; ; ++i) {
    s += i;
    if (s < n) continue;
    for (int j = 1; j <= i; ++j) {
      if (s - n == j) continue;
      cout << j << endl;
    }
    return 0;
  }
}

