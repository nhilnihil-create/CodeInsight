#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long x;
  cin >> x;

  long long r = x % 11;
  long long ans = x / 11 * 2;

  if (r == 0) {
    cout << ans << endl;
  } else if (r <= 6) {
    cout << ans + 1 << endl;
  } else {
    cout << ans + 2 << endl;
  }
  return 0;
}