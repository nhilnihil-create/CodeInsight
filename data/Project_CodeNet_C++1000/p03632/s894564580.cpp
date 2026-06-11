#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  
  int ans = 0;
  b--; d--;
  for (int i = 0; i < 101; i++){
    if (a <= i && i <= b && c <= i && i <= d)
      ans++;
  }

  cout << ans << endl;

  return 0;
}
