#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<long long> c(m), d(m);
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }
  for (int i = 0; i < n; i++) {
    vector<long long> dis(m);
    for (int j = 0; j < m; j++) {
      dis[j] = llabs(a[i] - c[j]) + llabs(b[i] - d[j]);
    }
    cout << (int)distance(dis.begin(), min_element(dis.begin(), dis.end())) + 1
         << '\n';
  }
}