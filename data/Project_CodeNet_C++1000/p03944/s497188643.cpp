#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<vector<int>> xy(n, vector<int>(2));
  vector<int> a(n);
  vector<vector<int>> field(h, vector<int>(w));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> xy.at(i).at(j);
    }
    cin >> a.at(i);
  }
  
  for (int i = 0; i < n; i++) {
    if (a.at(i) == 1) {
      for (int j = 0; j < h; j++) {
        for (int k = 0; k < xy.at(i).at(0); k++) {
          field.at(j).at(k) = 1;
        }
      }
    }
    if (a.at(i) == 2) {
      for (int j = 0; j < h; j++) {
        for (int k = xy.at(i).at(0); k < w; k++) {
          field.at(j).at(k) = 1;
        }
      }
    }
    if (a.at(i) == 3) {
      for (int j = 0; j < xy.at(i).at(1); j++) {
        for (int k = 0; k < w; k++) {
          field.at(j).at(k) = 1;
        }
      }
    }
    if (a.at(i) == 4) {
      for (int j = xy.at(i).at(1); j < h; j++) {
        for (int k = 0; k < w; k++) {
          field.at(j).at(k) = 1;
        }
      }
    }
  }
  
  int count = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (field.at(i).at(j) == 0) {
        count++;
      }
    }
  }
  
  cout << count << endl;    
}