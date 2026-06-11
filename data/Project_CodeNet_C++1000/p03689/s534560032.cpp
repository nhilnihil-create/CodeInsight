#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(int x = (l);x<=(u);x++)
#define RREP(x,l,u) for(int x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 510;
const int mod = 1e9+7;
const int MAX = 1000000010;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int H,W,h,w;

int Ans[maxn][maxn];

void Work(){
	REP(i,1,H)REP(j,1,W)Ans[i][j]=1000;
	int x=-(h*w-1)*1000-1;
	for(int i=1;i+h-1<=H;i+=h)
		for(int j=1;j+w-1<=W;j+=w){
			Ans[i+h-1][j+w-1]=x;
		}
	int ans=0;
	REP(i,1,H)REP(j,1,W)ans+=Ans[i][j];
	
	if(ans>0){
		puts("Yes");
		REP(i,1,H){
			REP(j,1,W)printf("%d ",Ans[i][j]);puts("");
		}
	}
	else puts("No");
}

void Init(){
	read(H,W,h,w);
}

int main(){
	Init();
	Work();
	return 0;
}
