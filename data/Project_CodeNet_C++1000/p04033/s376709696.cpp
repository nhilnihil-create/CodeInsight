#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;
  int sign = +1;
  if (a < 0) {
    if (b < 0) {
      if ((b - a + 1) % 2 != 0) {
        sign = -1;
      }
    }
    else {
      sign = 0;
    }
  }
  if (sign > 0) {
    cout << "Positive" << endl;
  }
  else if (sign < 0) {
    cout << "Negative" << endl;
  }
  else {
    cout << "Zero" << endl;
  }
  return 0;
}
