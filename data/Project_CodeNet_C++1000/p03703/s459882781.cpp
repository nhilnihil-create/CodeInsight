//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const int MOD = 1000000007;
//const int MOD = 998244353;
template<class T> inline int add(T& a, T b, T M = MOD){a=(a+M)%M;b=(b+M)%M;a=(a+b)%M;return a;};
template<class T> inline int mul(T& a, T b, T M = MOD){if(a>=M)a%=M;if(b>=M)b%=M;a*=b;if(a>=M)a%=M;return a;};
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
const string abc="abcdefghijklmnopqrstuvwxyz";
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

////////////////////////////////////////////////////////////////////
///////////////////////___modpow___////////////////////
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
////////////////////////////////////////////////////////////////////

int n, k, a[210000];
int bit[210000];
int bsum(int i){
  int s = 0;
  while(i > 0){
    s += bit[i];
    i -= (i & -i);
  }
  return s;
}
void badd(int i, int x){
  while(i <= n){
    bit[i] += x;
    i += (i & -i);
  }
}

signed main(){
  cin>>n>>k;rep(i,n)cin>>a[i+1],a[i+1]-=k,a[i+1] += a[i];
  vector<int> b(n+1);
  rep(i,n+1)b[i] = a[i];
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int ans = 0;
  n++;
  rep(i,n){
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;    
  }
  rep(i,n){
    ans += bsum(a[i]);
    badd(a[i], 1);
  }
  cout << ans << endl;
}
