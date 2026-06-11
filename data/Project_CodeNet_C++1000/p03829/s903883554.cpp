#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    ans += min((ll)(x[i] - x[i - 1]) * a, (ll)b);
  }
  cout << ans << endl;
}
