#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

//2つの正整数の最大公約数を求める
ll gcd(ll a, ll b) {
    const ll LARGE = max(a,b);
    const ll SMALL = min(a,b);
    ll x = LARGE;
    ll y = SMALL;
    ll r = x % y;

    while(r!=0){
        x = y;
        y = r;
        r = x % y;
    }

    return y;
}

//2つの正整数の最小公倍数を求める
ll lcm(ll a,ll b){
  ll y = gcd(a,b);
  return a * (b / y);
}

int main(){
  int n;
  cin >> n;

  vector<ll> t(n);
  rep(i,n) cin >> t[i];

  ll ans = 1;
  rep(i,n) ans = lcm(t[i],ans);

  cout << ans << endl;
  
  return 0;
}