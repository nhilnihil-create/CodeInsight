#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, W;
  cin >> N >> W;

  vector<vector<ll>> a(4);
  ll w0 = 0;
  vector<ll> w(N + 1), v(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> w[i] >> v[i];
    if(i == 1) w0 = w[i];
    int itr = w[i] - w0;
    a[itr].push_back(v[i]);
  }
  for (int i = 0; i < 4; i++) {
    sort(a[i].rbegin(),a[i].rend());
    a[i].insert(a[i].begin() + 0,0);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < (int)a[i].size(); j++) {
      a[i][j] += a[i][j - 1];
    }
  }
  ll ans = 0;
  for (int i = 0; i < a[0].size(); i++) {
    for (int j = 0; j < a[1].size(); j++) {
      for (int k = 0; k < a[2].size(); k++) {
        for (int l = 0; l < a[3].size(); l++) {
          ll sum = w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3) * l;
          if (sum > W) break;
          ll tmp = a[0][i] + a[1][j] + a[2][k] + a[3][l];
          ans = max(ans, tmp);
        }
      }
    }
  }
  cout << ans << '\n';
}