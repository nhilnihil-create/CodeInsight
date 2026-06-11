#include <bits/stdc++.h>
using namespace std;
int main(){
  int H, W;
  cin >> H >> W;
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  vector<int> s(N + 1, 0);
  for (int i = 0; i < N; i++){
    s[i + 1] = s[i] + a[i];
  }
  int idx = 0;
  vector<int> c(H * W);
  for (int i = 0; i < H * W; i++){
    if (i >= s[idx + 1]){
      idx++;
    }
    c[i] = idx + 1;
  }
  vector<vector<int>> c2(H, vector<int>(W));
  int cnt = 0;
  for (int i = 0; i < H; i++){
    if (i % 2 == 0){
      for (int j = 0; j < W; j++){
        c2[i][j] = c[cnt];
        cnt++;
      }
    } else {
      for (int j = W - 1; j >= 0; j--){
        c2[i][j] = c[cnt];
        cnt++;
      }
    }
  }
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cout << c2[i][j];
      if (j < W - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}