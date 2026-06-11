#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

int main() {
  int W, H; cin >> W >> H;
  ll p[W]; rep(i,W) cin >> p[i];
  ll q[H]; rep(i,H) cin >> q[i];

  ll result = 0;
  rep(i,W) result += p[i];
  rep(i,H) result += q[i];

  sort(q,q+H);
  ll qs[H+1] = {}; rep(i,H) qs[i+1] = qs[i] + q[(H-1)-i];
  rep(i,W) {
    auto ite = upper_bound(q, q+H, p[i]);
    int pos = (q+H) - ite;
    result += qs[H] - qs[pos] + p[i] * pos;
    // cout << i << " " << p[i] << " " << pos << endl;
  }

  cout << result << endl;
  return 0;
}