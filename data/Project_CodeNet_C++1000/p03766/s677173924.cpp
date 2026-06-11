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

const int maxn = 1000010;
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

int n;

int f[maxn],sm[maxn];
	
void Work(){
	int ans=0;
	REP(i,0,n-2){
		ans=(ans+1ll*f[i]*(n-1)%mod*(n-2))%mod;
	}
	REP(i,0,n-1){
		ans=(ans+1ll*f[i]*(n-1))%mod;
	}
	REP(i,0,n-2){
		ans=(ans+1ll*f[i]*(n-1))%mod;
	}
	ans=(ans+1)%mod;
	iout(ans);
}

void Init(){
	read(n);
	f[0]=f[1]=1;sm[1]=2;
	REP(i,2,n){
		f[i]=sm[i-1];
		f[i]=(f[i]-f[i-2]+mod)%mod;
		sm[i]=(sm[i-1]+f[i])%mod;
	}
}

int main(){
	Init();
	Work();
	return 0;
}
