#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,a,ans=0;
  cin >> n >> a;
  vector<long> x(n);
  vector<vector<long>> aaa(n,vector<long>(2500));
  for(long i=0;i<n;i++) cin >> x[i];
  for(long i=0;i<n;i++) {
    for(long j=i;j>0;j--) {
      for(long k=0;k<i*50;k++) {
        aaa[j][x[i]+k]+=aaa[j-1][k];
      }
    }
    aaa[0][x[i]-1]++;
  }
  for(long i=0;i<n;i++) ans+=aaa[i][a*(i+1)-1];
  cout << ans << endl;
}