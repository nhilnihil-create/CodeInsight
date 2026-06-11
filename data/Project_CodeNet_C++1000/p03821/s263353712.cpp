#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<pair<ll, ll>> x(n);
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    x[i] = make_pair(a, b);
  }
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ll a = ans + x[i].first;
    ll b = x[i].second;
    if (a % b == 0) continue;
    ans += b - (a % b);
  }
  cout << ans << endl;
  return 0;
}