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
  int n, a, b;
  cin>>n>>a>>b;
  LL h[n];
  ARRIN(h, n);
  int x=a-b;
  LL ng=0, ok=0;
  REP(i, n){
    ok += (h[i]+b-1)/b;
  }
  ++ok;
  LL c, w, t;
  while(ok-ng>1){
    c=(ok+ng)/2;
    w=0;
    REP(i, n){
      t=(h[i]-c*b);
      if(t<=0) continue;
      w += t/x;
      if(t%x) ++w;
    }
    //cout<<ng<<" "<<ok<<" "<<c<<" "<<w<<endl;
    if(w<=c) ok=c;
    else ng=c;
  }

  cout<<ok<<endl;

  return 0;
}
