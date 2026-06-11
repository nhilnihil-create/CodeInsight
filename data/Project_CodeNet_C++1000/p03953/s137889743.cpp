/**
 *    author:  tourist
 *    created: 01.01.2020 20:09:07       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  vector<int> d(n - 1);
  for (int i = 0; i < n - 1; i++) {
    d[i] = x[i + 1] - x[i];
  }
  int m;
  long long k;
  cin >> m >> k;
  vector<int> p(n - 1);
  for (int i = 0; i < n - 1; i++) {
    p[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    swap(p[x - 2], p[x - 1]);
  }
  vector<int> q(n - 1);
  for (int i = 0; i < n - 1; i++) {
    q[i] = i;
  }
  while (k > 0) {
    if (k & 1) {
      vector<int> r(n - 1);
      for (int i = 0; i < n - 1; i++) {
        r[i] = p[q[i]];
      }
      swap(q, r);
    }
    vector<int> r(n - 1);
    for (int i = 0; i < n - 1; i++) {
      r[i] = p[p[i]];
    }
    swap(p, r);
    k >>= 1;
  }
  vector<int> new_d(n - 1);
  for (int i = 0; i < n - 1; i++) {
    new_d[i] = d[q[i]];
  }
  long long res = x[0];
  cout << res << '\n';
  for (int i = 0; i < n - 1; i++) {
    res += new_d[i];
    cout << res << '\n';
  }
  return 0;
}
