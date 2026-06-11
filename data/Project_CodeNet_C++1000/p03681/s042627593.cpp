#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  ll n, m;
  cin >> n >> m;
  if(abs(n-m)>1){
    cout << 0 << endl;
    return 0;
  }
  ll sum = 1;
  for(int i=1; i<=n; i++){
    sum *= i;
    sum %= mod;
  }
  for(int i=1; i<=m; i++){
    sum *= i;
    sum %= mod;
  }
  if(n==m){
    sum *= 2;
    sum %= mod;
  }
  cout << sum << endl;
  return 0;
}
