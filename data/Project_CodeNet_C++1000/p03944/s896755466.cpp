#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  vector<int> x(N);
  vector<int> y(N);
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i) >> y.at(i) >> a.at(i);
  }
  
  vector<vector<int>> rect(H, vector<int>(W, 1));
  for (int i = 0; i < N; i++) {
    if (a.at(i) == 1) {
      for (int j = 0; j < H; j++) {
        for (int k = 0; k < x.at(i); k++) {
          rect.at(j).at(k) = 0;
        }
      }
    } else if (a.at(i) == 2) {
      for (int j = 0; j < H; j++) {
        for (int k = x.at(i); k < W; k++) {
          rect.at(j).at(k) = 0;
        }
      }
    } else if (a.at(i) == 3) {
      for (int j = 0; j < y.at(i); j++) {
        for (int k = 0; k < W; k++) {
          rect.at(j).at(k) = 0;
        }
      }
    } else if (a.at(i) == 4) {
      for (int j = y.at(i); j < H; j++) {
        for (int k = 0; k < W; k++) {
          rect.at(j).at(k) = 0;
        }
      }
    }
  }
  int area = 0;
  for (int j = 0; j < H; j++) {
    for (int k = 0; k < W; k++) {
      area += rect.at(j).at(k);
    }
  }
    
  cout << area << endl;
}
