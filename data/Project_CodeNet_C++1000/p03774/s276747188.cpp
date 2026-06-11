#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, m;
  cin >> n >> m;

  vector<ll> x(n), y(n);
  vector<ll> cx(m), cy(m);
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < m; i++) cin >> cx[i] >> cy[i];

  for (int i = 0; i < n; i++) {
    int no = 0;
    ll dist = 1e10;
    for (int j = 0; j < m; j++) {
      ll d = abs(x[i] - cx[j]) + abs(y[i] - cy[j]);
      if (d < dist) {
        no = j + 1;
        dist = d;
      }
    }
    printf("%d\n", no);
  }
}
