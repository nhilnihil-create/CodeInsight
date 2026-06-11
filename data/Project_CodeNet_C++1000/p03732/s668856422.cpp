#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

  long long N;
  scanf("%lld", &N);
  long long W;
  scanf("%lld", &W);
  vector<ll> w(N);
  vector<ll> v(N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &w[i], &v[i]);
  }
  auto w0 = w[0];
  map<ll, vector<ll>> m;
  for (int i = 0; i < N; i++) {
    m[w[i] - w0].push_back(v[i]);
  }
  ll s[4][N+1];
  for (int i = 0; i < 4; i++) {
    sort(m[i].begin(), m[i].end(), greater<>());
    s[i][0] = 0;
    for (int j = 0; j < m[i].size(); j++) {
	s[i][j+1] = s[i][j] + m[i][j];
    }
  }
  ll maxVal = 0;
  for (int i = 0; i <= m[0].size(); i++) {
    for (int j = 0; j <= m[1].size(); j++) {
      for (int k = 0; k <= m[2].size(); k++) {
        for (int l = 0; l <= m[3].size(); l++) {
          if (w0 * i + (w0 + 1) * j + (w0 + 2) * k + (w0 + 3)*l <= W) {
	      maxVal = max(maxVal, s[0][i] + s[1][j] + s[2][k] + s[3][l]);
          }
        }
      }
    }
  }
  cout << maxVal << endl;
}
