#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll W, H, P[100000], Q[100000];

int main(void) {
  cin >> W >> H;
  REP(i, 0, W) cin >> P[i];
  REP(i, 0, H) cin >> Q[i];

  vector<pll> len;
  REP(i, 0, W) len.push_back(pll(P[i], 0));
  REP(i, 0, H) len.push_back(pll(Q[i], 1));
  sort(len.begin(), len.end());

  ll wcnt = 0, hcnt = 0, ans = 0;
  REP(i, 0, len.size()) {
    ll l = len[i].first;
    ll t = len[i].second;

    if(t == 0) {
      ans += (H + 1 - hcnt) * l;
      wcnt++;
    } else {
      ans += (W + 1 - wcnt) * l;
      hcnt++;
    }
  }
  cout << ans << endl;
}
