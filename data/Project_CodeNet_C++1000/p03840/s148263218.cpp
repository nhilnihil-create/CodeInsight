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

  vector<ll> a(7);
  rep(i, 7) cin >> a[i];

  ll k = 0;
  k += a[0] / 2 * 2;
  k += a[1];
  k += a[3] / 2 * 2;
  k += a[4] / 2 * 2;
  if (a[0] > 0 && a[3] > 0 && a[4] > 0) {
    ll resk = 3;
    a[0]--, a[3]--, a[4]--;
    resk += a[0] / 2 * 2;
    resk += a[1];
    resk += a[3] / 2 * 2;
    resk += a[4] / 2 * 2;
    chmax(k, resk);
  }
  cout << k << '\n';




  
  return 0;
}