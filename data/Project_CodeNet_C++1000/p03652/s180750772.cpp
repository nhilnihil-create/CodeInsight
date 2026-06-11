#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a;
vector<int> memo;
vector<bool> erased;

int solve();

int main() {
  cin >> n >> m;
  a.assign(n, vector<int>(m, 0));
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
  cout << solve() << endl;
  return 0;
}

int solve() {
  int ans = n;
  erased.assign(m, 0);
  memo.assign(n, 0);
  for(int i = 0; i < m; ++i) {
    vector<int> cnt(m, 0);
    for(int j = 0; j < n; ++j) ++cnt[a[j][memo[j]]];
    int now = 0;
    for(int j = 0; j < m; ++j)
      if(cnt[now] < cnt[j]) now = j;
    ans = min(ans, cnt[now]);
    erased[now] = 1;
    for(int j = 0; j < n; ++j)
      while(memo[j] < m && erased[a[j][memo[j]]]) ++memo[j];
  }
  return ans;
}
