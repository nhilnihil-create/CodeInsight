#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> box(N,1);
  vector<bool> red(N, false);
  red[0] = true;
  rep (i, M) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (red[x]) {
      red[y] = true;
      if (box[x] == 1) red[x] = false;
    }
    box[x]--; box[y]++;
  }

  int ans = 0;
  rep(i, N) {
    if (red[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}
