#include <iostream>

using namespace std;

int main() {
  long a, b, x;
  cin >> a >> b >> x;
  long da = a / x;
  long db = b / x;
  long ans = db - da;
  if (a % x == 0) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
