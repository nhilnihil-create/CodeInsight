#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int H, W, D;
string C = "RYGB";

int get_color(int x, int y) {
  x += 1000000;
  y += 1000000;
  x %= 2 * D;
  y %= 2 * D;
  x = x < D;
  y = y < D;
  return (x << 1) | y;
}

int main() {
  cin >> H >> W >> D;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cout << C[get_color(i + j, i - j)];
    }
    cout << endl;
  }
}