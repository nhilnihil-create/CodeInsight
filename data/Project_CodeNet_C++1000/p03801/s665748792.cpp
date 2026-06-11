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

int n,a[110000];
vector<P> b;
map<int,int> cnt, sum;
int ans[110000];P p[110000];
signed main(){
  cin>>n;rep(i,n)cin>>a[i];
  b.push_back(P(0,-1)); b.push_back(P(0,-1));int last = 0;
  rep(i,n)if(last < a[i]){
    b.push_back(P(a[i], i));
    last = a[i];
  }
  sort(a,a+n);
  int s = 0;
  rep(i,n){
    if(i > 0 && a[i] != a[i-1] || i == 0)cnt[a[i]] = i;
    if(i > 0 && a[i] != a[i-1] || i == 0)sum[a[i]] = s;
    s += a[i];
  }
  repd(i,2,b.size()){
    int num = b[i].first, ind = b[i].second, pnum = b[i-1].first;
    ans[ind] = (n-cnt[num])*(num-pnum);
    //cout << i << " " << ans[ind] << endl;
    ans[ind] += (sum[num] - sum[pnum])-pnum*(cnt[num]-cnt[pnum]);
  }
  rep(i,n){
    cout << ans[i] << endl;
  }
}

