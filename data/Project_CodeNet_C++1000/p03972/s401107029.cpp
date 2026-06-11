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
map<char,int> m;
int main(){
  int w,h; cin >> w >> h;
  vector<tii> v;
  rep(i,w){
    int p; cin >> p;
    v.pb(tii{p,0});
  }
  rep(i,h){
    int q; cin >> q;
    v.pb(tii{q,1});
  }
  ll ans = 0;
  sort(ALL(v));
  rep(i,(int)v.size()){
    ll c,type; tie(c,type) = v[i];
    if(type == 0){
      ans += 1LL*(h+1)*c;
      w--;
    }else{
      ans += 1LL*(w+1)*c;
      h--;
    }
  }
  cout << ans << endl;
}