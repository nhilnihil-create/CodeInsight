#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  int ans = 0;
  if (x == 0) {
    if (0 < y) {
      ans = abs(y);
    } else {
      ans = abs(y) + 1;
    }
  } else if (y == 0) {
    if (0 < x) {
      ans = abs(x) + 1;
    } else {
      ans = abs(x);
    }
  } else if (0 < x && 0 < y) {
    if (x <= y) {
      ans = y - x;
    } else {
      ans = x - y + 2;
    }
  } else if (x < 0 && 0 < y) {
    ans = abs(x + y) + 1;
  } else if (y < 0 && 0 < x) {
    ans = abs(x + y) + 1;
  } else { // x < 0 && y < 0
    if (x <= y) {
      ans = y - x;
    } else {
      ans = x - y + 2;
    }
  }

  cout << ans << endl;
  return 0;
}
