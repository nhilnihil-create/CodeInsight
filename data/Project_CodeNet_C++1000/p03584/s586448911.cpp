#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<cmath>
#include<climits>
#include<algorithm>
#include<bitset>
#include<set>
#include<stack>
#include<queue>
#include<iomanip>
#include<memory.h>
#include<complex>
#include<unordered_map>
using namespace std;  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int,int> tii;
#define rep(i,n) for(int i=0;i<(n);i++)  
#define pb push_back
#define mt make_tuple
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second  
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-8;
const double PI = M_PI;  
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define SHOWARRAY(ar,i,j) REP(a,i)REP(b,j)cerr<<ar[a][b]<<((b==j-1)?((a==i-1)?("\n\n"):("\n")):(" "))
#define DIV int(1e9+7)
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}
/* Coding Space*/ 
ll c[10][10];
typedef tuple<ll,ll> tll;
int main(){
  ll n,k; cin >> n >> k;
  vector<tll> mask;
  ll t = 1;
  mask.pb(tll{k,0});
  while(t <= k){
    if((t|k) == k)
      mask.pb(tll{(t^k)|(t-1),0});
    t *= 2;
  }
  ll ans = 0;
  rep(i,n){
    ll a,b; cin >> a >> b;
    rep(j,(int)mask.size()){
      ll maskk,value; tie(maskk,value) = mask[j];
      if((maskk | a) == maskk){
        value += b;
        mask[j] = tll{maskk,value};
        ans = max(ans,value);
      }
    }
  }
  cout <<ans << endl;
}