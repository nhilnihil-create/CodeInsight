#include <bits/stdc++.h>

int main(void)
{
  int W, H, N;
  std::cin >> W >> H >> N;

  bool rect[W][H] = {false};
  for (int i = 0; i < N; i++) {
    int x, y, a;
    std::cin >> x >> y >> a;

    // x--;  y--;

    if (a == 1) {
      for (int w = 0; w < x; w++) {
        for (int h = 0; h < H; h++) {
          rect[w][h] = true;
        }
      }
    }

    if (a == 2) {
      for (int w = x; w < W; w++) {
        for (int h = 0; h < H; h++) {
          rect[w][h] = true;
        }
      }
    }

    if (a == 3) {
      for (int h = 0; h < y; h++) {
        for (int w = 0; w < W; w++) {
          rect[w][h] = true;
        }
      }
    }

    if (a == 4) {
      for (int h = y; h < H; h++) {
        for (int w = 0; w < W; w++) {
          rect[w][h] = true;
        }
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (!rect[i][j]) {
        cnt++;
      }
    }
  }

  std::cout << cnt << std::endl;

  return 0;
}