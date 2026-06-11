#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> marked(n * n);
  vector<int> ans(n * n);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    --x;
    marked[x] = ans[x] = i;
  }
  for (int i = n * n - 1, j = n * n - 1; i >= 0; i--) {
    if (marked[i] == 0) continue;
    int need = n - marked[i];
    for (; j > i && need > 0; j--) {
      if (ans[j] == 0) ans[j] = marked[i], need--;
    }
    if (need > 0) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = 0, j = 0; i < n * n; i++) {
    if (marked[i] == 0) continue;
    int need = marked[i] - 1;
    for (;j < i && need > 0; j++) {
      if (ans[j] == 0) ans[j] = marked[i], need--;
    }
    if (need > 0) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = 0; i < n * n; i++) if (ans[i] == 0) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (int i = 0; i < n * n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}