#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  rep(i, n - m + 1) rep(j, n - m + 1) {
    bool ok = true;
    rep(k, m) {
      if (a[i + k].substr(j, m) != b[k]) ok = false;
    }
    if (ok == true) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
