
// Problem: D - An Invisible Hand
// Contest: AtCoder - AtCoder Regular Contest 063
// URL: https://atcoder.jp/contests/arc063/tasks/arc063_b
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 1;

int n, t;
int a[N];

int32_t main() { cin.tie(0)->sync_with_stdio(0);
  cin >> n >> t;
  set<int> s;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!s.empty()) {
      mx = max(mx, a[i] - *s.begin());
    }
    s.insert(a[i]);
  }
  s.clear();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!s.empty() && mx == a[i] - *s.begin()) {
      ans++;
    }
    s.insert(a[i]);
  }
  cout << ans;
}