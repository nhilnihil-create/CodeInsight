#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, R;
  cin>>n>>m>>R;
  int r[R];
  for (int i=0; i<R; i++) {
    cin>>r[i];
    --r[i];
  }
  int d[n][n];
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i != j) {
        d[i][j] = 1e9;
      } else {
        d[i][j] = 0;
      }
    }
  }
  for (int i=0; i<m; i++) {
    int a, b, c;
    cin>>a>>b>>c;
    --a;
    --b;
    d[a][b] = c;
    d[b][a] = c;
  }
  for (int k=0; k<n; k++) {
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (d[i][k] < 1e9 && d[k][j] < 1e9) {
          d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
        }
      }
    }
  }
  sort(r, r + R);
  int ans = 1e9;
  do {
    int tmp = 0;
    for (int i=0; i<R-1; i++) {
      tmp += d[r[i]][r[i+1]];
    }
    ans = min(tmp, ans);
  } while (next_permutation(r, r + R));
  cout<<ans<<endl;
}