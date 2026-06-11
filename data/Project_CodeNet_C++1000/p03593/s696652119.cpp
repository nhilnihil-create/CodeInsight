#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int vis[105][105];
int cnt[5];
int f[256];
int main() {
  IOS;
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      f[c]++;
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (vis[i][j])
        continue;
      int tmp = 0;
      tmp = !vis[i][j], vis[i][j] = 1;
      tmp += !vis[h - i - 1][j], vis[h - i - 1][j] = 1;
      tmp += !vis[i][w - j - 1], vis[i][w - j - 1] = 1;
      tmp += !vis[h - i - 1][w - j - 1], vis[h - i - 1][w - j - 1] = 1;
      cnt[tmp]++;
    }
  }
  for (int k = 4; k >= 1; k--) {
    for (int i = 0; i < cnt[k]; i++) {
      int ok = 0;
      for (int j = 'a'; j <= 'z'; j++) {
        if (f[j] >= k) {
          f[j] -= k, ok = 1;
          break;
        }
      }
      if (!ok) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
