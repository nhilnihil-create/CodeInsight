#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> data(H);
  
  // 標準入力から読み込んで出力
  for (int i = 0; i < H; i++) {
    // 一行目 ##### を出力
    if (i == 0) {
      for (int j = 0; j < W+2; j++) cout << "#";
      cout << endl;
    }
    // データ出力
    cin >> data.at(i);
    cout  << "#" << data.at(i) << "#" << endl;

    // 最終行 ##### を出力
    if (i == H-1) {
      for (int j = 0; j < W+2; j++) cout << "#";
      cout << endl;
    }
  }
  return 0;
}