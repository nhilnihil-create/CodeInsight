#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int W, H, N; cin >> W >> H >> N;
  
  bool table[H][W]; int ans = 0;
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      table[i][j] = true;
    }
  }
  
  for (int i = 0; i < N; i++) {
    
    int x, y, a; cin >> x >> y >> a;
    
    for (int j = 0; j < H; j++) {
      for (int k = 0; k < W; k++) {
        if (a == 1 && k < x) table[j][k] = false;
        if (a == 2 && x <= k) table[j][k] = false;
        if (a == 3 && j < y) table[j][k] = false;
        if (a == 4 && y <= j) table[j][k] = false;
      }
    }
    
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (table[i][j]) ans++;
    }
  }
  
  cout << ans << endl;
  
}