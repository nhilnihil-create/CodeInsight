#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
const ll INF = (1ll << 60);

int main() {
  ll W, H;
  cin >> W >> H;

  vi p(W), q(H);
  for (ll i = 0; i < W; i++) cin >> p[i];
  for (ll i = 0; i < H; i++) cin >> q[i];

  using tiii = tuple<ll, ll, ll>;
  priority_queue<tiii> pq;

  for (ll i = 0; i < W; i++) {
    pq.emplace(-p[i], 0, i);
  }

  for (ll i = 0; i < H; i++) {
    pq.emplace(-q[i], 1, i);
  }

  ll ans = 0;
  while (pq.size()) {
    ll h, i;
    tie(ignore, h, i) = pq.top();
    pq.pop();

    if (h) {
      ans += q[i] * (W + 1);
      H -= 1;
    } else {
      ans += p[i] * (H + 1);
      W -= 1;
    }
  }

  cout << ans << endl;
  
}
