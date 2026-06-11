#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

ll gcd(ll a, ll b){
  if (a < b)
    return gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> t(n);
  for (int i = 0; i < n; i++){
    cin >> t[i];
  }
  if (n == 1){
    cout << t[0] << endl;
  }
  else {
    ll l = lcm(t[0], t[1]);
    for (int i = 2; i < n; i++){
      l = lcm(l, t[i]);
    }
    cout << l << endl;
  }


  return 0;
}
