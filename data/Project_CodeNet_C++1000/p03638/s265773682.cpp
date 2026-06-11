#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, N, A;
  cin >> H >> W >> N;
  vector<int> V;
  int now = 1;
  while (cin >> A) {
    while (A--) V.push_back(now);
    now++;
  }
  int v = 0;
  vector<vector<int>> ans(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans.at(i).at(j) = V.at(v), v++;
    }
  }
  for (int i = 0; i < H; i++) {
    if (i % 2) reverse(ans.at(i).begin(), ans.at(i).end());
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j != 0) cout << " ";
      cout << ans.at(i).at(j);
    }
    cout << "\n";
  }
}