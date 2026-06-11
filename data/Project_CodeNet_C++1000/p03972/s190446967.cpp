#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ll w, h;
  cin >> w >> h;

  vector<ll> p(w), q(h + 1, 0);
  ll ans = 0;
  for (int i = 0; i < w; i++) {
    cin >> p[i];
    ans += p[i];
  }
  for (int i = 0; i < h; i++) {
    cin >> q[i];
    ans += q[i];
  }
  sort(p.begin(), p.end());
  sort(q.begin(), q.end());

  vector<ll> cump = p, cumq = q;
  for (int i = 1; i < w; i++) {
    cump[i] += cump[i - 1];
  }
  for (int i = 1; i <= h; i++) {
    cumq[i] += cumq[i - 1];
  }
  q[0] = -1;

  for (int i = 0; i < w; i++) {
    ll r = lower_bound(q.begin(), q.end(), p[i]) - q.begin() - 1;
    ans += p[i] * (h - r);
    if (!r) continue;
    ans += cumq[r];
  }
  cout << ans << endl;

  return 0;
}