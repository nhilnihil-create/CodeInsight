#include <bits/stdc++.h>
using namespace std;

long long n, k, a[100005] = {0}, b[100005] = {0}, t = 0;
long long memo[35] = {0};

long long solve();

int main() {
  cin >> n >> k;
  for(long long i = 0; i < n; ++i) cin >> a[i] >> b[i];
  memo[0] = 1;
  for(long long i = 1; i < 32; ++i)
    memo[i] = 2 * memo[i - 1];
  while(memo[t] <= k) ++t;
  t = max(t - 1, 0LL);
  cout << solve() << endl;
  return 0;
}

// decided x ~ t
long long solve() {
  long long ans = 0, now = 0;
  for(long long i = 0; i < n; ++i)
    if((k | a[i]) == k) ans += b[i];
  for(long long x = t; x >= 0; --x) {
    now = 0;
    for(long long i = 0; i < n; ++i) {
      if(k >= memo[x] && memo[x] > a[i])
        now += b[i];
      else if(k >= memo[x] && a[i] >= memo[x])
        a[i] -= memo[x];
    }
    if(k >= memo[x]) k -= memo[x];
    ans = max(ans, now);
  }
  return ans;
}