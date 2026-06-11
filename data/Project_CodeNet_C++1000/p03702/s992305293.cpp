#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  int64 a, b;
  cin >> n >> a >> b;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  int64 l = 0;
  int64 u = 1E9;
  auto fn = [&](int64 k) -> bool {
    int64 c = 0;
    for(int64 x : xs) {
      if (x > b * k) {
        c += (x - b * k + (a - b - 1)) / (a - b);
      }
    }
    return c <= k;
  };
  while (u - l >= 2) {
    int64 m = (u + l) / 2;
    if (fn(m)) {
      u = m;
    } else {
      l = m;
    }
  }
  cout << u << endl;
}