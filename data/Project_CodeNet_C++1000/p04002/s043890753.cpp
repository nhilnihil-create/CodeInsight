#include <iostream>
#include <utility>
#include <vector>
#include <set>
#define int long long
using namespace std;

signed main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; ++i) cin >> a[i] >> b[i];
  
  vector<int> ans(10, 0);
  ans[0] = (H - 2) * (W - 2);
  set<pair<int, int>> S;
  vector<int> dx = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
  vector<int> dy = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 9; ++j) {
      int x = a[i] + dx[j];
      int y = b[i] + dy[j];
      if (!(1 < x && x < H && 1 < y && y < W)) continue;
      int cnt = 0;
      for (int k = 0; k < 9; ++k) {
        if (S.count(make_pair(x + dx[k], y + dy[k]))) ++cnt;
      }
      --ans[cnt];
      ++ans[cnt + 1];
    }
    S.insert(make_pair(a[i], b[i]));
  }
  
  for (int i = 0; i < 10; ++i) cout << ans[i] << endl;
  return 0;
}