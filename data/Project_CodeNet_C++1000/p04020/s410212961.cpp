#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(i, n) {
    ans += a[i] / 2;
    a[i] %= 2;
    if (i != n - 1 && a[i] == 1 && a[i + 1] >= 1) {
      a[i]--;
      a[i + 1]--;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
