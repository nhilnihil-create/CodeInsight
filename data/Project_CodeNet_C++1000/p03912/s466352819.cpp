#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
int in[101010], cnt[101010], pairs[101010], alone[1010110];
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> in[i];
    cnt[in[i] % m]++;
    if (alone[in[i]]) {
      pairs[in[i] % m]++;
    }
    alone[in[i]] ^= 1;
  }
  int ans = 0;
  for (int x = 0; x < m; x++) {
    int y = (m - x) % m;
    if (x < y) continue;
    if (x == y) {
      ans += cnt[x] / 2;
    } else {
      int u = x, v = y;
      if (cnt[u] < cnt[v]) {
        swap(u, v);
      }
      int over = cnt[u] - cnt[v];
      if (pairs[u] * 2 >= over) {
        ans += (cnt[u] + cnt[v]) / 2;
      } else {
        ans += pairs[u] + cnt[v];
      }
    }
  }
  cout << ans << endl;
  return 0;
}