#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> a(N);
  vector<vector<int>> ans(H, vector<int>(W));
  for (int i = 0; i < N; i++) cin >> a[i];
  int k = 0;
  for (int i = 0; i < H; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < W; j++) {
        a[k]--;
        ans[i][j] = k + 1;
        if (a[k] == 0) {
          k++;
        }
      }
    } else {
      for (int j = W - 1; j >= 0; j--) {
        a[k]--;
        ans[i][j] = k + 1;
        if (a[k] == 0) {
          k++;
        }
      }
    }
  }
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}