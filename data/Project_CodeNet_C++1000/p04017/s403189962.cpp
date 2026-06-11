#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repi(i, a, b) for (int i = (a); i < int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ull << (b))
#define uniq(v) (v).erase(unique(all(v)), (v).end())

using namespace std;
using i32 = int;
using i64 = long long;
using f64 = double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vf64 = vector<f64>;
using vstr = vector<string>;

template<typename T, typename S> void amax(T &x, S y) { if (x < y) x = y; }
template<typename T, typename S> void amin(T &x, S y) { if (y < x) x = y; }

int dp[100010][21];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(16);
  int n;
  cin >> n;
  vi64 x(n);
  rep(i, n) cin >> x[i];
  int l, q;
  cin >> l >> q;
  rep(i, n) dp[i][0] = upper_bound(all(x), x[i] + l) - x.begin() - 1;
  rep(i, 20) rep(j, n) dp[j][i + 1] = dp[dp[j][i]][i];
  rep(_, q) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    if (a > b) swap(a, b);
    int ans = 1;
    rrep(i, 20) if (dp[a][i] < b) {
      a = dp[a][i];
      ans += 1 << i;
    }
    cout << ans << endl;
  }
  return 0;
}
