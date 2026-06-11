#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){return b ? gcd(b, a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

int main(){
  int n;
  cin >> n;
  ll ans = 1;
  for(int i=0; i<n; ++i){
    ll x;
    cin >> x;
    ans = lcm(ans, x);
  }
  cout << ans << endl;
}