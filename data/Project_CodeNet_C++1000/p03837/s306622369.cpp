#include <bits/stdc++.h>
using namespace std;

#define VV(T) vector<vector<T> >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()) {
  v.assign(a, vector<T>(b, t));
}

#define REP(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  VV(int) d;
  initvv(d, n, n, 1010101010);
  for (int i = 0; i < n; ++i) {
    d[i][i] = 0;
  }
  vector<int> a(m), b(m), c(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i];
    --b[i];
    d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    ans += d[a[i]][b[i]] != c[i];
  }
  cout << ans << endl;
}
