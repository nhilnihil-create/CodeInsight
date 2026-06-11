#include <cstdio>
#include <vector>
#include <utility>
using std::printf;
using std::scanf;
using std::pair;
using std::vector;
 
typedef pair<int,int> pii;
 
typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
 
// fenwick tree
const int N = 125252;
int dat[N+1];
void add(int x,int v){
  while(x<=N){
    dat[x]+=v;
    x+=x&-x;
  }
}
int sum(int x){
  int ret = 0;
  while(x){
    ret+=dat[x];
    x-=x&-x;
  }
  return ret;
}
 
int n,m;
vector<pii> lens[125252];
 
int main(){
  scanf("%d%d",&n,&m);
  REP(i,n){
    int l,r;
    scanf("%d%d",&l,&r);
    r++;
    lens[r-l].push_back(pii(l,r));
  }
  printf("%d\n",n);
  int rest = n;
  FOR(d,2,m+1){
    // len==d-1
    for(pii P : lens[d-1]){
      add(P.first,1);
      add(P.second,-1);
      rest--;
    }
    int ans = rest;
    int it = d;
    while(it<=m){
      ans += sum(it);
      it += d;
    }
    printf("%d\n",ans);
  }
  return 0;
}