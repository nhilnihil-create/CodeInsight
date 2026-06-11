#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> S(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> S.at(i).at(j);
    }
  }
  vector<char> V(W + 2, '#');
  for (auto v : V) cout << v;
  cout << "\n";
  for (int i = 0; i < H; i++) {
    cout << "#";
    for (auto s : S.at(i)) cout << s;
    cout << "#";
    cout << "\n";
  }
  for (auto v : V) cout << v;
  cout << "\n";
}