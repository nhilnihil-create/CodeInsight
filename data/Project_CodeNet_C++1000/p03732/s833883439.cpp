#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int N, W, w1, b1;
ll ans = 0;
vector<vector<ll>> vv(4, vector<ll>(0));
void dfs(ll x, ll a, ll b) {
  if (x == 4) {
    chmax(ans, a);
    return;
  }

  dfs(x + 1, a, b);
  rep(i, 0, vv[x].size()) {
    if ((w1 + x) * (i + 1) + b > W)
      break;
    dfs(x + 1, a + vv[x][i], b + (w1 + x) * (i + 1));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> W;
  cin >> w1 >> b1;
  vv[0].push_back(b1);
  rep(i, 1, N) {
    int a, b;
    cin >> a >> b;
    vv[a - w1].push_back(b);
  }

  rep(i, 0, 4) {
    sort(vv[i].rbegin(), vv[i].rend());
    rep(j, 1, vv[i].size()) vv[i][j] = vv[i][j - 1] + vv[i][j];
  }

  dfs(0, 0, 0);
  cout << ans << endl;
}
