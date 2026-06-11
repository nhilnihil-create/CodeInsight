#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> x(n + 1), f(n + 1);
  for (int i = 1; i <= n; i++) cin >> x.at(i);
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += min(1ll * a * (x.at(i) - x.at(i - 1)), 1ll * b);
  }
  cout << ans << '\n';
}