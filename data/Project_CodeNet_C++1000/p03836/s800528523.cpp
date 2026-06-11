#include <iostream>
#include <string>

int main() {
  int sx, sy, tx, ty;
  std::string moves = "";
  std::cin >> sx >> sy >> tx >> ty;
  int dx = tx - sx, dy = ty - sy;
  for (int i = 0; i < dx; i++) {
    moves += 'R';
  }
  for (int i = 0; i < dy; i++) {
    moves += 'U';
  }
  for (int i = 0; i < dx; i++) {
    moves += 'L';
  }
  for (int i = 0; i < dy; i++) {
    moves += 'D';
  }
  moves += 'D';
  for (int i = 0; i <= dx; i++) {
    moves += 'R';
  }
  for (int i = 0; i <= dy; i++) {
    moves += 'U';
  }
  moves += "LU";
  for (int i = 0; i <= dx; i++) {
    moves += 'L';
  }
  for (int i = 0; i <= dy; i++) {
    moves += 'D';
  }
  moves += 'R';

  std::cout << moves << "\n";

  return 0;
}