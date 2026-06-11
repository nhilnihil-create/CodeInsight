#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> beg, end;
  for (int i = 0, a; i < n; i++) {
    cin >> a;
    if (i % 2 == 0) {
      beg.emplace_back(a);
    } else {
      end.emplace_back(a);
    }
  }
  vector<int> ans;
  for (int i = (int)beg.size() - 1; ~i; i--) {
    ans.emplace_back(beg[i]);
  }
  for (int i = 0; i < (int)end.size(); i++) {
    ans.emplace_back(end[i]);
  }
  if (n % 2 == 0) reverse(ans.begin(), ans.end());
  cout << ans[0];
  for (int i = 1; i < n; i++) {
    cout << ' ' << ans[i];
  }
  cout << '\n';
  return 0;
}