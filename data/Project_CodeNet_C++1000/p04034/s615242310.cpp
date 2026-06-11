#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(m), y(m);
  rep(i, m) cin >> x[i] >> y[i];

  vector<int> bc(n), rb(n);
  rep(i, n) bc[i] = 1;
  rb[0] = 1;

  rep(i, m) {
    int o = x[i] - 1;
    int d = y[i] - 1;

    if (rb[o] != 0) rb[d] = 1;
    bc[o]--;
    if (bc[o] == 0) rb[o] = 0;
    bc[d]++;
  }

  int ans = 0;
  rep(i, n) if (rb[i] != 0) ans++;
  cout << ans << endl;
}
