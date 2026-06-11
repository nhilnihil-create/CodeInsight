#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string s[H];

  for(int i=0; i < H; i++) {
    cin >> s[i];
  }

  for(int i=-1; i < H + 1; i++) {
    for(int j=-1; j < W+1; j++) {
      if(i == -1 || i == H) {
        cout << "#";
      }
      else {
        cout << "#" << s[i] << "#";
        break;
      }
    }
    cout << endl;
  }
}