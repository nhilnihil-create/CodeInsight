#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> in(n);
  vector<long long> best(n + 1), sum(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> in[i];
    best[i + 1] += best[i] + max(in[i], 0LL);
    sum[i + 1] = sum[i] + in[i];
  }
  long long ans = -(1LL << 60);
  for (int i = 1; i + k - 1 <= n; i++) {
    ans = max(ans, best[i - 1] + best[n] - best[i + k - 1] + max(0LL, sum[i + k - 1] - sum[i - 1]));
  }
  cout << ans << endl;
  return 0;
}