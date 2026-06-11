#include<bits/stdc++.h>

#define MOD_1_000_000_007 (1000000007LL)
#define rep(i, n)   for (long long i = 0; i <  (long long)(n); i++)
#define rep1(i, n)  for (long long i = 1; i <  (long long)(n); i++)
#define rep2(i, n)  for (long long i = 2; i <  (long long)(n); i++)
#define rep0c(i, n) for (long long i = 0; i <= (long long)(n); i++)
#define rep1c(i, n) for (long long i = 1; i <= (long long)(n); i++)
#define rep2c(i, n) for (long long i = 2; i <= (long long)(n); i++)
#define repc0(n, i) for (long long i = (long long)(n); i >= 0; i--)
#define repc1(n, i) for (long long i = (long long)(n); i >= 1; i--)
#define repc2(n, i) for (long long i = (long long)(n); i >= 2; i--)

namespace solver {
  using namespace std;
  typedef long long ll;

  ll N, K, a[20];

  void init() {
    scanf("%d %d", &N, &K);
    rep(i, N) scanf("%d", &a[i]);
  }

  void solve() {
    ll minv = 20000000000ll;
    rep(k, 1<<(N-1)) {
      ll prev = a[0], current = 0ll, count = 1ll;
      rep(i, N-1) {
        if(prev < a[i+1]) {
          count++;
          prev = a[i+1];
        } else if(k & (1<<i)) {
          current += prev + 1 - a[i+1];
          count++;
          prev++;
        }
      }
      if(K <= count) minv = min(minv, current);
    }
    printf("%lld\n", minv);
  }
}


int main() {
  solver::init();
  solver::solve();
  return 0;
}