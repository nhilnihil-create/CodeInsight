#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int h, w;
  cin >> h >> w;

  char grid [h][w];
  char result [2 * h][w];

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < 2 * h; ++i) {
    for (int j = 0; j < w; ++j) {
      result[i][j] = grid[i / 2][j];
    }
  }

  for (int i = 0; i < 2 * h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << result[i][j];
    }
    cout << endl;
  }
}
