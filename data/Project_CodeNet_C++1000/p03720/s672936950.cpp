#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int>ans(n+1);
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    ans[a]++;
    ans[b]++;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << "\n";
  }

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}

