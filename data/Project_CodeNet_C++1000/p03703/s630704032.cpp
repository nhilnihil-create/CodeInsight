#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= k;
  }

  function<long long(int,int)> dfs = [&](int l, int r) {
    if (l + 1 == r) {
      if (a[l] >= 0) return 1LL;
      else return 0LL;
    }
    int m = (l + r) / 2;
    vector<long long> sl, sr;
    for (long long i = m - 1, sum = 0; i >= l; i--) {
      sum += a[i];
      sl.push_back(sum);
    }
    for (long long i = m, sum = 0; i < r; i++) {
      sum += a[i];
      sr.push_back(sum);
    }
    sort(sl.begin(), sl.end());
    sort(sr.begin(), sr.end());
    long long res = 0;
    res += dfs(l, m);
    res += dfs(m, r);
    for (auto i : sl) {
      res += sr.size() - (lower_bound(sr.begin(), sr.end(), -i) - sr.begin());
    }
    return res;
  };
  
  cout << dfs(0, n) << '\n';
  return 0;
}
