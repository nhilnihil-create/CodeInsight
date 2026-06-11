#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  int N = 900000000 / (h * w);
  vector<vector<int>> a(H, vector<int>(W, 1 + N));
  for (int i = h - 1; i < H; i += h){
    for (int j = w - 1; j < W; j += w){
      a[i][j] = -(h * w) - N * (h * w - 1);
    }
  }
  long long sum = 0;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      sum += a[i][j];
    }
  }
  if (sum <= 0){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    for (int i = 0; i < H; i++){
      for (int j = 0; j < W; j++){
        cout << a[i][j];
        if (j < W - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}