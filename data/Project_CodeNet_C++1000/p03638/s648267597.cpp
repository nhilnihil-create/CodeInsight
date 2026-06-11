#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<vector<int>> C(H, vector<int>(W));
  auto fill = [&](int i, int color) {
    int h = i / W;
    int w;
    if (h % 2 == 0) {
      w = i % W;
    } else {
      w = W - 1 - i % W;
    }
    C[h][w] = color;
  };
  int idx = 0;
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      fill(idx, i);
      idx++;
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j > 0) cout << " ";
      cout << C[i][j];
    }
    cout << endl;
  }

  return 0;
}
/* vim:set fdm=marker: */
