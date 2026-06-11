// 2020-08-25 21:02:59
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

ll ans[2], cur[2];
void answer() {
  int n;
  cin >> n;
  rep(i, n) {
    ll a;
    cin >> a;
    int x = i%2, y = (i+1)%2;
    cur[x] += a;
    cur[y] += a;
    if(cur[x] <= 0) ans[x] += 1 - cur[x], cur[x] = 1;
    if(cur[y] >= 0) ans[y] += 1 + cur[y], cur[y] = -1;
  }
  cout << min(ans[0], ans[1]) << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}