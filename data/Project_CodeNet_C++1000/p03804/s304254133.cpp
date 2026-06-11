#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  rep(i, n) cin >> a[i];
  vector<string> b(m);
  rep(i, m) cin >> b[i];

  for (int posy = 0; posy <= n - m; ++posy) {
    for (int posx = 0; posx <= n - m; ++posx){
      bool ok = true;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
          if (b[i][j] != a[posy + i][posx + j]) {
            ok = false;
            break;
          }
        }
        if (!ok) {
          break;
        }
      }
      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  
  return 0;
}