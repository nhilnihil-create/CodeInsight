#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string s;

  for(int hi = 0; hi < H; hi++) {
    for(int wi = 0; wi < W; wi++) {
      cin >> s;
      if(s == "snuke") {
        cout << (char)(wi+65) << hi+1 << endl;
        return 0;
      }
    }
  }
}