#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define FOR(NAME, START, NUM) for (ll NAME = START; NAME < (NUM); NAME++)
#define REP(NAME, NUM) for (ll NAME = 0; NAME < (NUM); NAME++)
#define BREP(NAME, NUM) for (ll NAME = (NUM)-1; NAME >= 0; NAME--)
#define ALL(NAME) (NAME).begin(), (NAME).end()
const ll INF =1000000000000000;

int main(){
  ll n,x,a,b,c;cin >> n >> x;
  ll ans = n;
  a = max(x,n-x);
  b = min(x,n-x);//a >= b
  
  while(b != 0){
    ans += 2*(b*(a/b));
    c = a;
    a = b;
    b = c%b;
    //cout << ans << endl;
  }
  
  ans -= a;
  
  cout << ans << endl;
}