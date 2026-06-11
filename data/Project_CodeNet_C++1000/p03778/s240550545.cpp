#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int w, a, b;
  cin >> w >> a >> b;
  if (a < b) {
    if (b < a + w) cout << 0 << '\n';
    else cout << b - a - w << '\n';
  } else if (a > b) {
    if (a < b + w) cout << 0 << '\n';
    else cout << a - b - w << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}
