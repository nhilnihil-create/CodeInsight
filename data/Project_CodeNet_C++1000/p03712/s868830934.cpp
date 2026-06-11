#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  char P[H+2][W+2];
  for (int i=0; i<H+2; i++) {
    for (int j=0; j<W+2; j++) {
      if (i == 0 || j == 0 || i == H+1 || j == W+1) {
        P[i][j] = '#';
      } else {
        cin >> P[i][j];
      }
    }
  }
  
  for (int i=0; i<H+2; i++) {
    for (int j=0; j<W+2; j++) {
      cout << P[i][j];
    }
    cout << endl;
  }
}
