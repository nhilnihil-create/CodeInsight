#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  int l = -1, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (a[m] >= k) r = m;
    else {
      vector<bool> dp(k, false);
      dp[0] = true;
      rep(i, n) {
        if (i == m) continue;
        repr(j, k - 1) {
          if (dp[j] && j + a[i] < k) {
            dp[j + a[i]] = true;
          }
        }
      }
      bool flag = false;
      FOR(i, k - a[m], k) {
        if (dp[i]) {
          flag = true;
          break;
        }
      }
      if (flag) r = m;
      else l = m;
    }
  }
  cout << r << endl;


  
  return 0;
}