#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  
  vector<vector<char>> data(H, vector<char>(W));
 
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
      if (j == W - 1){
        for (int k = 0; k < W; k++) {
          if (k != W - 1){
            cout << data.at(i).at(k);
          }
          else {
            cout << data.at(i).at(k) << endl;
          }
        }
        for (int k = 0; k < W; k++) {
          if (k != W - 1){
            cout << data.at(i).at(k);
          }
          else {
            cout << data.at(i).at(k) << endl;
          }
        }
      }
    }
  }
}
        
 