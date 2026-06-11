#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, ans = 0, cnt = 1;
  cin >> n;
  vector<ll> a(n * 3);
  rep(i, n * 3) cin >> a[i];

  sort(a.rbegin(), a.rend());

  for (int i = i + 1; i < 2 * n; i += 2) ans += a[i];

  cout << ans << endl;
  return 0;
}