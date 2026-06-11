#include <bits/stdc++.h>
using namespace std;

int main () {
  int H, W;
  cin >> H;
  cin >> W;
  
  char a[H][W];
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  
  for (int s = 0; s < H + 2; s++) {
    if (s == 0 || s == H + 1) {
      for (int t = 0; t < W + 2; t++) {
        cout << '#';
      }
    } else {
      for (int t = 0; t < W + 2; t++) {
        if (t == 0 || t == W + 1){ 
          cout << '#';
        } else {
          cout << a[s - 1][t - 1];
        }
      }
    }
    cout << endl;
  }
}
