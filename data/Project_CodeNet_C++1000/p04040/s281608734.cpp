#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;
ll inv[200010], fac[200010], finv[200010];

ll C(int a, int b) {
  if(a < b) return 0;
  return fac[a] * (finv[b]*finv[a-b] % MOD) % MOD;
}

int main() {
  int H, W, A, B; cin >> H >> W >> A >> B; H--, W--;
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i = 2; i < 200010; ++i) {
    inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
    fac[i] = fac[i-1] * (ll)i%MOD;
    finv[i] = finv[i-1]*inv[i]%MOD;
  }
  ll ret = C(W+H, W);

  for(int i = 0; i < B; ++i) {
    ll all = C((H-A)+i, i);
    ll all2 = C((W-i)+(A-1), A-1);
    ret -= all*all2%MOD;
    if(ret < 0) ret += MOD;
  }
  cout << ret << endl;

  return 0;
}
