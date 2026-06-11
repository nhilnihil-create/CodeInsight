#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, t;
  cin >> n >> t;

  vector<ll> vt(n);
  for (int i = 0; i < n; ++i) {
    cin >> vt[i];
  }

  ll ans = t * n, cur_t = t;
  for (int i = 1; i < vt.size(); ++i) {
    if (vt[i - 1] + t >= vt[i]) {
      ans -= (vt[i - 1] + t) - vt[i];
    }
  }

  cout << ans << '\n';
}