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

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }

  vector<ll> seg(m, 0), cost(m, 0);
  rep(i, n - 1) {
    seg[(a[i] + 1) % m]++;
    seg[a[i + 1]]--;
    cost[a[i + 1]] += (a[i + 1] - a[i] + m - 1) % m;
  }
  ll res = 0, cnt = 0;
  rep(i, n - 1) {
    if (a[i] < a[i + 1]) res += a[i + 1] - a[i];
    else {
      res += a[i + 1] + 1;
      if (a[i] != m - 1) cnt++;
    }
  }
  ll ans = res;
  rep(i, m - 1) {
    //cout << cnt << '\n';
    res += cost[i];
    cnt += seg[i];
    res -= cnt;
    chmin(ans, res);
    //cout << res << '\n';
  }
  cout << ans << '\n';


  




  
  return 0;
}