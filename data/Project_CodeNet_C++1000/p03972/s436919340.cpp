#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main() {
  ll w, h;
  cin >> w >> h;
  vector<ll> lp(w), lq(h);
  for (ll &p: lp) cin >> p;
  for (ll &q: lq) cin >> q;
  sort(lp.begin(), lp.end());
  sort(lq.begin(), lq.end());
  lp.push_back(1e10);
  lq.push_back(1e10);
  int ip = 0, iq = 0;
  ll ans = 0;
  while (ip < w || iq < h) { 
    if (lp[ip] <= lq[iq]) {
      ans += (h-iq+1)*lp[ip];
      ++ip;
    }
    else { 
      ans += (w-ip+1)*lq[iq];
      ++iq;
    }
  }
  cout << ans << endl;
}

