#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, l, r, ans = 0;
  cin >> n;
  rep(i, n) {
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}
