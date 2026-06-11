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
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  rep(i, n - 1) {
    if (a[i] + a[i + 1] >= l) {
      cout << "Possible" << '\n';   
      vector<int> ans;
      FORR(j, i + 1, 1) ans.push_back(j);
      FOR(j, i + 2, n) ans.push_back(j);
      repr(i, n - 2) cout << ans[i] << '\n';
      return 0;
    }
  }
  cout << "Impossible" << '\n';




  
  return 0;
}