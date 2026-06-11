#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  ll x = 0, y = 0;
  for (ll i = 0; i < n; i++){
    ll t, a;
    cin >> t >> a;
    
    if (i == 0){
      x = t;
      y = a;
    }
    else {
      ll m = max((x + t - 1)/t, (y + a - 1)/a);
      x = m*t;
      y = m*a;
    }
  }
  cout << x + y << endl;

  return 0;
}
