#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  rep(i, n - m + 1) {
    rep(j, n - m + 1) {
      bool flag = true;
      rep(k, m) rep(l, m) flag &= (a[i + k][j + l] == b[k][l]);
      if (flag) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
  return 0;
}
