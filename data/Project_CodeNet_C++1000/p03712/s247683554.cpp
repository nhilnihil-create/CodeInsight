#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> data(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }

  for (int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;

  for (int i = 0; i < H; i++) {
    cout << '#';
    for (int j = 0; j < W; j++) {
      cout << data[i][j];
    }
    cout << '#' << endl;
  }

  for (int i = 0; i < W + 2; i++) {
    cout << '#';
  }
  cout << endl;
}