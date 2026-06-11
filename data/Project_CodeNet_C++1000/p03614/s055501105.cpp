#include <iostream>

using namespace std;

int main () {
  int n;
  cin >> n;

  int cur = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    if (x == i) {
      cur++;
    } else {
      ans += (cur + 1) / 2;
      cur = 0;
    }
  }

  ans += (cur + 1) / 2;

  cout << ans << endl;
}
