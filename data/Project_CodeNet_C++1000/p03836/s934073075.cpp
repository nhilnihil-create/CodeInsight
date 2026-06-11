#include <bits/stdc++.h>
using namespace std;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  int dx = tx - sx;
  int dy = ty - sy;

  // 1回目 行き
  cout << string(dy, 'U');
  cout << string(dx, 'R');

  // 1回目 帰り
  cout << string(dy, 'D');
  cout << string(dx, 'L');

  // 2回目 行き 左から抜けて上から到達する
  cout << "L";
  cout << string(dy + 1, 'U');
  cout << string(dx + 1, 'R');
  cout << "D";

  // 2回目 帰り 右から抜けて下から到達する
  cout << "R";
  cout << string(dy + 1, 'D');
  cout << string(dx + 1, 'L');
  cout << "U" << endl;
}