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
  
  if (a*b > c*d)
    cout << a*b << endl;
  else
    cout << c*d << endl;

  return 0;
}
