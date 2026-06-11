#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  long sumx=0;
  long sumy=0;
  const int mod=1000000007;
  for(int i=0;i<n;i++){
    long x;
    cin >> x;
    sumx=(sumx+x*(-n+2*i+1))%mod;
  }
  for(int i=0;i<m;i++){
    long y;
    cin >> y;
    sumy=(sumy+y*(-m+2*i+1))%mod;
  }
  long ans=sumx*sumy%mod;
  cout << ans;
}


