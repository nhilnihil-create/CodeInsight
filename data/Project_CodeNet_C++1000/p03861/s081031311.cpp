#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t a, b, x;

  cin >> a >> b >> x;

  if (a > 0) {
    cout << (b / x) - ((a - 1) / x);
  } else {
    cout << (b / x) + 1;
  }

  return 0;
}
