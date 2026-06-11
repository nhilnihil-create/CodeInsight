#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  int N; cin >> N;
  vector<int> A;
  for (int i = 1; i <= N; i++) {
    int cnt; cin >> cnt;
    for (int j = 0; j < cnt; j++) A.push_back(i);
  }
  vector<vector<int>> T(H, vector<int>(W));
  int index = 0;
  for (int i = 0; i < W; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < H; j++) {
        T.at(j).at(i) = A.at(index);
        index++;
      }
    }
    else {
      for (int j = H-1; j >= 0; j--) {
        T.at(j).at(i) = A.at(index);
        index++;
      }
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) cout << T.at(i).at(j) << " ";
    cout << endl;
  }
}