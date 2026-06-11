#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

ll gcd(ll x,ll y){
  if(x>y)swap(x,y);
  if(y%x==0)return x;
  return gcd(y-x*(y/x),x);
}

int main(){
  ll n,k;cin >> n >> k;
  vl a(n);
  ll M=0;
  ll g;
  rep(i,n){
    cin >> a[i];
    if(M<a[i])M=a[i];
    if(i==0)g=a[0];
    else g=gcd(g,a[i]);
  }
  
  if(k>M){
    cout << "IMPOSSIBLE" << endl;
  }else{
    if(k%g==0)cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
}