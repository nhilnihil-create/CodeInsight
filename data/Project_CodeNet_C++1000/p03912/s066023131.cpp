#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int n,m;
int x[125252];

// key = %m
struct da{
  int sum;
  int bulk;
  map<int,int> sames;
};
da data[125252];

int main(){
  scanf("%d%d",&n,&m);
  REP(i,n)scanf("%d",x+i);
  REP(i,n){
    int v = x[i];
    int key = v%m;
    data[key].sum += 1;
    data[key].sames[v]++;
  }
  REP(i,m){
    map<int,int>::iterator iter = data[i].sames.begin();
    while(iter != data[i].sames.end()){
      int key = iter->first;
      if(iter->second % 2 == 1){
        data[i].sames[key]--;
        data[i].bulk++;
      }
      iter++;
    }
  }
  int ans = 0;
  REP(i,m/2+1){
    if(i == m-i || i == 0){
      // same
      ans += data[i].sum/2;
    }else{
      // different
      int p = i;
      int q = m-i;
      int add = min(data[p].sum, data[q].sum);
      ans += add;
      {
        int y = p;
        int rest = add;
        rest -= min(rest,data[y].bulk);
        for(auto P:data[y].sames){
          int num = P.second;
          int mn = min(rest,num);
          num -= mn;
          rest -= mn;
          ans += num/2;
        }
      }
      {
        int y = q;
        int rest = add;
        rest -= min(rest,data[y].bulk);
        for(auto P:data[y].sames){
          int num = P.second;
          int mn = min(rest,num);
          num -= mn;
          rest -= mn;
          ans += num/2;
        }
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
