#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 
#define int long long
#define double long double

////////////////////////////////////////////////////////////////////
ll modpow(ll a,  ll n, const ll &MOD = MOD){
  ll ret = n == 0 ? 1 : modpow(a, n/2, MOD);
  (ret *= ret) %= MOD;
  if(n%2)((ret *= a) %= MOD);
  return ret;
}
///////////////////////___modinv___////////////////////
ll modinv(ll d, const ll &MOD = MOD){
  return modpow(d, MOD-2, MOD);
}
///////////////////////___prime_factor___////////////////////
map<int, int> prime_factor(int n){
  map<int, int> ret;
  for(int i = 2;i*i <= n;i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1){
    ret[n] = 1;
  }
  return ret;
}

////////////////////////////////////////////////////////////////////

int n,x,a[2100],vec[2100];
signed main(){
  cin>>n>>x;
  rep(i,n)cin>>a[n-i-1];
  rep(i,n){
    int x = INF;
    rep(j,n+1){
      int ind = (i-j+n)%n;
      chmin(x, a[ind]);
      vec[j] += x;
    }
  }
  int ans = INF;
  rep(i,n+1){
    chmin(ans, vec[i]+x*i);
  }
  cout << ans << endl;
}


