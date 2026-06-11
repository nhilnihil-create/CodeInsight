#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  string frame_row = "##";
  for (int i = 0; i < W; i++) {
    frame_row += "#";
  }

  cout << frame_row << endl;

  for (int i = 0; i < H; i++) {
    string row;
    cin >> row;
    cout << "#" + row + "#" << endl;
  }

  cout << frame_row << endl;
}