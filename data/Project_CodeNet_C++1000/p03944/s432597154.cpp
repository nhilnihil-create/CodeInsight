#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("../data.txt");

int w, h, n, x, y, a, x1, x2, y1, y2;

int main() {

  cin >> w >> h >> n;
  x1 = y1 = 0, x2 = w, y2 = h;
  while (n--) {
    cin >> x >> y >> a;
    switch (a) {
      case 1:
        x1 = max(x, x1);
        break;
      case 2:
        x2 = min(x, x2);
        break;
      case 3:
        y1 = max(y, y1);
        break;
      case 4:
        y2 = min(y, y2);
        break;
      default: break;
    }
  }
  if (x2 - x1 <= 0 || y2 - y1 <= 0) cout << 0;
  else cout << (x2 - x1) * (y2 - y1);
  return 0;
}
