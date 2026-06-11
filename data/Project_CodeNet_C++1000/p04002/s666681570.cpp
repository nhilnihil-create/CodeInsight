#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#define int long long
typedef pair<int, int> P;
map<P, int> M;

signed main() {
  int H, W, N; cin >> H >> W >> N;
  P a[100000];
  for(int i = 0; i < N; ++i) {
    cin >> a[i].first >> a[i].second;
    a[i].first--, a[i].second--;
  }
  sort(a, a + N);
  int sum[10] = {(H-2) * (W-2), 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for(int i = 0; i < N; ++i) {
    for(int j = -2; j <= 0; ++j) {
      for(int k = -2; k <= 0; ++k) {
        int X = a[i].first + j, Y = a[i].second + k;
        if(X < 0 || Y < 0 || X + 2 >= H || Y + 2 >= W) continue;
        if(M[P(X, Y)] == 1) continue;
        int cnt = 0;
        for(int l = 0; l <= 2; l++) {
          for(int m = 0; m <= 2; ++m) {
            int cx = X + l, cy = Y + m;
            int D = lower_bound(a, a + N, P(cx, cy)) - a;
            if(a[D] == P(cx, cy)) cnt++;
          }
        }
        if(cnt >= 1) {
          sum[0]--;
          sum[cnt]++;
          M[P(X, Y)] = 1;
        }
      }
    }
  }
  for(int i = 0; i <= 9; ++i) cout << sum[i] << endl;
  return 0;
}

