#include<bits/stdc++.h>
using namespace std;
int dis(int a, int b) {
  return max(a - b, b - a);
}
int main () {
  int N, M;
  cin >> N >> M;
  int sx[100];
  int sy[100];
  int cx[100];
  int cy[100];
  for (int i = 0; i < N; i ++) cin >> sx[i] >> sy[i];
  for (int i = 0; i < M; i ++) cin >> cx[i] >> cy[i];
  for (int i = 0; i < N; i ++) {
    int ans = 0;
    int mdi = 1e9 + 5;
    for (int j = M - 1; j >= 0; j --) {
      if (mdi >= (dis(sx[i], cx[j]) + dis(sy[i], cy[j]))) {
        ans = j + 1;
        mdi = dis(sx[i], cx[j]) + dis(sy[i], cy[j]);
      }
    }
    cout << ans << endl;
  }
}
