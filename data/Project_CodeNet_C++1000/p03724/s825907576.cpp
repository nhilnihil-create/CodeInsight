/**
 *    author:  tourist
 *    created: 08.01.2020 23:04:05       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> cnt(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    ++cnt[x];
    ++cnt[y];
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] % 2 == 1) {
      cout << "NO" << '\n';
      return 0;
    }
  }  
  cout << "YES" << '\n';
  return 0;
}
