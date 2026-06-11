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
  int h, w, n;
  map<P, int> mp;
  cin>>h>>w>>n;
  int a, b;
  LL ans[10]={};
  ans[0]=(LL)(h-2)*(w-2);

  REP(i, n){
    cin>>a>>b;
    for(int y=-1; y<=1; ++y){
      for(int x=-1; x<=+1; ++x){
        if(a+y<2||a+y>h-1) continue;
        if(b+x<2||b+x>w-1) continue;
        ++mp[make_pair(a+y, b+x)];
      }
    }
  }
  for(auto i=mp.begin(); i!=mp.end(); ++i){
    ++ans[i->second];
  }

  REP(i, 9){
    ans[0]-=ans[i+1];
  }
  REP(i, 10){
    cout<<ans[i]<<endl;
  }

  return 0;
}
