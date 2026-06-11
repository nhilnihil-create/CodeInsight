#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
signed main(){
  int n,m;
  cin >> n >> m;
  
  if( max(n,m) - min(n,m) > 1 ){
    cout << 0 << endl;
    return 0;
  }
  
  int N = 1;
  for(int i=1;i<=n;i++){
    N *= i;
    N %= mod;
  }
  
  int M = 1;
  for(int i=1;i<=m;i++){
    M *= i;
    M %= mod;
  }
  
  int ans = N * M;
  if( n == m ) ans *= 2;
  ans %= mod;
  
  cout << ans << endl;

  return 0;
}