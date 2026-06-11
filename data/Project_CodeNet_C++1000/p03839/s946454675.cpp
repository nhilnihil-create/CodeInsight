#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 1e5 + 10;
ll a[N], sum[N];
ll pre[N], suf[N];

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = a[i] + sum[i - 1];
    pre[i] = pre[i - 1] + max(0ll, a[i]);
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + max(0ll, a[i]);
  }

  ll ans = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    ans = max(ans,
      max(0ll, sum[i + k - 1] - sum[i - 1])
      + pre[i - 1]
      + suf[i + k]);
  }
  cout << ans << endl;

  return 0;
}
