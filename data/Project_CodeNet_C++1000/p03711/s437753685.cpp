#include <iostream>

using namespace std;

int main() {
  int x, y;
  int g2[] = {4, 6, 9, 11};
  cin >> x >> y;
  if (x == 2 || y == 2) {
    cout << "No" << endl;
  } else {
    bool xok = false;
    bool yok = false;
    for (int i = 0; i < 4; i++) {
      if (x == g2[i]) {
        xok = true;
      }
      if (y == g2[i]) {
        yok = true;
      }
    }
    if (xok == yok) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
