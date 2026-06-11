#include <iostream>

int main() {
  int h, w;
  char c[100][100];
  std::cin >> h >> w;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cin >> c[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cout << c[i][j];
    }
    std::cout << "\n";
    for (int j = 0; j < w; j++) {
      std::cout << c[i][j];
    }
    std::cout << "\n";
  }

  return 0;
}