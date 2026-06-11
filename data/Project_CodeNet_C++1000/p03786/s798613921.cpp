#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n + 1);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, n) b[i + 1] = b[i] + a[i];

  int ans = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (2 * b[i] < a[i]) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
