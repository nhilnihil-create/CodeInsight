#include <bits/stdc++.h>
using namespace std;

int H, W, HS, WS;
#define BIG 4000

int main() {
  cin >> H >> W >> HS >> WS;
  if(H % HS == 0 && W % WS == 0) cout << "No" << endl;
  else {
    cout << "Yes" << endl;
    for(int i = 0; i < H; ++i) {
      for(int j = 0; j < W; ++j) {
        cout << (j == 0 ? "" : " ")
          << (i % HS == HS - 1 && j % WS == WS - 1 ? BIG - 1 - BIG * HS * WS : BIG);
      }
      cout << endl;
    }
  }
  return 0;
}
