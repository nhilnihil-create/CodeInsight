#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ma,mb,ans=999999999;
  cin >> n >> ma >> mb;
  vector<long> a(n),b(n),c(n);
  vector<vector<long>> k(401,vector<long>(401,999999999));
  for(long i=0;i<n;i++) cin >> a[i] >> b[i] >> c[i];
  
  k[0][0]=0;
  for(long i=0;i<n;i++) {
    for(long j1=400-a[i];j1>=0;j1--) {
      for(long j2=400-b[i];j2>=0;j2--) {
        k[j1+a[i]][j2+b[i]]=min(k[j1+a[i]][j2+b[i]],k[j1][j2]+c[i]);
      }
    }
  }
  for(long i=1;max(ma,mb)*i<=400;i++) ans=min(ans,k[ma*i][mb*i]);
  if(ans==999999999) cout << -1 << endl;
  else cout << ans << endl;
}