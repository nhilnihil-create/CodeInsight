#include<bits/stdc++.h>
using namespace std;

vector<int> g[100005];

int dfs(int u) {
  vector<int> tmp;
  for (auto to : g[u]) {
    tmp.push_back(dfs(to));
  }
  if (tmp.size() == 0) return 1;
  sort(tmp.begin(), tmp.end()); reverse(tmp.begin(), tmp.end());
  int ma = 0;
  for (int i = 0; i < tmp.size(); i++) {
    ma = max(ma, tmp[i] + i);
  }
  return ma + 1;
}

main() {
  int n; cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a; cin >> a; --a;
    g[a].push_back(i + 1);
  }
  cout << dfs(0) - 1 << endl;
}