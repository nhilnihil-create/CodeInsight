#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, k, sum;
  cin >> n >> k;
  sum = 0;

  // ここにプログラムを追記
  rep (i, n) {
    int x, y;
    cin >> x;
    y = x - k;
    if (y < 0) {
      y = -y;
    }
    if (x < y) {
      sum += x * 2;
    }
    else {
      sum += y * 2;
    }
  }
  cout << sum << endl;
}
