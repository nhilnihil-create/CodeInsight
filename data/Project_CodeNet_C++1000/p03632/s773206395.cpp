#include <iostream>

using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (c < a) {
    int x = a;
    a = c;
    c = x;
    int y = b;
    b = d;
    d = y;
  }
  if (c > b) {
    cout << 0 << endl;
  } else {
    if (b < d) {
      cout << b - c << endl;
    } else {
      cout << d - c << endl;
    }
  }
  return 0;
}
