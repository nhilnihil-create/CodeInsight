#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; 
  int mass[110][110];
  cin >> H >> W;
  
  int N;
  cin >> N;
  
  int a[10100];
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  
  
  vector<pair<int, int>> perm(10100);
  int count = 1;
  for (int i = 0 ; i < H; i++) {
    int x;
    pair<int, int> p;
    if (count % 2) {
      for (int j = 0; j < W; j++) {
        p = make_pair(i, j);
        perm[x] = p;
        x++;
      }
    } else {
      for (int j = W-1; j >= 0; j--) {
        p = make_pair(i, j);
        perm[x] = p;
        x++;  
      }
    }
    count++;
  }
  
  int x = 0;
  for (int i = 1; i <= N; i++) {
    int count = 0;
    
    while (count < a[i]) {
      int h = perm[x].first, w = perm[x].second;
      mass[h][w] = i;
      x++;
      count++;
    }
    
  } 
  // 結果の出力
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << mass[i][j] << " ";
    }
    cout << endl; 
  }
}