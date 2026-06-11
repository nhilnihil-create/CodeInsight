#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

//DMDMDMDMD; D = 5, M = 4
//5! * 4!
int main(){
  ll n,m;
  cin >> n >> m;
  if(abs(n-m)>1) {
    cout << 0 << endl;
    return 0;
  }

  const int mod = 1000000007;

  ll ans = 1;
  if (n == m) ans *= 2;
  while(n>0){
    n %= mod;
    ans *= n;
    ans %= mod;
    n--;
  }

  while(m>0){
    m %= mod;
    ans *= m;
    ans %= mod;
    m--;
  }

  ans %= mod;
  cout << ans << endl;
  
}
