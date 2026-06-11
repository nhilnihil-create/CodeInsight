#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

int main(){
  int n,m;
  cin >> n >> m;
  if(abs(n-m) > 1){
    cout << 0 << endl;
    return 0;
  }
  else{
    ll n1 = 1, m1 = 1, ans;
    for(int i = 1; i <= n; i++){
      n1 = (n1*i) % MOD;
    }
    for(int i = 1; i <= m; i++){
      m1 = (m1*i) % MOD;
    }
    if (n == m) {
        ans = (n1 * m1 * 2) % MOD;
    } else {
        ans = (n1 * m1) % MOD;
    }
 
    cout << ans << endl;
    return 0;
  }
}