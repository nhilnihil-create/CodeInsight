#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using vpii = vector<pair<int, int>>;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep1(i, n) for (int i = 1; i < (int)n; i++)
ll inf = 1e9+7;

ll gcd(ll a, ll b){
  return (b != 0) ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b){
  return (a/gcd(a,b))*b;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  ll x;
  cin >> x;
  ll ans = 0;
  ans += (x/11)*2;
  if(x%11 <= 6 && x%11 >= 1) ans += 1;
  else if(x%11 >= 7) ans += 2;
  cout << ans << "\n";
  return 0;
}   