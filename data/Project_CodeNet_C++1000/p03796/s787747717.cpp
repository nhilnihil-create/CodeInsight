#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  ll n; cin >> n;
  ll ans = 1;

  ll div = 1000000007;
  for(ll i = 1;i<=n;i++){
    ans *= i;
    ans %= div;
  }

  cout << ans << endl;
  
  return 0;
}
