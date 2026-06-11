#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> box(n, 1);
  vector<bool> pos(n, false);
  pos[0] = true;
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    box[x]--;
    box[y]++;
    if (pos[x]) pos[y] = true;
    if (pos[x] && box[x] == 0) pos[x] = false;
  }

  int ans = 0;
  rep(i, n) if (pos[i]) ans++;
  cout << ans << endl;
  return 0;
}
