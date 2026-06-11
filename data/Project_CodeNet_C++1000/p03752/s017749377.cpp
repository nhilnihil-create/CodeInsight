#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n, k;
  cin >> n >> k;
  if(k == 1) {
    cout << 0 << "\n";
    return;
  }
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll minv = 1e18;
  rep(i, 1<<(n-1)) {
    if(__builtin_popcount(i) == k - 1) {
      int cur = a[0];
      ll res = 0;
      rep(j, n-1) {
        if(i&(1<<j)) {
          if(cur+1<=a[j+1]) {
            cur = a[j+1];
          } else {
            res += cur+1-a[j+1];
            cur++;
          }
        } else {
          chmax(cur, a[j+1]);
        }
      }
      chmin(minv, res);
    }
  }
  cout << minv << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}