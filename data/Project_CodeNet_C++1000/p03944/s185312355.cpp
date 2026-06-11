#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int w, h, n;
  cin >> w >> h >> n;

  int grid[w][h];
  memset(grid, 0, sizeof(grid));

  for (int i = 0; i < n; ++i) {
    int x, y, a;
    cin >> x >> y >> a;

    if (a == 1) {
      for (int i = 0; i < x; ++i) 
        for (int j = 0; j < h; ++j) grid[i][j] = 1;
    } else if (a == 2) {
      for (int i = x; i < w; ++i) {
        for (int j = 0; j < h; ++j) grid[i][j] = 1;
      }
    } else if (a == 3) {
      for (int j = 0; j < y; ++j)
        for (int i = 0; i < w; ++i) grid[i][j] = 1;
    } else {
      for (int j = y; j < h; ++j)
        for (int i = 0; i < w; ++i) grid[i][j] = 1;
    }
  }

  int count = 0;
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) if (!grid[i][j]) count++;
  }

  cout << count << "\n";
}
	