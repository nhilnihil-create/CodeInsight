#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<vector<int>> ans(h, vector<int>(w));
  int c = 1, res = 0;
  rep(i, h) {
    rep(j, w) {
      ans[i][j] = c;
      res++;
      if (a[c - 1] == res) {
        c++;
        res = 0;
      }
    }
  }

  rep(i, h) {
    if (i & 1) {
      repr(j, w - 1) {
        cout << ans[i][j];
        if (j) cout << " ";
      }
    }
    else {
      rep(j, w) {
        if (j) cout << " ";
        cout << ans[i][j];
      }
    }
    cout << endl;
  }


  
  return 0;
}