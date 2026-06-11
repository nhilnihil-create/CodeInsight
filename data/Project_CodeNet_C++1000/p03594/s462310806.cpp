#include <iostream>

int main() {
  unsigned H, W, d;
  std::cin >> H >> W >> d;
  if (d % 2 == 1) {
    for (unsigned i = 0; i < H; ++i) {
      for (unsigned j = 0; j < W; ++j) {
        if ((i + j) % 2) { std::cout << "R"; }
        else { std::cout << "G"; }
      }
      std::cout << std::endl;
    }
  } else {
    std::string s = "RGBY";
    for (unsigned i = 0; i < H; ++i) {
      for (unsigned j = 0; j < W; ++j) {
        unsigned x = ((i + j) / d) % 2;
        unsigned y = ((i - j + W) / d) % 2;
        std::cout << s[x * 2 + y];
      }
      std::cout << std::endl;
    }
  }
  return 0;
}