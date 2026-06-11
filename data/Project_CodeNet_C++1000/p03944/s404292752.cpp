#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  int whiteArea = 0;
  vector<vector<int>> v(h, vector<int>(w, 1));
  for (int i = 0; i < n; i++) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {// <xi
      for (int j = 0; j < h; j++) {
        for (int k = 0; k < x; k++) v.at(j).at(k) = 0;
       }
    }else if (a == 2) {// >xi
      for (int j = 0; j < h; j++) {
        for (int k = x; k < w; k++) v.at(j).at(k) = 0;
      }
    }else if (a == 3) {// <yi
      for (int j = 0; j < y; j++) v[j] = vector<int>(w, 0);
    }else {// >yi
      for (int j = y; j < h; j++) v[j] = vector<int>(w, 0);
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v.at(i).at(j) == 1) whiteArea++;
    }
  }
  cout << whiteArea;
}