#include <iostream>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  if (b < 0) {
    if (abs(b-a) % 2 == 1) {
      cout << "Positive" << endl;
    } else {
      cout << "Negative" << endl;
    }

  } else if (0 < a) {
    cout << "Positive" << endl;
  } else {
    cout << "Zero" << endl;
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
