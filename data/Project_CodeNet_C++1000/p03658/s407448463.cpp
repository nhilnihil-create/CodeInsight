#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  sort(l.rbegin(), l.rend());
  ll ans = 0;
  rep(i, k) ans += l[i];
  cout << ans << endl;
  return 0;
}
