#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  int l;
  cin >> l;

  vector<vector<int>> nxt(21, vector<int>(n, 0));
  rep(j, n) {
    int idx = upper_bound(x.begin(), x.end(), x[j] + l) - x.begin();
    idx--;
    nxt[0][j] = idx;
  }
  rep(i, 20) {
    rep(j, n) {
      nxt[i + 1][j] = nxt[i][nxt[i][j]];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b) swap(a, b);

    int ans = inf, res = 0;
    repr(i, 20) {
      if (nxt[i][a] >= b) chmin(ans, res + (1 << i));
      else {
        res += (1 << i);
        a = nxt[i][a];
      }
    }
    cout << ans << '\n';
  }


  




  
  return 0;
}