#include <bits/stdc++.h>
using namespace std;
#define mayu return 0;
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> table(2*H, vector<char>(W));
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> table[2*i][j];
    }
    table[2*i + 1] = table[2*i];
  }
  for(int i = 0; i < 2*H; i++) {
    for(int j = 0; j < W; j++) {
      cout << table[i][j];
    }
    cout << endl;
  }
  mayu;
}