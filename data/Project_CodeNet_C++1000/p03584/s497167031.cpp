#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  queue<int> que;
  int l = k;
  for (int i = 0; i < 30; i++) {
    if (l&1) {
      que.push(i);
    }
    l /= 2;
  }
  vector<pair<int, int>> nbs(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    nbs[i] = {a, b};
  }
  long long ans;
  long long scr = 0;
  for (int i = 0; i < n; i++) {
    int a = nbs[i].first;
    int b = nbs[i].second;
    if (!(a & ~k)) {
      scr += b;
    }
  }
  ans = scr;
  l = k;
  l--;
  while (!que.empty()) {
    scr = 0;
    for (int i = 0; i < n; i++) {
      int a = nbs[i].first;
      int b = nbs[i].second;
      if (!(a & ~l)) {
        scr += b;
      }
    }
    ans = max(ans, scr);
    l -= 1 << que.front();
    que.pop();
  }
  cout << ans << '\n';
  return 0;
}