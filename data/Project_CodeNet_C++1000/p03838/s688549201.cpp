#include <iostream>

using namespace std;

const int INF = 2e9 + 5;

int main () {
  int x, y;
  cin >> x >> y;

  int ans = INF;

  // neither flip
  if (x <= y) {
    ans = min(ans, y - x);
  }

  // initial flip
  if (-x <= y) {
    ans = min(ans, 1 + y - (-x));
  }

  // final flip
  if (x <= -y) {
    ans = min(ans, 1 - y - x);
  }

  // both flips
  if (-x <= -y) {
    ans = min(ans, 2 - y - (-x));
  }

  cout << ans << endl;
}
