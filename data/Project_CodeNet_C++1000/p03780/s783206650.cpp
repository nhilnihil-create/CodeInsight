#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, K;
ll a[5010];

bool check(int m) {
  bool dp[5010] = {};
  dp[0] = true;
  for (int i = 0; i < n; i++) {
    if (i == m) continue;
    for (int j = K; j - a[i] >= 0; j--) {
      dp[j] |= dp[j - a[i]];
    }
  }

  bool res = false;
  for (int i = max(0LL, K - a[m]); i < K; i++) {
    res |= dp[i];
  }
  return res;
}

int main() {
  cin >> n >> K;

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum < K) {
    cout << n << endl;
    return 0;
  }
  sort(a, a + n);

  int ng = -1, ok = n - 1;
  while (ok - ng > 1) {
    int m = (ng + ok) / 2;
    if (check(m)) ok = m;
    else ng = m;
  }
  cout << ng + 1 << endl;

  return 0;
}