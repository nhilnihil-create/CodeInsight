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

int n,t[110000],a[110000],b[110000],c[110000];
signed main(){
  cin>>n;rep(i,n)cin>>t[i];rep(i,n)cin>>a[i];
  b[0] = 1;c[0] = t[0];
  repd(i,1,n){
    if(t[i-1] > t[i]){
      cout << 0 << endl;return 0;
    }else if(t[i-1] < t[i]){
      b[i] = 1;
      c[i] = t[i];
    }else{
      b[i] = t[i];
      c[i] = 0;
    }
  }
  b[n-1] = 1;
  if(c[n-1] > 0 && c[n-1] != a[n-1] || (b[n-1] != 1 && a[n-1] > b[n-1])){
    cout << 0 << endl;return 0;
  }
  for(int i = n-2;i >= 0;i--){
    if(a[i+1] > a[i]){
      cout << 0<< endl;return 0;
    }else if(a[i+1] < a[i]){
      b[i] = 1;
      if((c[i] > 0 && c[i] != a[i]) || (b[i] != 1 && a[i] > b[i])){
        cout << 0 << endl;return 0;
      }
    }else{
      if(c[i] > a[i]){
        cout << 0 << endl;return 0;
      }
      chmin(b[i], a[i]);
    }
  }
  int ans = 1;
  rep(i,n)ans = (ans*b[i])%MOD;
  cout << ans << endl;
}


