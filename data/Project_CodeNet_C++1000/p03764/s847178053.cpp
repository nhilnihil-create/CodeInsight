#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define FOR(i, j, limit) for(int i=j; i< limit; ++i)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ECHO(x) cout<<x<<endl;
#define MEMSET(a, n, x) REP(i, n) a[i]=x;
#define ARRIN(a, n) REP(i, n) cin>>a[i];
#define LL long long
int INF = 2147483647;
LL LINF = 9223372036854775807;
LL MOD = 1000000007;
typedef pair<int, int>P;
typedef pair<LL, LL>PL;
typedef vector<int> vi;
typedef vector<LL> vl;


int main(){
  int n,m;
  cin>>n>>m;

  LL x[n], y[m];
  ARRIN(x, n);
  ARRIN(y, m);

  LL xsum=0, ysum=0, w;
  for(LL i=0; i<n-1; ++i){
    w = (x[i+1]-x[i])*(i+1)%MOD;
    w = w*(n-i-1)%MOD;
    xsum =(xsum+w)%MOD;
  }
  for(LL i=0; i<m-1; ++i){
    w = (y[i+1]-y[i])*(i+1)%MOD;
    w = w*(m-i-1)%MOD;
    ysum =(ysum+w)%MOD;
  }

  LL ans = xsum*ysum;
  ans%=MOD;
  ECHO(ans);

  return 0;
}
