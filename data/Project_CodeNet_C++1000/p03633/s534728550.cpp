#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 100100100;

ll gcd(ll x, ll y){
  if(x < y) swap(x,y);
  if(y == 0) return x;
  return gcd(y,x%y);
}
ll lcm(ll a, ll b){
  ll g = gcd(a,b);
  return a/g*b;
}




int main(){
  int n;
  cin >> n;
  vector<ll> t(n);
  rep(i,n) cin >> t[i];

  ll ans = t[0];
  rep(i,n){
    ans = lcm(ans,t[i]);
  }
  cout << ans << endl;
}
