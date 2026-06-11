#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  ll n,m;
  cin >> n >> m;
  if(abs(n-m)>1){
    print(0);
  }
  else{
    ll a = min(n, m);
    ll b = max(n, m);
    ll num1 = 1;
    for (ll i = 1; i <= a;i++){
      num1 *= i;
      num1 %= MOD;
    }
    ll num2 = num1;
    if (b - a == 1){
      num2 *= b;
      num2 %= MOD;
    }
    ll ans = num1 * num2;
    if(n==m){
      ans *= 2;
    }
    ans %= MOD;
    print(ans);
  }
}
