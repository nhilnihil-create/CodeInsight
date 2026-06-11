#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n, x;
  cin >> n >> x;
  ll a[100005];
  ll ans = 0;
  REP(i, n) {
    int t;
    cin >> t;
    ans += max(t - x, 0);
    a[i] = min(x, t);
  }
  REP(i, n - 1) {
    if (a[i] + a[i + 1] > x) {
      ans += (a[i] + a[i + 1] - x);
      a[i + 1] -= (a[i] + a[i + 1] - x);
    }
  }
  cout << ans << endl;
}