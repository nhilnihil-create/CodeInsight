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
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  map<int, int> cnt;
  rep(i, n) cnt[x[i]]++;
  map<int, int> res;
  int ans = 0;
  rep(i, n) {
    ans += cnt[x[i]] / 2;
    res[x[i] % m] += cnt[x[i]] % 2;
    cnt[x[i]] = 0;
  }
  rep(i, n) cnt[x[i] % m]++;
  ans += res[0] / 2;
  FOR(i, 1, m / 2 + 1) {
    if (i == m - i) {
      ans += res[i] / 2;
      break;
    }
    int now = min(cnt[i], cnt[m - i]);
    ans += now;
    if (res[i] < now) {
      ans -= (now - res[i] + 1) / 2;
    }
    if (res[m - i] < now) {
      ans -= (now - res[m - i] + 1) / 2;
    }
  }
  cout << ans << endl;
  



  
  return 0;
}