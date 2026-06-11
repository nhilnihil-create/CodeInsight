#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORS(i, m, n) for (int i = m; i <= n; i++)
#define bit(n) (1LL << (n))
#define INF 2e9
#define MOD (1000000007)
#define EPS 1e-9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef long long int lli;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  lli N, X;
  cin >> N >> X;

  lli sM = max(N - X, X);
  lli sN = min(N - X, X);
  lli ans = N; // 5
  //(3,2)+4
  //(2,1)+3
  while (sM % sN != 0) {
    ans += 2ll * sN * (sM / sN);
    lli tmp = sN;
    sN = sM % sN;
    sM = tmp;
  }

  ans += 2ll * sN * (sM / sN) - sN;
  cout << ans << "\n";
}