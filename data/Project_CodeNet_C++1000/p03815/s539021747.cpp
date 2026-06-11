#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll x;
  cin >> x;
  
  if (x % 11 == 0){
    cout << 2*(x / 11) << endl;
  }
  else if (x % 11 < 7){
    cout << 2*(x / 11) + 1 << endl;
  }
  else {
    cout << 2 * (x / 11 + 1) << endl;
  }

  return 0;
}
