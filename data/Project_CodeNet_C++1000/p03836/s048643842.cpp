#include <bits/stdc++.h>
using namespace std;

void move(int x1, int y1, int x2, int y2) {
  if (y2 - y1 > 0 ) {
    for (int i = 0; i < y2 - y1; i++)
      cout << "U";
  }
  else {
    for (int i = 0; i < y1 - y2; i++)
      cout << "D";
  }
  if (x2 - x1 > 0) {
    for (int i = 0; i < x2 - x1; i++)
      cout << "R";
  }
  else {
    for (int i = 0; i < x1 - x2; i++)
      cout << "L";
  }
}

void move2(int x1, int y1, int x2, int y2) {
  if (x1 < x2) {
    cout << "L";
    x1--;
  }
  else {
    cout << "R";
    x1++;
  }
  if (y1 < y2) {
    y2++;
    move(x1, y1, x2, y2);
    cout << "D";
  }
  else {
    y2--;
    move(x1, y1, x2, y2);
    cout << "U";
  }
}

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  move(sx, sy, tx, ty);
  move(tx, ty, sx, sy);
  move2(sx, sy, tx, ty);
  move2(tx, ty, sx, sy);
  cout << endl;
}