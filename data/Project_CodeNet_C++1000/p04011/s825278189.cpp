#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n, k;
  cin >> n >> k;
  ll x, y;
  cin >> x >> y;
  
  if (n < k)
    cout << n * x << endl;
  else
    cout << k * x + (n - k) * y << endl;
  

  return 0;
}
