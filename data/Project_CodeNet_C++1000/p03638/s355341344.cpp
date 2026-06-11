#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<vector<int>> ans(H, vector<int>(W));
  int h = 0, w = 0, check = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < a; j++) {
      ans.at(h).at(w) = i + 1;
      if (w == W - 1 && check == 0 || w == 0 && h != 0 && check == 0 || W == 1) {
        h++;
        check = 1;
      }
      else if (h%2 == 0) {
        w++;
        check = 0;
      }
      else {
        w--;
        check = 0;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << ans.at(i).at(j) << " ";
    }
    cout << endl;
  }
}