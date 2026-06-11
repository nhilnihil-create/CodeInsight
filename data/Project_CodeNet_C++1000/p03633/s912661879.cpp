#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

ll gcd(ll a, ll b){//最大公約数
  if (b == 0){
    return a;
  }
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){//最小公倍数
  ll c = gcd(a, b);
  return a / c * b;
}

int main(){
  int n;
  cin >> n;
  ll ans = 1LL;
  rep(i,n){
    ll t;
    cin >> t;
    ans = lcm(ans, t);
  }
  cout << ans << endl;
}
