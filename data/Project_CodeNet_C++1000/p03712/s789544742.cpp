#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<char> A;
  for (int cnt_h=0; cnt_h < H; ++cnt_h) {
    for (int cnt_w=0; cnt_w < W; ++cnt_w) {
      char tmp;
      cin >> tmp;
      A.push_back(tmp);
    }
  }

  for (int cnt_h=-1; cnt_h < H+1; ++cnt_h) {
    for (int cnt_w=-1; cnt_w < W+1; ++cnt_w) {
      if ( (0<=cnt_h) && (cnt_h<H) && (0<=cnt_w) && (cnt_w<W)) {
        cout << A.at(cnt_h * W + cnt_w);
      } else {
        cout << '#';
      }
    }
    cout << endl;
  }

  return 0;
}