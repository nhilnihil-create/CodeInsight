#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> a(n);
  vector<pair<int,int>> b(m);
  for ( int i=0; i<n; i++ ) cin >> a[i].first >> a[i].second;
  for ( int i=0; i<m; i++ ) cin >> b[i].first >> b[i].second;
  for ( int i=0; i<n; i++ ) {
    int ans=0,mi=1e9;
    for ( int j=0; j<m; j++ ) {
      int x=abs(a[i].first-b[j].first)+abs(a[i].second-b[j].second);
      if ( mi>x ) {
        mi=x;
        ans=j;
      }
    }
    cout << ans+1 << '\n';
  }
  return 0;
}
