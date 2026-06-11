#include <bits/stdc++.h>
using namespace std;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
 
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
const int MAX = 1000000;
const int MOD = 1000000007;
 
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }
ll modPow(ll a, ll n, ll p) {
  if (n == 0) return 1;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}
ll choose(ll n, ll r, ll mod){
    ll mul = 1, div = 1;
    for(ll i = 0; i < r; i++){
        mul *= n - i;
        div *= i + 1;
        mul %= mod;
        div %= mod;
    }   
    return mul * modPow(div, mod - 2, mod) % mod;
}
 
int main(){
  int n, m;
  cin >> n >> m;
  vector<int>tree(100100);
  rep(i, 0, m){
    int a, b;
    cin >> a >> b;
    tree[a]++;
    tree[b]++;
  }
  rep(i, 1, n+1){
    if(tree[i]%2==1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}