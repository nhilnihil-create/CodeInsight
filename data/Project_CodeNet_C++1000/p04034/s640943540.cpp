#include <bits/stdc++.h>
using namespace std;

long long n, m, res = 1;
vector<bool> red;
vector<int> cnt;

int main() {
  cin >> n >> m;
  red.assign(n, 0);
  red[0] = 1;
  cnt.assign(n, 1);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --y, --x;
    if (red[x]) {
      res += !red[y];
      red[y] = 1;
    }
    if (--cnt[x] == 0) {
      res -= red[x];
      red[x] = 0;
    }
    ++cnt[y];
  }
  cout << res << endl;
  return 0;
}
