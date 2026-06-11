#include <iostream>

using namespace std;

int main() {
  int w, a, b;
  cin >> w >> a >> b;
  if (a < b) {
    int x = b - (w + a);
    if (x < 0) {
      x = 0;
    }
    cout << x << endl;
  } else {
    int x = a - (w + b);
    if (x < 0) {
      x = 0;
    }
    cout << x << endl;
  }
  return 0;
}
