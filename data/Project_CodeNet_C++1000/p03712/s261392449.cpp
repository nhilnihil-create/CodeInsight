#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector S(H + 2, vector(W + 2, '#'));
  for (int i = 1; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) cin >> S.at(i).at(j);
  }
  for (auto s : S) {
    for (auto c : s) cout << c;
    cout << "\n";
  }
}