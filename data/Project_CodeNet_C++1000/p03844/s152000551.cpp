#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll a;
  cin >> a;
  
  char c; cin >> c;
  ll b;
  cin >> b;
  
  if (c == '+')
    cout << a + b << endl;
  else
    cout << a - b << endl;

  return 0;
}
