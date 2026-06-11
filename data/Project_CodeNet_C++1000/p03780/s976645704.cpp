#include <bits/stdc++.h>
using namespace std;

long long n, k;
vector<long long> a;

bool need(long long x);
long long solve();

int main() {
  cin >> n >> k;
  for(long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long l = 0, r = n - 1, now;
  while(l <= r) {
    if(r - l < 2) {
      if(need(l))
        return l;
      else if(need(r))
        return r;
      else
        return r + 1;
    }
    now = (l + r) / 2;
    if(need(now))
      r = now;
    else
      l = now;
  }
  return -1;
}

bool need(long long x) {
  if(a[x] >= k) return 1;
  bool memo[2][10005] = {0};
  memo[1][a[x]] = 1;
  for(long long i = 0; i < n; ++i)
    for(long long j = 0; j <= 10000; ++j) {
      memo[i % 2][j] = memo[1 - i % 2][j];
      if(i != x && j - a[i] >= 0 &&
         memo[1 - i % 2][j - a[i]])
        memo[i % 2][j] = 1;
    }
  for(long long i = k; i < k + a[x]; ++i)
    if(memo[(n - 1) % 2][i]) return 1;
  return 0;
}