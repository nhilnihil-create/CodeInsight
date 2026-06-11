/**
 *    author:  tourist
 *    created: 27.11.2019 10:01:04       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = (int) 2e9;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ans = min(ans, a + b);
  }
  cout << ans << '\n';
  return 0;
}
