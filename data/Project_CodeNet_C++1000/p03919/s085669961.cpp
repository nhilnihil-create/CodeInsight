#include <bits/stdc++.h>
using namespace std;

signed main() {
  int h, w; cin >> h >> w;
  int row = 0, col = 0;
  string s;
  bool flag = false;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> s;
      if(s == "snuke") {
        row = i, col = j;
        flag = true;
        break;
      }
    }
    if(flag) break;
  }
  cout << (char)(col+'A') << row+1 << '\n';
  return 0;
}