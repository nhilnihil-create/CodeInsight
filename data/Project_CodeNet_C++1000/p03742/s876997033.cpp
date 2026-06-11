#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int64 x, y;
  cin >> x >> y;
  if (abs(x - y) <= 1) {
    cout << "Brown" << endl;
  } else {
    cout << "Alice" << endl;
  }
}