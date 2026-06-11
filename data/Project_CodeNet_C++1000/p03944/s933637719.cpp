#include <bits/stdc++.h>
using namespace std;

bool is_black_out(int x, int y, int xi, int yi, int a) {
  switch (a) {
    case 1:
      return x < xi;
    case 2:
      return x >= xi;
    case 3:
      return y < yi;
    case 4:
      return y >= yi;
    default:
      return false;
  }
}

int main() {
  int W, H, N;
  cin >> W >> H >> N;

  bool xy_plane[W][H];
  for (int x = 0; x < W; x++) {
    for (int y = 0; y < H; y++) {
      xy_plane[x][y] = false;
    }
  }

  for (int i = 0; i < N; i++) {
    int xi, yi, a;
    cin >> xi >> yi >> a;

    for (int x = 0; x < W; x++) {
      for (int y = 0; y < H; y++) {
        xy_plane[x][y] = xy_plane[x][y] || is_black_out(x, y, xi, yi, a);
      }
    }
  }

  int counter = 0;
  for (int x = 0; x < W; x++) {
    for (int y = 0; y < H; y++) {
      if (!xy_plane[x][y]) counter++;
    }
  }

  cout << counter << endl;
}