#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, m;
bool ans = false;
bool t;


int main() {
  cin >> n >> m;
  vector<string> a(n);
  vector<string> b(m);
  rep (i, n) {
    cin >> a[i];
  }
  rep (i, m) {
    cin >> b[i];
  }
  rep (i, n-m+1) {
    rep (j, n-m+1) {
      t = true;
      rep (x, m) {
        rep (y, m) {
          if (a[i+x][j+y] != b[x][y]) t = false;
        }
        if (!t) break;
      }
      if (t) {
        ans = true;
        break;
      }
    }
    if (ans) break;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
