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

  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> c(2, 0);
  rep(i, n) c[a[i] % 2]++;
  ll c0 = 1;
  rep(i, c[0]) c0 *= 2;
  ll ans = 0, res = 1, cnt = 0;
  if (p) {
    res *= c[1];
    c[1]--;
    cnt++;
  }
  ans += res;
  while (c[1] >= 2) {
    res *= c[1] * (c[1] - 1);
    c[1] -= 2;
    res /= (cnt + 1) * (cnt + 2);
    cnt += 2;
    ans += res;
  }
  ans *= c0;
  cout << ans << '\n';

  









  
  return 0;
}