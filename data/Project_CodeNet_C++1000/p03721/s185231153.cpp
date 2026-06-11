#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n), b(n);
  vector<P> p(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
    p[i] = {a[i], b[i]};
  }

  sort(p.begin(), p.end());

  int ans = 0;
  ll cnt = 0;
  rep(i, n) {
    if (cnt >= k) break;
    ans = p[i].first;
    cnt += p[i].second;
  }
  cout << ans << endl;
}
