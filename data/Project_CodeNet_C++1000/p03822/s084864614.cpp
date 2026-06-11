#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> e(n + 1);
  for (int i = 2; i <= n; ++i) {
    int a;
    cin >> a;
    e[a].push_back(i);
  }
  function<int(int)> dfs = [&](int v) {
    if (e[v].empty()) {
      return 0;
    }
    vector<int> d;
    for (int i : e[v]) {
      d.push_back(dfs(i));
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size(); ++i) {
      d[i] += d.size() - i;
    }
    sort(d.begin(), d.end());
    return d.back();
  };
  cout << dfs(1) << endl;
  return 0;
}
