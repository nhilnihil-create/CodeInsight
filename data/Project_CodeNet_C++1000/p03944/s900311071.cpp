#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x(n), y(n), a(n);
  for (int i = 0; i < n; ++i) {
    cin >> x.at(i) >> y.at(i) >> a.at(i);
  }

  vector<vector<bool>> area(w, vector<bool>(h, true));
  for (int i = 0; i < n; ++i) {
    switch (a.at(i)) {
      case 1:
        for (int j = 0; j < x.at(i); j++) {
          for (int k = 0; k < h; k++) {
            area.at(j).at(k) = false;
          }
        }
        break;
      case 2:
        for (int j = x.at(i); j < w; j++) {
          for (int k = 0; k < h; k++) {
            area.at(j).at(k) = false;
          }
        }
        break;
      case 3:
        for (int j = 0; j < w; j++) {
          for (int k = 0; k < y.at(i); k++) {
            area.at(j).at(k) = false;
          }
        }
        break;
      case 4:
        for (int j = 0; j < w; j++) {
          for (int k = y.at(i); k < h; k++) {
            area.at(j).at(k) = false;
          }
        }
        break;
    }
  }

  int count = 0;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      if (area.at(i).at(j) == true) count++;
    }
  }
  cout << count << endl;
}