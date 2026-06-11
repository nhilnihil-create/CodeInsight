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
typedef tuple<int,int,int> tiii;
ll road[301][301];
int main(){
  int n; cin >> n;
  vector<tiii> v;
  rep(i,n)rep(j,n){
    cin >> road[i][j];
    v.pb(tiii{road[i][j],i,j});
  }
  sort(ALL(v));
  
  ll ans = 0;
  for(auto iii : v){
    int cost,from,to;
    tie(cost,from,to) = iii;
    bool flag = 0;
    rep(i,n){
      if(road[from][i] + road[i][to] < cost){cout << -1 << endl; return 0;}
      if(i != from && i != to && road[from][i] + road[i][to] == cost)
        flag = 1;
      else if(!flag && i == n -1)
        ans += cost;
    }
  }
  cout << ans/2 << endl;
}