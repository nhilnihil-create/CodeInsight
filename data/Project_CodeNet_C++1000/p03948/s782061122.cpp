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
  int n, t;
  cin>>n>>t;
  int a[n];
  ARRIN(a, n);
  int mi=a[0], r=0, c=0;
  FOR(i, 1, n){
    if(mi>a[i]) mi=a[i];
    else if(a[i]-mi==r) ++c;
    else if(a[i]-mi>r){
      r=a[i]-mi;
      c=1;
    }
  }
  ECHO(c);
  return 0;
}
