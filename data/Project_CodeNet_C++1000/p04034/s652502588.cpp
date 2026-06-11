#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 3e5;

int sz[N];
int can[N];

void solve() {
  int n, m; cin >> n >> m;
  fill(sz + 1, sz + 1 + n, 1);
  can[1] = 1;
  for (int i = 1; i <= m; i++) {
    int x, y; cin >> x >> y;
    if (can[x]) {
      if (sz[x] == 1) {
        can[x] = 0;
      }
      can[y] = 1;
    }
    sz[x]--, sz[y]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += can[i];
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
