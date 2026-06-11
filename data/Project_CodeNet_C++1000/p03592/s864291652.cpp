#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  bool ans = false;
  for (ll i = 0; i <= n; i++)
    for (ll j = 0; j <= m; j++) {
      ll val = i * m + j * n - 2 * i * j;
      if (val == k) ans = true;
    }
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
