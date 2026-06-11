#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  int n;
  cin >> n;
  vector<vector<int>> a(1001,vector<int>(1001,0)); //素因数分解
  int i,j,tmp; 
  a[1][1]=1;
  for(i=2;i<=n;i++) {
    tmp=i;
    for(j=2;j<=i;j++) {
      if(tmp%j==0) {
        tmp/=j;
        a[i][j]++;
        rep(k,i+1) {a[i][k] += a[tmp][k];}
        break;
      }
    }
  }
  vector<int> sum(n+1,0);
  rep(i,n+1) {
    rep(j,n+1) {
      sum[i] += a[j][i];
    }
  }
  //rep(i,n+1) cout << sum[i] << endl;
  ll ans=1;
  rep2(i,2,n+1) {
    ans *= (sum[i]+1);
    ans%= MOD;
  }
  cout << ans << endl;
}