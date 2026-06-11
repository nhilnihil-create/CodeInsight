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
  string s;
  cin >> n >> s;
  
  ll ans = 0;
  ll x = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == 'I')
      x++;
    else
      x--;

    ans = max(ans, x);
  }

  cout << ans << endl;

  return 0;
}
