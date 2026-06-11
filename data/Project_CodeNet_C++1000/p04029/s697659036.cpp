#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int ans = (n+1)*n;
  ans /=2;
  cout << ans;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
