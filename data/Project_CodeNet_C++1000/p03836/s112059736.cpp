#include <iostream>

using namespace std;

int main() {
  int sx, sy, tx, ty, dx, dy;
  cin >> sx >> sy >> tx >> ty;
  dx = tx - sx;
  dy = ty - sy;
  cout << string(dx,'R') + string(dy,'U')
      + string(dx,'L') + string(dy,'D')
      + "D" + string(dx+1,'R') + string(dy+1,'U') + "L"
      + "U" + string(dx+1,'L') + string(dy+1,'D') + "R\n";
}
