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
using namespace std;  
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int,int> tii;
#define rep(i,n) for(ll i=0;i<(n);i++)  
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
typedef tuple<int,int> tii;
int main(){
  int h,w,n; cin >> h >> w >> n;
  map<tii,int> m;
  rep(i,n){
    int a,b; cin >> a >> b;
    for(int x = -2; x <= 0; x++)
    for(int y = -2; y <= 0; y++){
      int aa = a+x,bb = b+y;
      if(aa >= 1 && aa <= h-2 && bb >= 1 && bb <= w-2)
        m[tii{aa,bb}]++;
    }
  }
  vector<ll> ans(10);
  ans[0] = ll(h-2)*(w-2) - m.size();
  for(auto i:m){
    ans[i.SEC]++;
  }
  rep(i,10)
    cout << ans[i] << endl;
}