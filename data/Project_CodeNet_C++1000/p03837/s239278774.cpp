#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,m,ans=0;
  cin >> n >> m;
  vector<long> a(m),b(m),c(m);
  vector<vector<long>> sp(n,vector<long>(n,999999999));
  for(long i=0;i<m;i++) {
    cin >> a[i] >> b[i] >> c[i];
    sp[a[i]-1][b[i]-1]=c[i];
    sp[b[i]-1][a[i]-1]=c[i];
  }
  for(long i=0;i<n;i++) sp[i][i]=0;
  for(long k=0;k<n;k++) {
    for(long i=0;i<n;i++) {
      for(long j=0;j<n;j++) {
        sp[i][j]=min(sp[i][j],sp[i][k]+sp[k][j]);
      }
    }
  }
  for(long i=0;i<m;i++) if(sp[a[i]-1][b[i]-1]!=c[i]) ans++;
  cout << ans << endl;
}