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
int main(){
  ll n,m; cin >> n >> m;
  ll ans = 0;
  vector<ll> x(n+1),y(m+1);
  rep(i,n) cin >> x[i+1];
  rep(i,m) cin >> y[i+1];
  ll xx=0,yy=0;
  for(int i = 1; i <= n; i++){
    xx += (i-1)*x[i] - (n-i)*x[i];
    xx %= DIV;
  }
  for(int i = 1; i <= m; i++){
    yy += (i-1)*y[i] - (m-i)*y[i];
    yy %= DIV;
  }
  cout << (xx*yy)%DIV << endl;
}