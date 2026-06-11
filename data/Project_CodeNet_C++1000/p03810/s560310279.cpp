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

int n;
int a[125252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  int turn = 0;
  while(true){
    int c1 = 0;
    int even = 0, odd = 0, oddid = 0;
    REP(i,n){
      if(a[i]==1)c1++;
      if(a[i]%2==0)even++;
      else{
        odd++;
        oddid = i;
      }
    }
    if(c1==n)break;
    if(even%2==1){
      turn ^= 1;
      break;
    }
    if(odd>=2 || c1>=1)break;
    a[oddid]--;
    int gd = 0;
    REP(i,n)gd=__gcd(gd,a[i]);
    REP(i,n)a[i]/=gd;
    turn ^= 1;
  }
  puts(turn==1?"First":"Second");
  return 0;
}
