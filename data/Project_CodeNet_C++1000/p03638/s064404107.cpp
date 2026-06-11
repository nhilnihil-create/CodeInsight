#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> a;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    for (int j = 0; j < tmp; j++) {
      a.push_back(i + 1);
    }
  }

  vector<vector<int>> ans(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int index = (i % 2 == 0 ? j : W - 1 - j);
      ans[i][index] = a[i * W + j];
    }
  }

  for (int i = 0; i < H; i++) {
    cout << ans[i][0];
    for (int j = 1; j < W; j++) {
      cout << " " << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}