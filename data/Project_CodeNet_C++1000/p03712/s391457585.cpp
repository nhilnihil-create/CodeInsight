#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W));
  for (int i = 0; i < H;i++){
    for (int j = 0; j < W;j++){
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < W + 2;i++){
    cout << "#";
  }
  cout << endl;
  for (int i = 0; i < H;i++){
    for (int j = 0; j < W + 2;j++){
      if(j==0 ||j==W+1){
        cout << "#";
      } else {
        cout << s[i][j - 1];
      }
    }
    cout << endl;
  }
  for (int i = 0; i < W + 2; i++) {
    cout << "#";
  }
  cout << endl;
}
