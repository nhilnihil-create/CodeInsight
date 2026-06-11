#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), idx;
  for (int i = 1; i <= n; ++i) {
    idx.push_back(i);
    cin >> a[i];
  }
  auto cmp = [&](int i, int j) {
    return a[i] < a[j];
  };
  sort(idx.begin(), idx.end(), cmp);
  set<int> seen;
  seen.insert(0);
  seen.insert(n + 1);
  long long ans = 0;
  for (int i : idx) {
    auto pr = seen.lower_bound(i);
    auto pl = pr;
    --pl;
    seen.insert(i);
    ans += a[i] * (*pr - (long long) (i)) * (i - *pl);
  }
  cout << ans << endl;
  return 0;
}
