#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull n, k, a[100005] = {0}, b[100005] = {0}, t = 0;
ull memo[70] = {0};

ull solve(ull x);

int main() {
  cin >> n >> k;
  for(ull i = 0; i < n; ++i) cin >> a[i] >> b[i];
  memo[0] = 1;
  for(ull i = 1; i < 64; ++i) memo[i] = 2 * memo[i - 1];
  if(k == 0) {
    for(ull i = 0; i < n; ++i) {
      if(a[i] == 0) t += b[i];
    }
    cout << t << endl;
    return 0;
  }
  while(memo[t] <= k) ++t;
  --t;
  cout << solve(t) << endl;
  return 0;
}

// decided x ~ t
ull solve(ull x) {
  if(x > t) return 0;
  ull ans = 0, now = 0;
  for(ull i = 0; i < n; ++i)
    if((k | a[i]) == k) now += b[i];
  for(ull i = 0; i < n; ++i) {
    if(k >= memo[x] && memo[x] > a[i])
      ans += b[i];
    else if(k >= memo[x] && a[i] >= memo[x])
      a[i] -= memo[x];
  }
  if(k >= memo[x]) k -= memo[x];
  ans = max(ans, now);
  now = solve(x - 1);
  return max(ans, now);
}