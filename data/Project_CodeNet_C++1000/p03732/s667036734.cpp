#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 111;
ll w[maxn], v[maxn], w0;
int N, W;
ll ans;
vector<ll> vv[5];
ll pre[5][maxn];
bool cmp(ll a, ll b) { return a > b; }
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }
  w0 = w[0];
  for (int i = 0; i < N; i++) {
    vv[w[i] - w0].push_back(v[i]);
  }
  for (int i = 0; i < 4; i++) {
    sort(vv[i].begin(), vv[i].end(), cmp);
    for (int j = 0; j < vv[i].size(); j++) {
      pre[i][j + 1] = pre[i][j] + vv[i][j];
    }
  }
  for (int i = 0; i <= vv[0].size(); i++) {
    for (int j = 0; j <= vv[1].size(); j++) {
      for (int k = 0; k <= vv[2].size(); k++) {
        for (int l = 0; l <= vv[3].size(); l++) {
          if (w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3) * l <= W) {
            ans = max(ans, pre[0][i] + pre[1][j] + pre[2][k] + pre[3][l]);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
