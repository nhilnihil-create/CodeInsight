#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define MOD 1000000007

int main(){
  int n,m;
  cin>>n>>m;
  ll x[n],y[m];
  for(int i=0;i<n;i++) cin>>x[i];
  for(int i=0;i<m;i++) cin>>y[i];
  ll X=0, Y=0;
  for(int i=1;i<=n;i++){
    (X+=(i-1)*x[i-1]-(n-i)*x[i-1])%=MOD;
  }
  for(int i=1;i<=m;i++){
    (Y+=(i-1)*y[i-1]-(m-i)*y[i-1])%=MOD;
  }
  cout<<(X*Y)%MOD<<endl;
  return 0;
}
