#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF (i64)(1e18)
#define MOD (i64)(1e9+7)
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RREP(i, n) for(i64 i = (n)-1; i >= 0; i--)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define RRANGE(i, a, b) for(i64 i = (b)-1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }

int main() {
  i64 n, a, b;
  cin >> n >> a >> b;
  vector<i64> v(n);
  for(auto& x : v) cin >> x;
  sort(ALL(v), greater<i64>());
  double sum = 0;
  REP(i, a) sum += v[i];
  i64 m1 = 0, m2 = 0;
  REP(i, a) if (v[i] == v[a-1]) m1++;
  RANGE(i, a, n) if (v[i] == v[a-1]) m2++;
  vector<vector<i64>> C(n+1, vector<i64>(n+2));
  C[0][0] = 1;
  RANGE(i, 1, n+1) {
    C[i][0] = 1;
    RANGE(j, 1, i+1) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }
  i64 ans = 0;
  if (a == m1) {
    REP(i, min(b-a, m2)+1) {
      ans += C[m1+m2][m1+i];
    }
  } else {
    ans = C[m1+m2][m1];
  }
  cout << setprecision(16) << sum/a << endl;
  cout << setprecision(16) << ans << endl;
  return 0;
}
