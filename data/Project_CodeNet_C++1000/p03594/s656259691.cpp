#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

const char COLOR[4] = { 'R', 'G', 'B', 'Y' };

ll H, W, D;
char ans[500][500];

int main(void) {
  cin >> H >> W >> D;

  REP(i, 0, H) REP(j, 0, W) {
    ll y = i + j + H, x = i - j + W;
    ans[i][j] = COLOR[((y / D) % 2) * 2 + (x / D) % 2];
  }

  REP(i, 0, H) {
    REP(j, 0, W) cout << ans[i][j];
    cout << endl;
  }
}
