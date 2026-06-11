#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, c, k;
  cin >> n >> c >> k;

  vector<ll> t(n);

  REP(i, n) { cin >> t[i]; }

  sort(all(t));

  int ans = 0, nc, nk = -1;

  for (int i = 0; i < n; i++) {
    if (nk < t[i] || !nc) {
      ans++;
      nc = c - 1;
      nk = t[i] + k;
    } else {
      nc--;
    }
  }

  cout << ans << "\n";
}
