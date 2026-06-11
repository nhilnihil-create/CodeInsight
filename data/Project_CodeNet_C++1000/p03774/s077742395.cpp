#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  rep(i, n) cin >> a[i] >> b[i];
  rep(i, m) cin >> c[i] >> d[i];

  rep(i, n) {
    vector<int> dist(m);
    rep(j, m) dist[j] = abs(a[i] - c[j]) + abs(b[i] - d[j]);
    vector<int>::iterator iter = std::min_element(dist.begin(), dist.end());
    size_t index = distance(dist.begin(), iter);
    cout << index + 1 << endl;
  }
  return 0;
}
