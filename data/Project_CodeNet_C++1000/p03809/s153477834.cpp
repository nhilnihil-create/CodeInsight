#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = (l);x<=(u);x++)
#define RREP(x,l,u) for(ll x = (l);x>=(u);x--)
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

const int maxn = 100010;
const int mod = 1e9+7;
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

int n,rt;

int A[maxn];

vector<int> G[maxn];

ll dfs(int u,int f){
	if(sz(G[u])==1)return A[u];
	vector<ll> tmp;
	for(auto v:G[u])if(v!=f){
		ll x=dfs(v,u);
		tmp.PB(x);
	}
	ll sm=0;
	for(auto i:tmp)sm+=i;
	if(sm<A[u]||sm>A[u]*2){
		puts("NO");
		exit(0);
	}
	ll x=sm-A[u];
	ll mx=0;
	for(auto i:tmp)mx=max(mx,i);
	if(x>sm-mx){
		puts("NO");
		exit(0);
	}
	return sm-x*2;
}

void Work(){
	if(n==2){
		puts(A[1]==A[2]?"YES":"NO");
		return;
	}
	REP(i,1,n)if(sz(G[i])>1)rt=i;
	if(!dfs(rt,0))puts("YES");else puts("NO");
}

void Init(){ 
	read(n);
	REP(i,1,n)read(A[i]);
	REP(i,2,n){
		int u,v;
		read(u,v);
		G[u].PB(v);G[v].PB(u);
	}
}

int main(){
	Init();
	Work();
	return 0;
}
