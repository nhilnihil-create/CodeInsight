#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> V;
  for (int i = 1; i <= N; i++) {
    int A;
    cin >> A;
    for (int j = 0; j < A; j++) V.push_back(i);
  }
  vector<vector<int>> R(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      R.at(i).at(j) = V.at(W * i + j);
    }
  }
  for (int i = 0; i < H; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < W; j++) cout << R.at(i).at(j) << " ";
    }
    else {
      for (int j = W - 1; j >= 0; j--) cout << R.at(i).at(j) << " ";
    }
    cout << endl;
  }
}