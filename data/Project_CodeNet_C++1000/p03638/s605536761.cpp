#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int H,W,N;
  cin >> H >> W >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int ans[H][W];
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < a[i]; j++) {
      int c = (cnt + j) / W;
      int d = (cnt + j) % W;   
      if (c % 2 == 1) {
        ans[c][(W-1-d)] = i+1;
      } else {
        ans[c][d] = i+1;
      }
    }
    cnt += a[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}