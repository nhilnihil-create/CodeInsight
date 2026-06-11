#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int i = 0; i < H; ++i) {
    cin >> C.at(i);
  }

  for (int i = 1; i <= H * 2; ++i) {
    cout << C.at(((i + 1) / 2) - 1) << endl;
  }

  return 0;
}
