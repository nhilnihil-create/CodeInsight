#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = a + b, y = b + c, z = c + a;
  if (x <= y && x <= z) {
    cout << x << endl;
  } else if (y <= z && y <= x) {
    cout << y << endl;
  } else {
    cout << z << endl;
  }
  return 0;
}
