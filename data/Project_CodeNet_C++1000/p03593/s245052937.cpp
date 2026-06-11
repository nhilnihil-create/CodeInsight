#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = {0, 1, 0, -1};
static const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'u', 'r', 'd', 'l'};
static const ll INF = 1ll << 60;
static const ll MOD = 1e9 + 7;
int H, W;

signed main() {
  cin >> H >> W;
  vector<int> cnt(26);
  rep(i, H) {
    rep(j, W) {
      char a;
      cin >> a;
      cnt[a - 'a']++;
    }
  }
  int g1 = H & W & 1;  // 奇数のグループ(真ん中にある文字)
  int g2 = H % 2 * W / 2 + W % 2 * H / 2;  // 2(mod2)あるグループ
  int c1 = 0, c2 = 0;                      // 1, 2(mod2)のグループ

  for (int i = 0; i < 26; i++) {
    if (cnt[i] & 1) {
      c1++;
    }
    if (cnt[i] & 2) {
      c2++;
    }
  }

  if (c1 <= g1 && c2 <= g2) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}