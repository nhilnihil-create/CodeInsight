// ABC 062 B- Picture Frame
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); i++)
// 縦横配列をどう考えるか

int main() {
  int H, W;
  cin >> H >> W;

  vector<char> vec1(W + 2, '#'); // 最初に#で横の列を作っておく
  vector<string> vec2(H);

  // 入力
  rep(i, H) {
    cin >> vec2.at(i);
  }
  // #の囲み
  rep(i, W + 2) {
    cout << vec1.at(i);
  }
  cout << endl;
  // #を前後に入れてから出力
  rep(i, H) {
    cout << '#' << vec2.at(i) << '#' << endl;
  }
  // #の囲み
  rep(i, W + 2) {
    cout << vec1.at(i);
  }
  cout << endl;
}