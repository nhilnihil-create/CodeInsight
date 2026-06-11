#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int h,w;
  cin >> h >> w;
  
  vector<vector<char>> c(h,vector<char>(w));
  for ( int i = 0; i < h; i++){
    for ( int j = 0; j < w; j++){
      cin >> c[i][j];
    }
  }
  
  for ( int i = 0; i < h; i++){
    int k = 0;
    while(k < 2){
      for ( int j = 0; j < w; j++){
        cout << c[i][j];
      }
      cout << endl;
      k++;
    }
  }
  return 0;
}