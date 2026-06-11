#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> S(H);
  
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << S[i][j];
    }
    cout << endl;
    
    for (int j = 0; j < W; j++) {
      cout << S[i][j];
    }
    cout << endl;
  }
}

