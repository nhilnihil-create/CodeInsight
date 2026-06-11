#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 1e5 + 10;
int a[N], pref[N], suf[N], sum[N];  

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1];
    if (a[i] > 0) {
      pref[i] += a[i];
    }
    sum[i] = sum[i - 1] + a[i];
  }  
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1];
    if (a[i] > 0) {
      suf[i] += a[i];
    }
  }
  int ans = 0;
  for (int lst = 1; lst + k - 1 <= n; lst++) {
    ans = max(ans, pref[lst - 1] + suf[lst + k] + max(0ll, sum[lst + k - 1] - sum[lst - 1]));
  }
  cout << ans << '\n';
}