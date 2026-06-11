#include <bits/stdc++.h>
using namespace std;

int h, w, r, c;
vector<vector<int>> res;

bool solve();

int main() {
  cin >> h >> w >> r >> c;
  if(solve()) {
    cout << "Yes" << endl;
    for(int i = 0; i < h; ++i) {
      for(int j = 0; j < w; ++j) {
        if(j != 0) cout << " ";
        cout << res[i][j];
      }
      cout << endl;
    }
  }
  else
    cout << "No" << endl;
  return 0;
}

bool solve() {
  res.assign(h, vector<int>(w, 0));
  if(w % c != 0) {
    for(int i = 0; i < h; ++i)
      for(int j = 0; j < w; j += c) {
        res[i][j] = 1000;
        if(j + c <= w) res[i][j + c - 1] = -1001;
      }
    return 1;
  }
  if(h % r != 0) {
    for(int j = 0; j < w; ++j)
      for(int i = 0; i < h; i += r) {
        res[i][j] = 1000;
        if(i + r <= h) res[i + r - 1][j] = -1001;
      }
    return 1;
  }
  return 0;
}
