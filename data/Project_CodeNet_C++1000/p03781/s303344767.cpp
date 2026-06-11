#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x;
  cin >> x;
  int t = 0;
  for (int i = 1; i <= x; i++) {
    t += i;
    if (t >= x) {
      cout << i << endl;
      return 0;
    }
  }
}