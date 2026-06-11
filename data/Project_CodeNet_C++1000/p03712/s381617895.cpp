#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool contains(const vector<T>& vec, const T& item) {
  return std::find(vec.begin(), vec.end(), item) != vec.end();
}

int main() {
  int H, W;
  cin >> H >> W;

  char area[H][W];

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> area[i][j];
    }
  }

  for (int i = 0; i < W + 2; i++) cout << '#';
  cout << endl;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (j == 0) cout << '#';
      cout << area[i][j];
      if (j == W - 1) cout << '#';
    }
    cout << endl;
  }

  for (int i = 0; i < W + 2; i++) cout << '#';
  cout << endl;
}
