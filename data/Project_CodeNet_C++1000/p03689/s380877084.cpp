#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll H, W, A, B;

int main(void) {
  cin >> H >> W >> A >> B;

  if(A * B == 1) {
    cout << "No" << endl;
    return 0;
  }

  ll d = A * B - 1;
  ll u = (1000000000LL - 1) / d;
  ll m = u * d + 1;
  ll p = (H / A) * (W / B);
  ll s = (H * W - p) * u - p * m;

  if(s > 0) {
    cout << "Yes" << endl;
    REP(i, 0, H) REP(j, 0, W) cout << ((i + 1) % A == 0 && (j + 1) % B == 0 ? -m : u) << (j + 1 != W ? " " : "\n");
  } else {
    cout << "No" << endl;
  }
}
