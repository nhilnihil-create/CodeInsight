#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;  // vi <=> vl
using P = pair<int, int>;  // int <=> ll
const int MOD = 1e9+7;
const double EPS = 1e-9;

int main() {
  ll H, W; cin >> H >> W;
  
  ll ans = 1e10;
  rep(tmp,(1<<3)) {
    bitset<3> s(tmp);
    vl area(3);
    ll Hs = H, Ws = W;

    if (s.test(0)) {
      area[0] = (H/3 + s[1]) * W;
      Hs -= H/3 + s[1];
    } else {
      area[0] = (W/3 + s[1]) * H;
      Ws -= W/3 + s[1];
    }

    if (s.test(2)) {
      area[1] = (Hs/2) * Ws;
    } else {
      area[1] = (Ws/2) * Hs;
    }

    area[2] = H*W - area[0] - area[1];

    sort(all(area));
    ans = min(ans, area[2]-area[0]);
  }

  cout << ans << endl;
  return 0;
}
