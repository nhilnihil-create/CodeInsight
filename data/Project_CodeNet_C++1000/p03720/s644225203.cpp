#include <bits/stdc++.h>
using namespace std;

const int N=55;
int g[N][N];
int main() {
  int n,m;
  cin >> n >> m;
  for ( int i=0; i<m; i++ ) {
    int a,b;
    cin >> a >> b;
    --a;--b;
    g[a][b]++;
    g[b][a]++;
  }
  for ( int i=0; i<n; i++ ) {
    int ans=0;
    for ( int j=0; j<n; j++ ) {
      ans+=g[i][j];
    }
    cout << ans << '\n';
  }
  return 0; 
}
